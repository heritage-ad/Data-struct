/* Program name: Selection Sort Linked List
Author: Heritage Adigun
Date last updated: 10/28/2024
Purpose: A program that uses selection sort for linked list. */



#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node
{
    int data;
    Node *next;
};

// Function to insert a new node at the beginning of linked list
void insert(Node **head, int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

// Function to print the linked list
void print(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to perform selection sort on linked list
void selectionSort(Node *head)
{
    Node *i, *j, *minNode;
    int temp;

    for (i = head; i->next != NULL; i = i->next)
    {
        minNode = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (j->data < minNode->data)
            {
                minNode = j;
            }
        }
        temp = i->data;
        i->data = minNode->data;
        minNode->data = temp;
    }
}

// Main function to test selection sort on linked list
int main()
{
    Node *head = NULL;

    // Insert 1000 random numbers into the linked list
    for (int i = 0; i < 1000; i++)
    {
        insert(&head, rand() % 1000);
    }

    // Perform selection sort on the linked list and measure the time taken
    auto start = high_resolution_clock::now();
    selectionSort(head);
    auto stop = high_resolution_clock::now();

    // Print the time taken to perform selection sort on linked list
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by selection sort: " << duration.count() << " milliseconds" << endl;

    return 0;
}