#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold process information
struct Process {
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    int processed;
};

// Function to calculate waiting time and turnaround time using FCFS algorithm
void calculateFCFS(struct Process *processes, int numProcesses) {
    // FCFS algorithm
    int currentTime = 0;
    for (int i = 0; i < numProcesses; ++i) {
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        if (processes[i].waitingTime < 0) {
            processes[i].waitingTime = 0;
        }
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
    }
}

void calculateSJF(struct Process *processes, int numProcesses) {
    // SJF algorithm
    // Sort processes based on burst time in ascending order
    for (int i = 0; i < numProcesses - 1; ++i) {
        for (int j = 0; j < numProcesses - i - 1; ++j) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                // Swap processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int currentTime = 0;
    for (int i = 0; i < numProcesses; ++i) {
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        if (processes[i].waitingTime < 0) {
            processes[i].waitingTime = 0;
        }
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
    }
}

/*int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <scheduling_algorithm(FCFS/SJF)>\n", argv[0]);
        return 1;
    }

    char *fileName = argv[1];
    char *algorithm = argv[2];

    // Open the input file
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return 1;
    }

    int numProcesses;
    fscanf(file, "%d", &numProcesses);

    // Allocate memory for processes
    struct Process *processes = malloc(numProcesses * sizeof(struct Process));

    // Read process information from the file
    for (int i = 0; i < numProcesses; ++i) {
        fscanf(file, "%d %d", &processes[i].burstTime, &processes[i].arrivalTime);
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
        processes[i].processed = 0;
    }

    // Close the file as we have read the data
    fclose(file);

    // Choose the scheduling algorithm and calculate waiting time and turnaround time
    if (strcmp(algorithm, "FCFS") == 0) {
        calculateFCFS(processes, numProcesses);
    } else if (strcmp(algorithm, "SJF") == 0) {
        calculateSJF(processes, numProcesses);
    } else {
        printf("Error: Invalid scheduling algorithm. Please use FCFS or SJF.\n");
        free(processes);
        return 1;
    }

    // Calculate average waiting time and average turnaround time
    double avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < numProcesses; ++i) {
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }
    avgWaitingTime /= numProcesses;
    avgTurnaroundTime /= numProcesses;

    // Output the order of execution of processes and average times
    printf("Order of Execution: ");
    for (int i = 0; i < numProcesses; ++i) {
        printf("P%d", i + 1);
        if (i < numProcesses - 1) {
            printf(" -> ");
        }
    }
    printf("\nAverage Waiting Time: %.2lf\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnaroundTime);

    // Free allocated memory
    free(processes);

    return 0;
}*/