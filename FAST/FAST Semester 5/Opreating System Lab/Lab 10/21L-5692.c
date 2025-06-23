// main.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int laps;
int lapTime;
int lapCounter = 0;

void childHandler(int signum) {
    if (signum == SIGCHLD) {
        int status;
        wait(&status);
        printf("Completed Lap: %d\n", ++lapCounter);

        if (lapCounter < laps) {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                sleep(lapTime);
                exit(0);
            }
        } else {
            printf("Received SIGCHLD\nTotal Time in Seconds: %d\n", laps * lapTime);
            exit(0);
        }
    }
}

int main() {
    signal(SIGCHLD, childHandler);

    printf("Enter Number of Laps: ");
    scanf("%d", &laps);

    printf("Enter Lap Time: ");
    scanf("%d", &lapTime);

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        sleep(lapTime);
        exit(0);
    } else {
        // Parent process
        while (1) {
            // Nothing will be done, parent will be interrupted by signals
        }
    }

    return 0;
}

