/* Program name: Merge Sort Linked List
Author: Heritage Adigun
Date last updated: 10/28/2024
Purpose: A program that uses merge sort for linked list. */

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node
{
    int data;
    Node *next;
};

void insert(Node **head, int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void print(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node *sortedMerge(Node *a, Node *b)
{
    Node *result = NULL;

    if (!a) return b;
    if (!b) return a;

    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void split(Node *source, Node **front, Node **back)
{
    Node *fast, *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(Node **head)
{
    Node *h = *head;
    Node *a, *b;

    if (!h || !h->next)
        return;

    split(h, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *head = sortedMerge(a, b);
}

int main()
{
    Node *head = NULL;

    for (int i = 0; i < 1000; i++)
    {
        insert(&head, rand() % 1000);
    }

    auto start = high_resolution_clock::now();
    mergeSort(&head);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by merge sort: " << duration.count() << " milliseconds" << endl;

    return 0;
}
