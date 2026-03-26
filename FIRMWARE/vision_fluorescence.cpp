#include "esp_camera.h"
#include <ArduinoJson.h>

// Configuración de la lente Gran Angular (Fisheye 160°)
#define CAMERA_MODEL_AI_THINKER 
#include "camera_pins.h"

// Coordenadas de los tubos (Ajustar según la alineación del búnker)
// X, Y, Ancho, Alto
int tube_coords[8][4] = {
  {40, 50, 20, 20}, {80, 50, 20, 20}, {120, 50, 20, 20}, {160, 50, 20, 20},
  {40, 90, 20, 20}, {80, 90, 20, 20}, {120, 90, 20, 20}, {160, 90, 20, 20}
};

float readFluorescence(int tubeID, camera_fb_t * fb) {
  uint32_t total_green = 0;
  int x_start = tube_coords[tubeID][0];
  int y_start = tube_coords[tubeID][1];
  int w = tube_coords[tubeID][2];
  int h = tube_coords[tubeID][3];

  // Recorremos los pixeles del ROI (Region of Interest)
  for (int y = y_start; y < y_start + h; y++) {
    for (int x = x_start; x < x_start + w; x++) {
      // Obtenemos el pixel en formato RGB565
      uint16_t pixel = ((uint16_t*)(fb->buf))[y * fb->width + x];
      // Extraemos solo el canal VERDE (donde emite el ADN con el filtro OG515)
      uint8_t green = (pixel >> 5) & 0x3F; 
      total_green += green;
    }
  }
  return (float)total_green / (w * h); // Promedio de intensidad
}

void processOpticalData() {
  camera_fb_t * fb = esp_camera_fb_get();
  if (!fb) return;

  StaticJsonDocument<512> doc;
  JsonArray data = doc.createNestedArray("fluorescence_levels");

  for (int i = 0; i < 8; i++) {
    data.add(readFluorescence(i, fb));
  }

  // Liberar el buffer de la cámara
  esp_camera_fb_return(fb);

  // Enviar a PJ vía MQTT
  char buffer[512];
  serializeJson(doc, buffer);
  client.publish("glyxon/primals/optics", buffer);
}
