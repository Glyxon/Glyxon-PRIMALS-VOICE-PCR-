# ⚡ CIRCUIT GUIDE: The Photonic Power of PJ
> **Precision energy delivery for molecular sovereignty.**

The GLYXON PRIMALS electronic system is designed for high-current thermal ramping and local voice processing using the **ESP32-S3**. This guide outlines the Photonic Matrix and the Cordless Bayonet Lid system.

## 📡 Control Core: ESP32-S3 (Matter-Ready)
We utilize the ESP32-S3 for its native AI acceleration (Vector Instructions), which allows **PJ (Personal Justice)** to process basic voice commands locally and manage the Matter-over-Wi-Fi stack simultaneously.

## 🔆 The Photonic Matrix (36 IR LED Array)
To achieve uniform DNA denaturation without Peltier blocks, we use a circular array of 36 High-Power Infrared LEDs.

* **Topology:** 6 parallel strings of 6 LEDs in series.
* **Driving:** PWM-controlled via logic-level MOSFETs (e.g., IRLB8721).
* **Thermal Feedback:** 4x High-precision thermistors (10k NTC) embedded in the concrete-well interface for real-time PID tuning.
* **Wavelength:** 850nm - 940nm for optimal penetration of micro-centrifuge tubes.

## 🧲 The Cordless Bayonet Lid (Galvanic Contact System)
The PRIMALS design eliminates "umbilical" wires to the lid. Instead, we use a 1/4 turn locking mechanism inspired by camera lens mounts.

* **Contact Plates:** 4x Concentric brass rings integrated into the concrete chassis.
* **Spring Pins:** Gold-plated pogo pins located in the lid.
* **Lid Function:** Powers the top-heating element (to prevent condensation) and monitors the "Lid Closed" safety interrupt for **PJ**.
* **Safety Logic:** The ESP32-S3 will not initialize the IR Matrix unless the galvanic circuit is closed and verified.

## 🔋 Power Requirements
* **Input:** 12V DC / 10A (Industrial Grade Power Supply).
* **Regulation:** * 12V (Direct to IR Matrix and Lid Heater).
    * 3.3V (Buck converter for ESP32-S3 and Logic).

## 🛡️ Safety Systems (The PJ Guardian)
**PJ** monitors the following hardware interrupts:
1.  **Over-Temperature Cutoff:** Independent thermal fuse set at 110°C.
2.  **Galvanic Disconnect:** Instant PWM shutdown if the lid is rotated during a cycle.
3.  **Visual Feedback:** A neopixel ring at the base indicates cycle status (Blue: Idle, Red: Denaturation, Green: Complete).

---
### "PJ, check the photonic array. Ready for amplification."
