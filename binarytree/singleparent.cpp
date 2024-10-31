/* Program name: Binary Search Tree
Author: Heritage Adigun
Date last updated: 10/31/2024
Purpose: A program that return the number of nodes in a binary tree that have only one child.*/


#include "binaryTree.h"
#include <iostream>
using namespace std;

int main() {
    binaryTreeType<int> tree;

    // Insert nodes to create a binary search tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    tree.insert(11);  // Adds some single-parent nodes intentionally

    cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    cout << endl;

    // Count and display single-parent nodes
    cout << "Number of nodes with a single child: " << tree.singleParent() << endl;

    return 0;
}
