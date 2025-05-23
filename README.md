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