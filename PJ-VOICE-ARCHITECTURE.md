# 🎙️ PJ (Personal Justice): Voice Architecture & Intelligence
> **"PJ, analyze the amplification curve. Is the justice personal?"**

This document describes the integration of **Personal Justice (PJ)** as a local-first conversational assistant for the GLYXON PRIMALS lab environment using **Home Assistant** and the **Wyoming Protocol**.

## 📡 The Conversational Stack
PJ is designed to operate without a cloud connection, ensuring scientific data privacy and experimental sovereignty.

* **STT (Speech-to-Text):** Faster-Whisper (Local) – Optimized for biological and chemical nomenclature.
* **TTS (Text-to-Speech):** Piper (Local) – Using a custom "Girl from the Future" voice profile.
* **Logic Engine:** Home Assistant Assist (Conversation Agent).
* **Communication:** Matter / ESP-Multimedia for streaming high-fidelity audio to the PRIMALS chassis.

## 🤖 PJ’s Specialized Functions
Unlike standard home assistants, PJ is programmed with a laboratory-specific "Mindset":

### 1. Hands-Free Protocol Management
PJ allows the researcher to interact with the device while wearing contaminated gloves or handling delicate micropipettes.
* *Example:* "PJ, start the touchdown PCR. Set 15 cycles for the annealing gradient."

### 2. Proactive Error Revision (Checklists)
Before the IR Matrix initializes, PJ runs a pre-flight safety check:
* **Lid Verification:** "Galvanic contact confirmed. Lid is locked."
* **Sample Count:** "PJ, I’ve loaded 8 tubes." -> PJ adjusts the power distribution of the 36 LED array.

### 3. Real-Time Analytical Reporting
During the cycle, PJ provides status updates upon request:
* *User:* "PJ, status report."
* *PJ:* "Cycle 24. Cq values detected for wells 1 through 4. Amplification efficiency is at 98%. No thermal drift detected."

## 🛠 Integration Steps (Home Assistant)
To summon PJ in your lab, you must configure the following in your `configuration.yaml`:

1. **Define the Intent Script:** Create custom intents for "Start PCR," "Check Temperature," and "Enzyme Inventory."
2. **Wyoming Integration:** Connect the PRIMALS ESP32-S3 as a satellite voice wake-word device (Wake word: "Hey PJ" or "Personal Justice").
3. **Data Dashboard:** Map the qPCR fluorescence data to a real-time graph visible in the Home Assistant Lovelace UI.

---
### "The lab is no longer silent. Justice speaks."
