/* Program name: linkedQueueType
Author: Heritage Adigun
Date last updated: 10/24/2024
Purpose: A program that defines the class linkedQueueType which is derived from the class unorderedLinkedList and a program that tests various operations of the class. */


#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// unorderedLinkedList class (base class)
class unorderedLinkedList {
protected:
    Node* head;
    Node* tail;
    int count;

public:
    // Constructor
    unorderedLinkedList() {
        head = tail = nullptr;
        count = 0;
    }

    // Destructor
    ~unorderedLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        count = 0;
    }

    // Check if the list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

    // Add to the list (unordered)
    void insertLast(int element) {
        Node* newNode = new Node;
        newNode->data = element;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    // Delete the first element (used in dequeue)
    void deleteFirst() {
        if (!isEmpty()) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count--;

            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            cout << "List is empty. Nothing to delete." << endl;
        }
    }
};

// linkedQueueType class (derived class)
class linkedQueueType : public unorderedLinkedList {
public:
    // Constructor
    linkedQueueType() : unorderedLinkedList() {}

    // Function to enqueue an element
    void enqueue(int element) {
        insertLast(element);
    }

    // Function to dequeue an element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a sentinel value for an empty queue
        }
        int element = head->data;
        deleteFirst();
        return element;
    }

    // Function to check if the queue is empty
    bool isQueueEmpty() const {
        return isEmpty();
    }

    // Function to get the front element of the queue
    int front() const {
        if (!isEmpty()) {
            return head->data;
        } else {
            cout << "Queue is empty. No front element." << endl;
            return -1; // Return a sentinel value for an empty queue
        }
    }
};

int main() {
    linkedQueueType queue;

    // Enqueue elements
    cout << "Enqueuing 10, 20, and 30..." << endl;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display the front element
    cout << "Front element: " << queue.front() << endl;

    // Dequeue elements
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    // Display the front element after dequeuing
    cout << "Front element: " << queue.front() << endl;

    // Dequeue the last element
    cout << "Dequeued: " << queue.dequeue() << endl;

    // Try to dequeue from an empty queue
    cout << "Dequeued: " << queue.dequeue() << endl;

    // Check if the queue is empty
    if (queue.isQueueEmpty()) {
        cout << "Queue is empty." << endl;
    }

    return 0;
}
