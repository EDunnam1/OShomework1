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

    // Generate initial set of random numbers and put them in the priority queue
    cout << "Initial numbers in the queue: ";
    for (int i = 0; i < 10; ++i) {
        int num = generateRandomNumber();
        pq.push(num);
        cout << num << " ";
    }
    cout << endl;

    // Simulate dispatching and generating new numbers
    for (int i = 0; i < 30; ++i) {
        // Dispatch the highest priority job
        int currentDispatched = pq.top();
        pq.pop();
        cout << "The current dispatched number is " << currentDispatched << endl;

        // Generate a new random number
        int newNumber = generateRandomNumber();
        cout << "The new coming number is " << newNumber << endl;

        // Add the new number to the priority queue
        pq.push(newNumber);

        // Print the numbers in the queue
        cout << "The numbers in the queue are: ";
        priority_queue<int, vector<int>, greater<int>> temp = pq; // Make a copy to print without modifying the original
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    return 0;
}