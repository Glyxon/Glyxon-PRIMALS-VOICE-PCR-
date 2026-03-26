#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <PID_v1.h>

// Definición de Pines
const int IR_MATRIX_PIN = 18;  // Salida PWM para los 36 LEDs IR
const int COOLING_FAN_PIN = 19; // Salida para el ventilador de 40mm

// Variables de Control
double Setpoint, Input, Output;
double Kp=2, Ki=5, Kd=1; // Ajustar según la inercia térmica del búnker
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(115200);
  mlx.begin();
  
  pinMode(IR_MATRIX_PIN, OUTPUT);
  pinMode(COOLING_FAN_PIN, OUTPUT);

  Setpoint = 95.0; // Temperatura de desnaturalización inicial
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(0, 255); // Rango de PWM
}

void loop() {
  Input = mlx.readObjectTempC(); // Lectura IR sin contacto
  myPID.Compute();

  if (Output > 0) {
    analogWrite(IR_MATRIX_PIN, Output); // Calentamiento fotónico
    digitalWrite(COOLING_FAN_PIN, LOW);
  } else {
    analogWrite(IR_MATRIX_PIN, 0);
    digitalWrite(COOLING_FAN_PIN, HIGH); // Enfriamiento activo
  }
  
  // Enviar datos al puerto serial para Grafana/Home Assistant
  Serial.print("Temp:"); Serial.println(Input);
}
