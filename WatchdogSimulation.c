// Vehicle Watchdog Simulation
#include <stdio.h>
#include <stdlib.h> // For atoi
#include <stdbool.h> // For boolean type
#include <unistd.h> // For sleep (optional, for timing)

// Default Configuration
#define DEFAULT_WATCHDOG_TIMEOUT 100
#define DEFAULT_KICK_INTERVAL 50

// Global variables
int watchdog_counter;
bool is_hanging = false;
int watchdog_timeout;
int kick_interval;

// Function to "kick" (reset) the watchdog timer
void kick_watchdog() {
    watchdog_counter = watchdog_timeout;
    printf("Watchdog kicked!\n");
}

int main() {
    char input_buffer[256];

    // Prompt user for watchdog timeout
    printf("Enter watchdog timeout (in loop iterations, default: %d): ", DEFAULT_WATCHDOG_TIMEOUT);
    if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {
        watchdog_timeout = atoi(input_buffer);
        if (watchdog_timeout <= 0) {
            printf("Invalid input. Using default watchdog timeout: %d\n", DEFAULT_WATCHDOG_TIMEOUT);
            watchdog_timeout = DEFAULT_WATCHDOG_TIMEOUT;
        }
    } else {
        printf("Error reading input. Using default watchdog timeout: %d\n", DEFAULT_WATCHDOG_TIMEOUT);
        watchdog_timeout = DEFAULT_WATCHDOG_TIMEOUT;
    }

    // Prompt user for kick interval
    printf("Enter kick interval (in loop iterations, default: %d): ", DEFAULT_KICK_INTERVAL);
    if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {
        kick_interval = atoi(input_buffer);
        if (kick_interval <= 0 || kick_interval >= watchdog_timeout) {
            printf("Invalid input (must be > 0 and < watchdog timeout). Using default kick interval: %d\n", DEFAULT_KICK_INTERVAL);
            kick_interval = DEFAULT_KICK_INTERVAL;
        }
    } else {
        printf("Error reading input. Using default kick interval: %d\n", DEFAULT_KICK_INTERVAL);
        kick_interval = DEFAULT_KICK_INTERVAL;
    }

    printf("Watchdog Timeout: %d iterations\n", watchdog_timeout);
    printf("Kick Interval: %d iterations\n", kick_interval);

    // Initialize the watchdog counter
    watchdog_counter = watchdog_timeout;

    // Main application loop
    int loop_counter = 0;
    while (1) {
        // Simulate some application work
        printf("Application doing some work....\n");

        // Simulate a timer interrupt (or check within the loop)
        watchdog_counter--;

        printf("Watchdog counter: %d\n", watchdog_counter);

        // Periodically "kick" the watchdog
        if (loop_counter % kick_interval == 0) {
            kick_watchdog();
        }

        // Check if watchdog has timed out
        if (watchdog_counter <= 0) {
            printf("WATCHDOG RESET!\n");
            // Simulate a reset (in a real system, this would be a hardware reset)
            watchdog_counter = watchdog_timeout;        // Reset the counter
            is_hanging = false;            // Clear the hang flag (if it was set)
            printf("System reset.\n");
        }

        // Simulate a condition that causes a "hang"
        if (loop_counter == 50) {
            printf("Simulating a software hang!\n");
            is_hanging = true;
            while (is_hanging) {
                // Infinite loop - the watchdog should eventually trigger
                printf("Hanging...\n");
                sleep(1); // To prevent the loop from consuming all CPU
            }
        }

        // Optional: Add a small delay to simulate real-time behavior
        usleep(100000); // 100 milliseconds
        loop_counter++;
    }

    return 0;
}