/* Program name: Binary Search Tree
Author: Heritage Adigun
Date last updated: 10/31/2024
Purpose: A program that takes as a parameter a pointer to the root node of a binary tree and returns the number of leaves in a binary tree. */

#include "binaryTree.h"
#include <iostream>
using namespace std;

int main() {
    binaryTreeType<int> ob;
    int numNodes, value;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        ob.insert(value);
    }

    cout << "Inorder traversal: ";
    ob.inorderTraversal();
    cout << "\nNumber of leaves: " << ob.treeLeavesCount() << endl;

    return 0;
}