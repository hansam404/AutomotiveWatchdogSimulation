//Vehicle Watchdog Simulation
#include <stdio.h>

#include <stdbool.h> // For boolean type

#include <unistd.h> // For sleep (optional, for timing)

//Configuration

#define WATCHDOG TIMEOUT 100

#define KICK_INTERVAL 10 // How often to "kick" the watchdog (in loop iterations)

// Global variables

int watchdog counter,

bool is hanging = false;

// Function to "kick" (reset) the watchdog timer

void kick watchdog() {
    watchdog counter = WATCHDOG TIMEOUT;
    printf("Watchdog kicked!\n");

int main() {

    // Initialize the watchdog counter
    watchdog counter = WATCHDOG TIMEOUT;

    // Main application loop

    int loop counter = 0;

    while (1) (

        // Simulate some application work printf("Application doing some work....\n");

        // Simulate a timer interrupt (or check within the loop)

        watchdog counter--;

        printf("Watchdog counter: %d\n", watchdog counter),

        // Periodically "kick" the watchdog

        if (lopp counter% KICK_INTERVAL == 0) {

            kick watchdog();
        }

        // Check if watchdog has timed out

        if (watchdog counter <= 0) {

            printf("WATCHDOG RESET!\n");

            // Simulate a reset (in a real system, this would be a hardware reset)

            watchdog counter = WATCHDOG_TIMEOUT;

            // Reset the counter

            is_hanging = false;

            // Clear the hang flag (if it was set)

        }

}

printf("System reset.\n");

}

// Simulate a condition that causes a "hang"

if (loop counter = 50) {

printf("Simulating a software hang!\n");

is hanging = true;

while (is hanging) {

// Infinite loop - the watchdog should eventually trigger

printf("Hanging...\n");

sleep(1); // To prevent the loop from consuming all CPU

// Optional: Add a small delay to simulate real-time behavior

usleep(100000); // 100 milliseconds

loop.counter++;
}
return 0;

}
