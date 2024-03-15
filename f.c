#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Define a static variable
static int count = 0;

// Signal handler function
void signal_handler(int signal) {
    if (signal == SIGINT) {
        // Increment the static variable
        count++;
        printf("\nCtrl+C pressed %d times. Exiting...\n", count);
        exit(EXIT_SUCCESS);
    }
}

int main() {
    // Register signal handler
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        perror("Signal registration failed");
        exit(EXIT_FAILURE);
    }

    printf("Press Ctrl+C to increment static variable and exit.\n");

    // Infinite loop to keep the program running
    while (1) {
        // Your main program logic goes here
        // For demonstration purposes, we'll just keep the program running
    }

    return 0;
}