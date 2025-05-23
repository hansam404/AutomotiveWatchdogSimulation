# 🚗 Vehicle Watchdog Simulation 🐶

[![C Language](https://img.shields.io/badge/C-Programming-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Stars](https://img.shields.io/github/stars/YOUR_GITHUB_USERNAME/YOUR_REPOSITORY_NAME?style=social)](https://github.com/YOUR_GITHUB_USERNAME/YOUR_REPOSITORY_NAME/stargazers)
[![GitHub Forks](https://img.shields.io/github/forks/YOUR_GITHUB_USERNAME/YOUR_REPOSITORY_NAME?style=social)](https://github.com/YOUR_GITHUB_USERNAME/YOUR_REPOSITORY_NAME/network/members)

## 🛠️ Overview

This project simulates a basic watchdog timer, a crucial component in embedded systems, particularly in connected vehicles. Watchdog timers are used to detect and recover from software malfunctions or hardware issues that might cause the system to hang or become unresponsive.

The simulation demonstrates the fundamental principles of a watchdog:

* **Timeout:** A predefined period (in loop iterations) within which the watchdog expects to be "kicked" (reset).
* **Kicking:** The act of signaling to the watchdog that the system is still functioning correctly.
* **Reset:** If the watchdog is not kicked within the timeout period, it triggers a system reset to bring the system back to a known good state.

This project now allows you to **input custom configurations** for the watchdog timeout and kick interval when the program starts.

## ⚙️ How it Works

The simulation operates in a loop, mimicking the behavior of a real-time system.

1.  **Initialization:** The program prompts the user to enter the desired watchdog timeout and kick interval. Default values are provided if the user enters invalid input or no input.
2.  **User Input:** The program uses `fgets` to read input from the user for both the watchdog timeout and the kick interval. `atoi` is then used to convert the input strings to integers.
3.  **Input Validation:** Basic validation is performed to ensure the provided values are positive and that the kick interval is less than the watchdog timeout. If invalid input is detected, the default values are used.
4.  **Watchdog Counter Initialization:** The watchdog counter is initialized to the configured `watchdog_timeout` value.
5.  **Application Work:** The main loop simulates the vehicle's software performing its regular tasks.
6.  **Watchdog Counter Decrement:** In each iteration (representing a time tick), the watchdog counter is decremented.
7.  **Kicking the Watchdog:** At regular intervals (defined by the configured `kick_interval`), the `kick_watchdog()` function is called, which resets the `watchdog_counter` back to `watchdog_timeout`. This signifies that the application is still running and responsive.
8.  **Timeout Detection:** If the `watchdog_counter` reaches zero or goes below, it indicates that the watchdog has not been kicked in time, implying a system hang.
9.  **Simulated Reset:** Upon timeout, the simulation prints a "WATCHDOG RESET!" message and resets the `watchdog_counter`, simulating a hardware reset.
10. **Simulated Hang:** The code includes a section that intentionally simulates a software hang using an infinite `while` loop. This demonstrates how the watchdog mechanism detects and recovers from such situations.

## 📂 Project Structure

├── README.md
└── watchdog_simulation.c


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

### Running the Simulation with Custom Configuration (User Input)

1.  Open your terminal or command prompt and navigate to the directory where you compiled the executable (`watchdog_simulation`).

2.  Run the simulation:

    ```bash
    ./watchdog_simulation
    ```

3.  The program will then prompt you to enter the watchdog timeout and kick interval:

    ```
    Enter watchdog timeout (in loop iterations, default: 100):
    ```

    Enter the desired integer value and press Enter.

    ```
    Enter kick interval (in loop iterations, default: 50):
    ```

    Enter the desired integer value and press Enter.

4.  The simulation will then start using the values you provided (or the defaults if your input was invalid or if you just pressed Enter).

5.  Observe the output, which will indicate the configured watchdog timeout and kick interval before the simulation starts. You'll then see the application work, watchdog kicks, and simulated resets based on your input.

## ⚙️ Configuration

The following default parameters are used if you don't provide valid input:

```c
// Default Configuration
#define DEFAULT_WATCHDOG_TIMEOUT 100      // Number of loop iterations before timeout
#define DEFAULT_KICK_INTERVAL 50        // Number of loop iterations between watchdog kicks
You can override these defaults by providing integer values as prompted when the program runs. Ensure that the kick interval is a positive value and less than the watchdog timeout.

💡 Potential Enhancements
Here are some ideas to further develop this simulation:

🕰️ Time-Based Watchdog with User Configuration: Implement the watchdog using actual time (e.g., milliseconds) and prompt the user to enter timeout and kick interval in milliseconds.
📝 Configuration File: Instead of user input at runtime, read configuration parameters from a separate file (e.g., a .ini or .cfg file).
🚦 Different Failure Modes with User Selection: Simulate various types of failures and allow the user to choose which failure mode to trigger via input.
🧱 Modular Design: Encapsulate the watchdog logic into a separate set of functions or a structure for better organization and reusability.
📞 Watchdog Driver Interface: Create an abstract interface that mimics how a real watchdog driver would interact with the application code, potentially with configuration options.
🔄 Hardware Reset Simulation: Instead of just printing a message, simulate a more detailed system reset process.
<0xF0><0x9F><0x97><0x84> Logging with User-Configurable Levels: Add logging functionality and allow the user to set the verbosity of the logs.
TaskManager Integration with User-Defined Tasks: Integrate the watchdog with a simple task scheduler and allow the user to define tasks and their expected execution times.
🔗 Related Concepts
Real-Time Operating Systems (RTOS)
Embedded Systems
Fault Tolerance
Connected Vehicles
📜 License
This project is licensed under the MIT License. See the LICENSE file for more details.

👨‍💻 Author
[Your Name/GitHub Username]

Feel free to contribute to this project by submitting pull requests or suggesting improvements!