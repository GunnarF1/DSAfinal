#include "ForstersAuto.h"

// Function to write order receipt to a text file
void writeOrderToFile(const string& partName, double partPrice, ofstream& outFile) {
    outFile << left << setw(20) << partName << setw(10) << partPrice << endl;
}

// Function to process the checkout and update the queue
void checkout(queue<string>& userQueue, double& totalOrder) {
    // Check if there are any users in the queue
    if (userQueue.empty()) {
        cout << "No users in the queue. Exiting program." << endl;
        exit(0);
    }

    // Get the next user in line and remove them from the queue
    string currentUser = userQueue.front();
    userQueue.pop();

    // Display the total order to the user and update the total cost
    cout << "Your total order is: $" << fixed << setprecision(2) << totalOrder << endl;

    // Display the next user in line
    if (!userQueue.empty()) {
        cout << "Next user in line: " << userQueue.front() << endl;
    }
}

// Bubble sort function to sort parts menu by alphabetical order
void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
