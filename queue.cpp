/* Program name: Queues
Author: Heritage Adigun
Date last updated: 10/24/2024
Purpose: A program that defines the queue design using array implementation using special array slot called the reserved slot.*/


#include <iostream>
using namespace std;

class ReservedSlotQueue {
private:
    int* arr; // Array to store queue elements
    int front; // Index of the front element
    int rear; // Index of the rear element
    int capacity; // Maximum number of elements the queue can hold
    int size; // Current number of elements in the queue
public:
    // Constructor to initialize the queue
    ReservedSlotQueue(int maxCapacity) {
        capacity = maxCapacity + 1; // Adding one for the reserved slot
        arr = new int[capacity];
        front = rear = size = 0;
    }

    // Destructor to free memory
    ~ReservedSlotQueue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity - 1;
    }

    // Function to enqueue an element into the queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        arr[rear] = element;
        rear = (rear + 1) % capacity;
        size++;
    }

    // Function to dequeue an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a sentinel value for an empty queue
        }

        int element = arr[front];
        front = (front + 1) % capacity;
        size--;
        return element;
    }
};

int main() {
    ReservedSlotQueue queue(5); // Create a queue with a capacity of 5

    // Enqueue elements
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // Dequeue elements
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    // Enqueue more elements
    queue.enqueue(4);
    queue.enqueue(5);

    // Try to enqueue when the queue is full
    queue.enqueue(6);

    // Dequeue the remaining elements
    while (!queue.isEmpty()) {
        cout << "Dequeued: " << queue.dequeue() << endl;
    }

    return 0;
}