#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

//STATEMENT OF PURPOSE
//Authors: Evan Dunnam and Zach Monette
//March. 26, 2024
//The program creates processes with unique, incrementing IDs and assigns them a random number that serves as the 
//priority and time needed in the CPU.
//A ready queue handles 5 processes in a roud-robbin fashion with a 2 unit slice time.
// If a program needs more time, it will be put back in the ready queue. Otherwise it will terminate and leave the system.
// (If a program has an execution time of 3, it will complete 2 units of time before it is moved to the back, where its number will change to 1.
int generateRandomNumber() {
    return rand() % 20 + 1; // Generates a random number between 1 and 20
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    priority_queue<int, vector<int>, greater<int>> pq; // Priority queue to store jobs
    vector<int> queue; // Vector to store the last 10 elements
    stack<int> readyQueue; //Ready queue for programs to be processed

    // Generate initial set of random numbers and put them in the priority queue
    cout << "Initial numbers in the queue: ";
    for (int i = 0; i < 10; ++i) {
        int num = generateRandomNumber();
        pq.push(num);
        queue.push_back(num);
    }

    // Print the initial numbers in the queue
    for (auto it = queue.begin(); it != queue.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Simulate dispatching and generating new numbers
    for (int i = 0; i < 10; ++i) {
        // Dispatch the highest priority job
        int currentDispatched = pq.top();
        pq.pop();
        cout << "The current dispatched number is " << currentDispatched << endl;

        // Remove the dispatched number from the display queue
        queue.erase(find(queue.begin(), queue.end(), currentDispatched));

        // Generate a new random number
        int newNumber = generateRandomNumber();
        cout << "The new coming number is " << newNumber << endl;

        // Add the new number to the priority queue
        pq.push(newNumber);
        queue.push_back(newNumber);

        // If the stack exceeds 10 elements, remove the oldest element
        if (queue.size() > 10) {
            queue.erase(queue.begin());
        }

        // Print the numbers in the queue with the newest number on the right side
        cout << "The numbers in the queue are: ";
        for (int i = 0; i < 10; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

