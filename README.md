# Smart Traffic Light Controller with Integrated Pedestrian Request System

An Arduino-based embedded software project demonstrating real-time traffic signal management and interactive pedestrian crosswalk control. Built on a **Finite State Machine (FSM)** architecture and leveraging non-blocking asynchronous timing (`millis()`), this system ensures maximum responsiveness, system reliability, and safety at intersections.

---

## 🔬 System Overview

Conventional traffic light controllers relying on blocking timing functions (such as `delay()`) often freeze execution, causing missed input triggers and delayed system responses. 

This project solves that limitation by implementing an asynchronous execution loop using `millis()`. The controller continuously monitors input signals—such as pedestrian button presses—while concurrently managing multi-phase state transitions for both vehicle and pedestrian signals.

---

## 🛠️ Key Technical Features

* **Finite State Machine Architecture:** Predictable, robust state management preventing conflicting traffic signals.
* **Non-Blocking Asynchronous Timing:** Utilizes `millis()` for continuous, background task execution and rapid switch reading.
* **Internal Pull-Up Resistors:** Configured via `INPUT_PULLUP` to eliminate floating pin states and simplify hardware layout.
* **Real-Time Telemetry:** Streams system status updates, button acknowledgments, and state logs over Serial UART (9600 Baud).
* **Safe Transition Protocols:** Incorporates amber warning phases and flashing pedestrian signals before restoring primary traffic flow.

---

## 📌 Hardware Specifications & Pin Mapping

| Component | Microcontroller Pin | Description / Function |
| :--- | :--- | :--- |
| **Car Green LED** | Digital Pin 2 | Vehicle Go Signal (220Ω Resistor) |
| **Car Yellow LED** | Digital Pin 3 | Vehicle Caution Signal (220Ω Resistor) |
| **Car Red LED** | Digital Pin 4 | Vehicle Stop Signal (220Ω Resistor) |
| **Pedestrian Green LED** | Digital Pin 5 | Pedestrian Walk Signal (220Ω Resistor) |
| **Pedestrian Red LED** | Digital Pin 6 | Pedestrian Wait Signal (220Ω Resistor) |
| **Pedestrian Push Button** | Digital Pin 7 | Active-LOW Crosswalk Request Input |
| **Ground Line** | GND | Common Return Ground Rail |

---

## 🚦 Operational State Machine

  +-----------------+
  |    CARS_GO      |  <--- (Vehicle Green / Ped Red)
  +--------+--------+
           |  (Button Press / Timer)
           v
  +-----------------+
  |    CARS_WARN    |  <--- (Vehicle Yellow / Ped Red)
  +--------+--------+
           |  (2s Duration)
           v
  +-----------------+
  |   PEDS_CROSS    |  <--- (Vehicle Red / Ped Green)
  +--------+--------+
           |  (5s Duration)
           v
  +-----------------+
  |    PEDS_WARN    |  <--- (Flashing Ped Green / Ped Red Transition)
  +--------+--------+
           |  (Flashing Complete)
           +---> Back to CARS_GO

---

## 🚀 Deployment Instructions

### Prerequisites
* Arduino IDE (v1.8.x or higher) / Wokwi Simulator
* USB Cable for Hardware Programming

### Steps
1. Clone or download the project files (`sketch.ino`, `diagram.json`).
2. Connect your **Arduino Uno** board via USB.
3. Open `sketch.ino` in the Arduino IDE.
4. Select the correct **Board** (`Arduino Uno`) and **COM Port** under `Tools`.
5. Click **Upload** and open the **Serial Monitor** set to `9600 baud` to view real-time log outputs.
