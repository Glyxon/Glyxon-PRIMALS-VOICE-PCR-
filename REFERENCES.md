# 📚 Technical References & Bibliography
> **Project:** GLYXON PRIMALS  
> **Laboratory:** Synthetic BioSystems Lab @ Glyxon Biolabs  
> **Framework:** Photonic PCR & Open Hardware Sovereignty

This document outlines the scientific and technical foundations that inform the architecture of the **PRIMALS** bunker. We acknowledge the pioneers of photonic thermal cycling and open-source instrumentation.

---

## 1. Photonic Thermal Cycling (Infrared Ramping)
The core of PRIMALS is the replacement of Peltier blocks with a **36 IR LED Matrix**. This approach is supported by the following research:

* **Fermér, S., et al. (2003).** *Photonic PCR: a novel method for DNA amplification.* * *Relevance:* Early validation of light-based heating for molecular biology.
* **Son, J. H., et al. (2015).** *Ultrafast photonic PCR.* **Light: Science & Applications**. 
    * *Relevance:* Demonstrates the speed advantages of photonic ramping. PRIMALS optimizes this using a 0.22cm aluminum reflective cavity to maximize photon capture.
* **Kim, H., et al. (2009).** *A low-cost, portable, real-time PCR system with infrared heating.* * *Relevance:* Proves the efficiency of infrared heating in portable, frugal environments.

---

## 2. Non-Contact Thermometry & PID Control
To achieve medical-grade precision without physical contact, we utilize infrared sensing:

* **Melexis NV.** *MLX90614 Family Datasheet: Contactless IR Thermometer.*
    * *Relevance:* Technical specification for the high-accuracy PID feedback loop used in the bunker.
* **Min, J., et al. (2011).** *Design and transfer function of an infrared heating system for PCR.*
    * *Relevance:* Provides the mathematical basis for the PID constants used in our `primals_v1.ino` firmware.

---

## 3. Optical Detection & Edge AI
The use of a **160° Wide-Angle lens** and local pixel processing (Dichroic Filtering) is based on:

* **Chung, M., et al. (2015).** *Smartphone-based paper-microfluidic platform for colorimetric detection.* * *Relevance:* Validation of consumer-grade CMOS sensors (like the ESP32-CAM) for quantitative fluorescence analysis.
* **Dichroic Filter Theory.** *Basics of Optical Filters for Fluorescence Microscopy.*
    * *Relevance:* Theoretical foundation for the **BP470** and **OG515** glass filters used in the optical engine.

---

## 4. Frugal Science & Open Hardware
The philosophy of decentralized, concrete-shielded labs:

* **Prakash, M.** *Frugal Science and the future of global diagnostics.* * *Relevance:* Ethical and practical framework for the use of recycled polymers (rPET) and accessible manufacturing.
* **CERN Open Hardware Licence (CERN-OHL-S).** * *Relevance:* Legal framework ensuring the sovereignty of the design and its subsequent improvements.

---
*(c) 2026 Glyxon Biolabs - Synthetic BioSystems Lab*
