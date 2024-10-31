/* Program name: Binary Search Tree
Author: Heritage Adigun
Date last updated: 11/02/2024
Purpose: A program that implements a B-Tree insert function.*/


#include <iostream>

// B-Tree Node Structure
struct BTreeNode {
    int *keys;       // Array to store keys
    int t;           // Minimum degree (defines the range for number of keys)
    BTreeNode **child; // Array of child pointers
    int n;           // Current number of keys
    bool leaf;       // True if node is a leaf, false otherwise
};

// Function to create a new B-Tree node
BTreeNode* createNode(int t, bool leaf) {
    BTreeNode* newNode = new BTreeNode;
    newNode->t = t;
    newNode->leaf = leaf;
    newNode->keys = new int[2*t - 1];
    newNode->child = new BTreeNode *[2*t];
    newNode->n = 0;
    return newNode;
}

// Function to split a child node of a B-Tree node
void splitChild(BTreeNode* parentNode, int index, BTreeNode* childNode) {
    int t = childNode->t;
    BTreeNode* newNode = createNode(t, childNode->leaf);
    newNode->n = t - 1;
  
    // Move the keys from the child node to the new node
    for (int i = 0; i < t-1; i++)
        newNode->keys[i] = childNode->keys[i+t];
  
    // Move the child pointers from the child node to the new node
    if (childNode->leaf == false) {
        for (int i = 0; i < t; i++)
            newNode->child[i] = childNode->child[i+t];
    }
  
    childNode->n = t - 1;
  
    // Adjust child pointers of the parent node
    for (int i = parentNode->n; i >= index+1; i--)
        parentNode->child[i+1] = parentNode->child[i];
  
    parentNode->child[index+1] = newNode;
  
    // Move a key from the child node to the parent node
    for (int i = parentNode->n-1; i >= index; i--)
        parentNode->keys[i+1] = parentNode->keys[i];
  
    parentNode->keys[index] = childNode->keys[t-1];
  
    parentNode->n++;
}

// Function to insert a key into a B-Tree
void insertBTree(BTreeNode* root, int key) {
    int t = root->t;
    if (root->n == 2*t-1) {
        BTreeNode* newNode = createNode(t, false);
        newNode->child[0] = root;
        splitChild(newNode, 0, root);
        int i = 0;
        if (newNode->keys[0] < key)
            i++;
        insertBTree(newNode->child[i], key);
        root = newNode;
    }
    else
        insertNonFull(root, key);
}

// Function to insert a key into a non-full B-Tree node
void insertNonFull(BTreeNode* node, int key) {
    int i = node->n-1;
    if (node->leaf == true) {
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i+1] = node->keys[i];
            i--;
        }
        node->keys[i+1] = key;
        node->n++;
    }
    else {
        while (i >= 0 && node->keys[i] > key)
            i--;
  
        if (node->child[i+1]->n == 2*node->t-1) {
            splitChild(node, i+1, node->child[i+1]);
            if (node->keys[i+1] < key)
                i++;
        }
        insertNonFull(node->child[i+1], key);
    }
}

int main() {
    BTreeNode* root = createNode(3, true);
    insertBTree(root, 10);
    insertBTree(root, 20);
    insertBTree(root, 30);
    insertBTree(root, 40);
    insertBTree(root, 50);
    insertBTree(root, 60);

    return 0;
}