#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

// Configuration (in milliseconds)
#define WATCHDOG_TIMEOUT_MS 1000
#define KICK_INTERVAL_MS 500

// Global variable
time_t last_kick_time;
bool is_hanging = false;

void kick_watchdog() {
    last_kick_time = time(NULL);
    printf("Watchdog kicked at %ld\n", last_kick_time);
}

int main() {
    // Initialize the watchdog
    kick_watchdog();

    int loop_counter = 0;
    while (1) {
        printf("Application doing some work....\n");

        // Check if watchdog has timed out
        time_t current_time = time(NULL);
        if ((current_time - last_kick_time) * 1000 > WATCHDOG_TIMEOUT_MS) {
            printf("WATCHDOG TIMEOUT at %ld!\n", current_time);
            printf("SYSTEM RESET!\n");
            kick_watchdog(); // Reset the watchdog
            is_hanging = false;
            printf("System reset.\n");
        }

        // Periodically "kick" the watchdog
        if ((loop_counter * 100) % KICK_INTERVAL_MS == 0) { // Assuming roughly 100ms delay
            kick_watchdog();
        }

        // Simulate a condition that causes a "hang"
        if (loop_counter == 5) {
            printf("Simulating a software hang!\n");
            is_hanging = true;
            while (is_hanging) {
                printf("Hanging...\n");
                sleep(1);
            }
        }

        usleep(100000); // 100 milliseconds
        loop_counter++;
    }
    return 0;
}