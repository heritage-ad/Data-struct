/* Program name: Binary Search Tree
Author: Heritage Adigun
Date last updated: 11/02/2024
Purpose: A program that implements an AVL Tree insert function.*/


#include <iostream>
using namespace std;

// Define the structure of an AVL Tree node
struct AVLNode {
    int key;            // Value of the node
    AVLNode* left;      // Pointer to the left child
    AVLNode* right;     // Pointer to the right child
    int height;         // Height of the node

    // Constructor to initialize a new node
    AVLNode(int key) : key(key), left(nullptr), right(nullptr), height(1) {}
};

// Helper function to get the height of a node
int getHeight(AVLNode* node) {
    return node ? node->height : 0;  // Return height or 0 if the node is null
}

// Calculate the balance factor of a node
int getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Perform a right rotation on the subtree rooted with 'y'
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;          // 'x' becomes the new root of the rotated subtree
    AVLNode* T2 = x->right;        // Temporary pointer for subtree swap

    x->right = y;                  // Rotate
    y->left = T2;

    // Update heights of the nodes involved in the rotation
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;                      // Return the new root of the subtree
}

// Perform a left rotation on the subtree rooted with 'x'
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;         // 'y' becomes the new root of the rotated subtree
    AVLNode* T2 = y->left;         // Temporary pointer for subtree swap

    y->left = x;                   // Rotate
    x->right = T2;

    // Update heights of the nodes involved in the rotation
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;                      // Return the new root of the subtree
}

// Insert a new key into the AVL Tree and balance it
AVLNode* insert(AVLNode* node, int key) {
    // Step 1: Perform standard BST insert
    if (!node)  // If the node is null, create a new node
        return new AVLNode(key);

    // Recursive insert based on BST properties
    if (key < node->key)           // Insert in left subtree
        node->left = insert(node->left, key);
    else if (key > node->key)      // Insert in right subtree
        node->right = insert(node->right, key);
    else                           // Equal keys are not allowed in this AVL Tree
        return node;

    // Step 2: Update height of this node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Step 3: Get the balance factor to check if this node is unbalanced
    int balance = getBalance(node);

    // If node becomes unbalanced, there are 4 possible cases:

    // Left Left Case (Single Right Rotation)
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Right Right Case (Single Left Rotation)
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Left Right Case (Double Rotation: Left then Right)
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left); // Left rotation on left child
        return rotateRight(node);            // Right rotation on node
    }

    // Right Left Case (Double Rotation: Right then Left)
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right); // Right rotation on right child
        return rotateLeft(node);                // Left rotation on node
    }

    // Return the unchanged node pointer
    return node;
}
