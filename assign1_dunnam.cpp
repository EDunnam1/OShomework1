#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

//STATEMENT OF PURPOSE
//Authors: Evan Dunnam and Zach Monette
//Feb. 7, 2024
//The program outputs a 10 item priority queue 30 times with a randomly generated priority item being added with each iteration
//As items are generated, the highest priority item in the list will be popped and printed out.
//The program will generate a string of the priority queue followed preceded by the incoming item and followed by the highest priority item being popped

int generateRandomNumber() {
    return rand() % 100 + 1; // Generates a random number between 1 and 100
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    priority_queue<int, vector<int>, greater<int>> pq; // Priority queue to store jobs
    vector<int> queue; // Vector to store the last 10 elements

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
        for (int i = 0; i < 10;i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

