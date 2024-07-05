#ifndef TREE_H
#define TREE_H

#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node(int key);
};

class BST {
private:
    Node* root;

    void insertNode(Node*& node, int key);
    Node* searchNode(Node* node, int key);
    Node* findMin(Node* node);
    Node* deleteNode(Node*& node, int key);
    void inorderTraversal(Node* node);
    void preorderTraversal(Node* node);
    void postorderTraversal(Node* node);
    void displayBST(Node* node, int space);

public:
    BST();
    void insert(int key);
    Node* search(int key);
    void remove(int key);
    void inorder();
    void preorder();
    void postorder();
    void display();
};

#endif // TREE_H
