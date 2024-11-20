#include <iostream>
#include <fstream>
using namespace std;

const int P = 5; // Number of processes
const int R = 3; // Number of resources

// Function to find the need matrix
void calculate(int need[P][R], int max[P][R], int allot[P][R]) {
    // Calculate the need matrix based on max and allotted resources
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allot[i][j];
}

// Function to check if the system is in a safe state
bool isSafe(int processes[], int avail[], int max[][R], int allot[][R]) {
    int need[P][R];
    calculate(need, max, allot); // Calculate the need matrix

    bool finish[P] = { 0 }; // Mark all processes as unfinished
    int safeSeq[P]; // Safe sequence array

    int work[R];
    // Initialize the work array with available resources
    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    int count = 0;
    // Continue until all processes are finished
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) { // If process p is not finished
                int j;
                // Check if process p's needs can be met with current work resources
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                // If all needs of process p can be met
                if (j == R) {
                    // Allocate resources to process p and add to work
                    for (int k = 0; k < R; k++)
                        work[k] += allot[p][k];

                    // Add process p to safe sequence and mark it as finished
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }

        // If no unfinished process could be found whose needs can be met
        if (!found) {
            cout << "System is not in safe state" << endl;
            return false;
        }
    }

    // Print the safe sequence
    cout << "System is in safe state.\nSafe sequence is: ";
    for (int i = 0; i < P; i++)
        cout << safeSeq[i] << " ";

    return true;
}

int main() {
    ifstream inputFile("/Users/annikamorgan/Desktop/CompSci/PA2/PA2/input.txt");
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    int processes[P]; // Array to hold process identifiers
    int avail[R]; // Array to hold available resources
    int max[P][R]; // Max matrix
    int allot[P][R]; // Allocation matrix

    // Read process identifiers from file
    for (int i = 0; i < P; i++)
        inputFile >> processes[i];

    // Read available resources from file
    for (int i = 0; i < R; i++)
        inputFile >> avail[i];

    // Read max matrix from file
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            inputFile >> max[i][j];

    // Read allocation matrix from file
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            inputFile >> allot[i][j];

    inputFile.close();

    // Check if the system is in a safe state
    isSafe(processes, avail, max, allot);

    return 0;
}
