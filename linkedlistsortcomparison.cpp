/* Program name: Time Comparison
Author: Heritage Adigun
Date last updated: 10/29/2024
Purpose: A program that compares the time between selection and merge. */



#include <iostream>
#include <chrono>
#include <vector>
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

void testSortingAlgorithms(vector<int> sizes)
{
    for (int n : sizes)
    {
        Node *head1 = NULL, *head2 = NULL;

        for (int i = 0; i < n; i++)
        {
            int value = rand() % 1000;
            insert(&head1, value);
            insert(&head2, value);
        }

        auto start = high_resolution_clock::now();
        mergeSort(&head1);
        auto stop = high_resolution_clock::now();
        auto mergeDuration = duration_cast<microseconds>(stop - start).count();


        start = high_resolution_clock::now();
        selectionSort(head2);
        stop = high_resolution_clock::now();
        auto selectionDuration = duration_cast<microseconds>(stop - start).count();

        cout << "List size: " << n << endl;
        cout << "Merge Sort time: " << mergeDuration << " microseconds" << endl;
        cout << "Selection Sort time: " << selectionDuration << " microseconds" << endl;
        cout << "-----------------------------------" << endl;
    }

}

int main()
{
    vector<int> listSizes = {1, 10, 100, 1000};
    testSortingAlgorithms(listSizes);

    return 0;
}
