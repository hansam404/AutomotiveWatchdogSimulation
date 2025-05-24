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

void print_progress_bar(int value, int max, int width) {
    int filled = (value * width) / max;
    printf("[");
    for (int i = 0; i < width; ++i) {
        if (i < filled)
            printf("#");
        else
            printf(" ");
    }
    printf("] %3d/%-3d\n", value, max);
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
        // Clear the screen (ANSI escape code)
        printf("\033[2J\033[H");

        // Print UI header
        printf("=== Automotive Watchdog Simulation ===\n");
        printf("Watchdog Timeout: %-5d | Kick Interval: %-5d | Loop: %-6d\n", watchdog_timeout, kick_interval, loop_counter);
        printf("----------------------------------------------------------\n");

        // Progress bar for watchdog counter
        printf("Watchdog Counter: ");
        print_progress_bar(watchdog_counter, watchdog_timeout, 30);

        // Show system state with color
        if (is_hanging) {
            printf("System State: \033[1;31mHANGING\033[0m\n"); // Red
        } else {
            printf("System State: \033[1;32mRUNNING\033[0m\n"); // Green
        }

        printf("----------------------------------------------------------\n");
        printf("Application doing some work....\n");

        // Simulate a timer interrupt (or check within the loop)
        watchdog_counter--;

        // Periodically "kick" the watchdog
        if (loop_counter % kick_interval == 0) {
            kick_watchdog();
        }

        // Check if watchdog has timed out
        if (watchdog_counter <= 0) {
            printf("\033[1;33mWATCHDOG RESET!\033[0m\n"); // Yellow
            // Simulate a reset (in a real system, this would be a hardware reset)
            watchdog_counter = watchdog_timeout;        // Reset the counter
            is_hanging = false;            // Clear the hang flag (if it was set)
            printf("System reset.\n");
            usleep(1000000); // Pause to show reset message
        }

        // Simulate a condition that causes a "hang"
        if (loop_counter == 50) {
            printf("Simulating a software hang!\n");
            is_hanging = true;
            while (is_hanging) {
                // Clear the screen for hang UI
                printf("\033[2J\033[H");
                printf("=== Automotive Watchdog Simulation ===\n");
                printf("System State: \033[1;31mHANGING\033[0m\n");
                printf("Watchdog Counter: %d\n", watchdog_counter);
                printf("Hanging...\n");
                sleep(1); // To prevent the loop from consuming all CPU
                watchdog_counter--;
                if (watchdog_counter <= 0) {
                    printf("\033[1;33mWATCHDOG RESET!\033[0m\n");
                    watchdog_counter = watchdog_timeout;
                    is_hanging = false;
                    printf("System reset.\n");
                    sleep(1);
                }
            }
        }

        // Optional: Add a small delay to simulate real-time behavior
        usleep(100000); // 100 milliseconds
        loop_counter++;
    }

    return 0;
}