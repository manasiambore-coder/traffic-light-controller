# Smart Traffic Light Controller with Integrated Pedestrian Request System

An Arduino-based embedded software project demonstrating real-time traffic signal management and interactive pedestrian crosswalk control. Built on a **Finite State Machine (FSM)** architecture and leveraging non-blocking asynchronous timing (`millis()`), this system ensures maximum responsiveness, system reliability, and safety at intersections.

---

## 📌 Project Overview
This project uses an **Arduino UNO** alongside signal LEDs and a tactile push button to simulate and control a smart traffic intersection.

Under normal operation, the system automatically cycles through standard vehicle traffic signals. When a pedestrian presses the crosswalk request button, the system safely transitions through amber warning signals before bringing vehicle traffic to a complete stop, enabling a dedicated pedestrian crossing phase.

---

## ✨ Features
* **Automated Vehicle Traffic Flow:** Sequential control for vehicle movement (Green → Yellow → Red).
* **Interactive Pedestrian Request:** Active-LOW push button input to trigger safe pedestrian crosswalk phases.
* **Non-Blocking Asynchronous Logic:** Leverages `millis()` instead of blocking delays to continuously scan inputs in real time.
* **Internal Pull-Up Circuitry:** Configured via `INPUT_PULLUP` to maintain pin stability without external resistors.
* **Flashing Pedestrian Warning:** Visual alert phase signaling the end of pedestrian crossing time.
* **Serial Telemetry Logging:** Real-time state updates, timing logs, and request confirmations via the Serial Monitor.

---

## 🔧 Components Used
* Arduino UNO R3
* Car Red LED
* Car Yellow LED
* Car Green LED
* Pedestrian Red LED
* Pedestrian Green LED
* Tactile Push Button
* 5x 220Ω Current-Limiting Resistors
* Breadboard
* Jumper Wires
* USB Cable

---

## 🔌 Pin Connections

| Component | Pin / Terminal | Arduino UNO Pin |
| :--- | :--- | :--- |
| **Car Green LED** | Anode via 220Ω | Digital Pin 2 |
| **Car Yellow LED** | Anode via 220Ω | Digital Pin 3 |
| **Car Red LED** | Anode via 220Ω | Digital Pin 4 |
| **Pedestrian Green LED** | Anode via 220Ω | Digital Pin 5 |
| **Pedestrian Red LED** | Anode via 220Ω | Digital Pin 6 |
| **Pedestrian Push Button** | Pin 1 | Digital Pin 7 |
| **Pedestrian Push Button** | Pin 2 | GND |
| **All LED Cathodes** | Short Leg | GND Rail |

---

## ⚙️ How It Works
1. The Arduino initializes digital pin modes, enables the internal pull-up resistor on Pin 7, and opens Serial Communication at 9600 baud.
2. The system enters the primary vehicle flow state (`CARS_GO`), keeping the vehicle green LED and pedestrian red LED lit.
3. The microcontroller constantly monitors Pin 7 in the background without halting code execution.
4. When a pedestrian presses the button, a crossing request is logged internally.
5. The system seamlessly transitions to `CARS_WARN` (Yellow LED) to notify oncoming drivers.
6. Vehicle traffic is brought to a full stop (`CARS_RED`), and the pedestrian signal switches to Green (`PEDS_CROSS`).
7. A flashing green warning indicates the crossing cycle is ending before traffic flow is safely restored to vehicles.

---

## 💻 Technologies & Concepts
* Embedded C / C++ Programming
* Finite State Machines (FSM)
* Non-Blocking Timing Architecture (`millis()`)
* Digital Input & Output (GPIO)
* Internal Pull-Up Resistors (`INPUT_PULLUP`)
* Asynchronous Serial UART Communication
* Circuit Design & Hardware Prototyping
* Hardware Debugging

---

## 📚 Libraries Used
* **`Arduino.h`** *(Core built-in library for standard I/O and timing functions)*

---

## 🧪 Testing

The system was verified across active operational phases using visual LED cues and Serial Monitor logs:

### 1. Normal Automatic Cycle (`CARS_GO`)
* **Vehicle LEDs:** Green ON, Yellow OFF, Red OFF
* **Pedestrian LEDs:** Red ON, Green OFF
* **Serial Monitor:** `State: CARS_GO (Green for vehicles)`

### 2. Pedestrian Button Triggered
* **Input Action:** Button Pressed
* **Serial Monitor:** `>> Pedestrian request registered! Will switch after current cycle.`
* **Transition:** Vehicle Yellow turns ON for 2 seconds (`CARS_WARN`).

### 3. Pedestrian Crossing Phase (`PEDS_CROSS`)
* **Vehicle LEDs:** Red ON (Traffic Stopped)
* **Pedestrian LEDs:** Green ON (Safe to Cross)
* **Serial Monitor:** `State: PEDS_CROSS (Safe for pedestrians to cross)`

### 4. Pedestrian Warning Phase (`PEDS_WARN`)
* **Pedestrian LEDs:** Green LED flashes 3 times.
* **Return State:** System securely resets back to `CARS_GO`.

---

## 📸 Project Demonstration
*(Add circuit diagram screenshots, Wokwi simulation captures, or breadboard hardware photos here)*

---

## 🎯 Learning Outcome
This project provided hands-on experience in implementing Finite State Machines in C/C++, avoiding blocking execution with `millis()`, managing active-LOW digital inputs, and building deterministic multi-output embedded systems.

---

## 👩‍💻 Author
**Manasi Sunil Ambore**  
*Electronics & Communication Engineering Student*

---

## 📸 Project Demonstration


---

## 🎥 Project Demo
▶️ *(Insert link to project video or simulation recording here)*
