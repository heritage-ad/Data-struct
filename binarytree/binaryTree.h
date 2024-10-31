#ifndef H_binaryTree
#define H_binaryTree

#include<iostream>
using namespace std;

// Node structure definition
template<class elemType>
struct binaryTreeNode {
    elemType info;
    binaryTreeNode<elemType> *llink;
    binaryTreeNode<elemType> *rlink;
};

// Binary tree class definition
template<class elemType>
class binaryTreeType {
public:
    binaryTreeType();                          // Constructor
    ~binaryTreeType();                         // Destructor

    void insert(const elemType &newItem);      // Insert node
    int singleParent() const;                  // Count single-parent nodes
    void inorderTraversal() const;             // Inorder traversal

protected:
    binaryTreeNode<elemType> *root;

private:
    int singleParent(binaryTreeNode<elemType> *p) const;  // Helper for singleParent count
    void inorder(binaryTreeNode<elemType> *p) const;      // Helper for inorder traversal
    void destroy(binaryTreeNode<elemType>* &p);           // Helper to destroy tree
};

// Constructor initializes root to NULL
template<class elemType>
binaryTreeType<elemType>::binaryTreeType() {
    root = NULL;
}

// Destructor clears memory
template<class elemType>
binaryTreeType<elemType>::~binaryTreeType() {
    destroy(root);
}

// Insert function
template<class elemType>
void binaryTreeType<elemType>::insert(const elemType &newItem) {
    binaryTreeNode<elemType>* newNode = new binaryTreeNode<elemType>();
    newNode->info = newItem;
    newNode->llink = newNode->rlink = NULL;

    if (root == NULL) {
        root = newNode;
    } else {
        binaryTreeNode<elemType>* current = root;
        binaryTreeNode<elemType>* parent = NULL;

        while (current != NULL) {
            parent = current;
            if (newItem < current->info)
                current = current->llink;
            else
                current = current->rlink;
        }

        if (newItem < parent->info)
            parent->llink = newNode;
        else
            parent->rlink = newNode;
    }
}

// Inorder traversal helper
template<class elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType> *p) const {
    if (p != NULL) {
        inorder(p->llink);
        cout << p->info << " ";
        inorder(p->rlink);
    }
}

// Public inorder traversal function
template<class elemType>
void binaryTreeType<elemType>::inorderTraversal() const {
    inorder(root);
}

// Helper function to destroy tree recursively
template<class elemType>
void binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>* &p) {
    if (p != NULL) {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

// Single-parent count helper function
template<class elemType>
int binaryTreeType<elemType>::singleParent(binaryTreeNode<elemType> *p) const {
    if (p == NULL)  // Base case: empty subtree
        return 0;

    // Check if node has only one child
    if ((p->llink == NULL && p->rlink != NULL) || (p->llink != NULL && p->rlink == NULL))
        return 1 + singleParent(p->llink) + singleParent(p->rlink);
    else
        return singleParent(p->llink) + singleParent(p->rlink);
}

// Public single-parent count function
template<class elemType>
int binaryTreeType<elemType>::singleParent() const {
    return singleParent(root);
}

#endif 
