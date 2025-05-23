# 🚗 Vehicle Watchdog Simulation 🐶

[![C Language](https://img.shields.io/badge/C-Programming-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Stars](https://img.shields.io/github/stars/YOUR_GITHUB_USERNAME/YOUR_REPOSITORY_NAME?style=social)](https://github.com/YOUR_GITHUB_USERNAME/YOUR_REPOSITORY_NAME/stargazers)
[![GitHub Forks](https://img.shields.io/github/forks/YOUR_GITHUB_USERNAME/YOUR_REPOSITORY_NAME?style=social)](https://github.com/YOUR_GITHUB_USERNAME/YOUR_REPOSITORY_NAME/network/members)

## 🛠️ Overview

This project simulates a basic watchdog timer, a crucial component in embedded systems, particularly in connected vehicles. Watchdog timers are used to detect and recover from software malfunctions or hardware issues that might cause the system to hang or become unresponsive.

The simulation demonstrates the fundamental principles of a watchdog:

* **Timeout:** A predefined period within which the watchdog expects to be "kicked" (reset).
* **Kicking:** The act of signaling to the watchdog that the system is still functioning correctly.
* **Reset:** If the watchdog is not kicked within the timeout period, it triggers a system reset to bring the system back to a known good state.

This project is intended for educational purposes and to showcase the implementation of this vital safety mechanism in connected vehicle systems.

## ⚙️ How it Works

The simulation operates in a loop, mimicking the behavior of a real-time system.

1.  **Initialization:** The watchdog counter is initialized to a predefined `WATCHDOG_TIMEOUT` value.
2.  **Application Work:** The main loop simulates the vehicle's software performing its regular tasks.
3.  **Watchdog Counter Decrement:** In each iteration (representing a time tick), the watchdog counter is decremented.
4.  **Kicking the Watchdog:** At regular intervals (defined by `KICK_INTERVAL`), the `kick_watchdog()` function is called, which resets the `watchdog_counter` back to `WATCHDOG_TIMEOUT`. This signifies that the application is still running and responsive.
5.  **Timeout Detection:** If the `watchdog_counter` reaches zero or goes below, it indicates that the watchdog has not been kicked in time, implying a system hang.
6.  **Simulated Reset:** Upon timeout, the simulation prints a "WATCHDOG RESET!" message and resets the `watchdog_counter`, simulating a hardware reset.
7.  **Simulated Hang:** The code includes a section that intentionally simulates a software hang using an infinite `while` loop. This demonstrates how the watchdog mechanism detects and recovers from such situations.

## 📂 Project Structure
├── README.md          <- This file
└── watchdog_simulation.c <- The C source code for the simulation


## 🚀 Getting Started

### Prerequisites

* A C compiler (like GCC)
* A terminal or command prompt

### Compilation

1.  Save the code as `watchdog_simulation.c`.
2.  Open your terminal or command prompt and navigate to the directory where you saved the file.
3.  Compile the code using GCC:

    ```bash
    gcc watchdog_simulation.c -o watchdog_simulation
    ```

### Running the Simulation

1.  Execute the compiled program:

    ```bash
    ./watchdog_simulation
    ```

2.  Observe the output, which will show the application doing work, the watchdog being kicked, and the simulated reset when the hang condition is triggered.

## ⚙️ Configuration

The following parameters can be adjusted in the `watchdog_simulation.c` file:

```c
// Configuration
#define WATCHDOG_TIMEOUT 100      // Number of loop iterations before timeout
#define KICK_INTERVAL 50        // Number of loop iterations between watchdog kicks
WATCHDOG_TIMEOUT: This defines how many loop iterations the watchdog will wait before assuming a system failure if it's not kicked. A higher value means a longer timeout period.
KICK_INTERVAL: This determines how often the kick_watchdog() function is called (in terms of loop iterations). The watchdog should be kicked more frequently than the timeout period to prevent resets during normal operation.
💡 Potential Enhancements
Here are some ideas to further develop this simulation:

🕰️ Time-Based Watchdog: Implement the watchdog using actual time (e.g., milliseconds) instead of loop iterations for more realistic timing. Explore using <time.h> functions.
📝 Configurable Parameters: Allow setting WATCHDOG_TIMEOUT and KICK_INTERVAL via command-line arguments or a configuration file.
🚦 Different Failure Modes: Simulate various types of failures that could prevent the watchdog from being kicked (e.g., a function taking too long, resource contention).
🧱 Modular Design: Encapsulate the watchdog logic into a separate set of functions or a structure for better organization and reusability.
📞 Watchdog Driver Interface: Create an abstract interface that mimics how a real watchdog driver would interact with the application code.
🔄 Hardware Reset Simulation: Instead of just printing a message, simulate a more detailed system reset process.
<0xF0><0x9F><0x97><0x84> Logging: Add logging functionality to record watchdog events (kicks, timeouts, resets) for debugging and analysis.
TaskManager Integration: Integrate the watchdog with a simple task scheduler to monitor the execution of different simulated tasks.
🔗 Related Concepts
Real-Time Operating Systems (RTOS): Watchdogs are commonly used in RTOS environments to ensure the reliability of time-critical tasks.
Embedded Systems: Watchdog timers are essential in embedded systems where manual intervention might not be possible in case of failures.
Fault Tolerance: Watchdog timers are a key component in building fault-tolerant systems that can automatically recover from errors.
Connected Vehicles: In connected vehicles, ensuring the reliability and safety of software components is paramount, making watchdog timers a critical safety mechanism.
📜 License
This project is licensed under the MIT License. See the LICENSE file for more details.

👨‍💻 Author
[Samyak Hanwate/hansam404]

Feel free to contribute to this project by submitting pull requests or suggesting improvements!

