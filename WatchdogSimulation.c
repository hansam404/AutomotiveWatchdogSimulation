//Vehicle Watchdog Simulation
#include<stdio.h>
#include<stdbool.h> // For boolean type
#include<unistd.h> // For sleep (optional, for timing)

//Configuration
#define WATCHDOG_TIMEOUT 100
#define KICK_INTERVAL 50 // How often to "kick" the watchdog (in loop iterations)

// Global variablesc
int watchdog_counter;
bool is_hanging = false;

// Function to "kick" (reset) the watchdog timer

void kick_watchdog() {
    watchdog_counter = WATCHDOG_TIMEOUT;
    printf("Watchdog kicked!\n");
}

int main() {


    // Initialize the watchdog counter
    watchdog_counter = WATCHDOG_TIMEOUT;

    // Main application loop

    int loop_counter = 0;

    while (1) {
        
        // Simulate some application work 
        printf("Application doing some work....\n");

        // Simulate a timer interrupt (or check within the loop)
        watchdog_counter--;

        printf("Watchdog counter: %d\n", watchdog_counter);

        // Periodically "kick" the watchdog

        if (loop_counter% KICK_INTERVAL == 0) {

            kick_watchdog();
        }

        // Check if watchdog has timed out

        if (watchdog_counter <= 0) {

            printf("WATCHDOG RESET!\n");

            // Simulate a reset (in a real system, this would be a hardware reset)
            watchdog_counter = WATCHDOG_TIMEOUT;        // Reset the counter
            is_hanging = false;     // Clear the hang flag (if it was set)
            printf("System reset.\n");

    }

        // Simulate a condition that causes a "hang"

        if (loop_counter = 50) {

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
