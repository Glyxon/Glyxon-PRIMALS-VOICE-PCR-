# 🧠 FIRMWARE ROADMAP: The Brain of Personal Justice (PJ)
> **Controlling the light, managing the protocol, ensuring the justice.**

This document outlines the development path for the GLYXON PRIMALS control system, powered by the **ESP32-S3** and integrated into the **Open Home / Matter** ecosystem.

## 📡 Core Architecture
The PRIMALS firmware is designed for local-first execution. **PJ** operates through the Home Assistant voice architecture to provide hands-free biological management.

### Phase 1: Photonic Control (Current Focus)
* **36 IR LED Matrix:** PWM-driven thermal control for precision DNA amplification.
* **Thermal Gradients:** Implementing PID loops for fast ramping and stable denaturation/annealing plateaus.
* **Safety Interrupts:** Hardware-level thermal cutoff to protect the concrete chassis and samples.

### Phase 2: Matter & Connectivity
* **Matter Clusters:** Mapping the PCR as a specialized climate/thermal entity within the Matter protocol.
* **Local API:** Real-time telemetry of temperature curves and fluorescence data to Home Assistant dashboards.

### Phase 3: PJ Intelligence (Personal Justice Interface)
* **Conversational Checklists:** Voice-driven pre-flight checks (e.g., "PJ, confirm the lid is locked and reagents are loaded").
* **Error Detection:** PJ proactively monitors thermal drift and warns the user: *"Detection: Thermal ramp inconsistent. Check galvanic contacts."*
* **Task Automation:** Automated logging of run data and inventory management of general reagents.

## 🛠 Technical Stack
* **Framework:** ESP-IDF / Arduino Core.
* **Communication:** Matter over Wi-Fi (Thread-ready).
* **AI Interface:** Home Assistant Assist / Wyoming Protocol for local voice processing.

---
### "PJ, initialize the cycle. Let's make science personal."
