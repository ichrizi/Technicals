#include "tree.h"

Node::Node(int key) {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
}

BST::BST() {
    this->root = nullptr;
}

void BST::insertNode(Node*& node, int key) {
    if (node == nullptr) {
        node = new Node(key);
        return;
    }
    if (key < node->key) {
        insertNode(node->left, key);
    } else if (key > node->key) {
        insertNode(node->right, key);
    }
}

Node* BST::searchNode(Node* node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    } else if (key < node->key) {
        return searchNode(node->left, key);
    } else {
        return searchNode(node->right, key);
    } 
}

Node* BST::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* BST::deleteNode(Node*& node, int key) {
    if (node == nullptr) {
        return node;
    }
    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}

void BST::inorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->left);
    std::cout << node->key << " ";
    inorderTraversal(node->right);
}

void BST::preorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->key << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void BST::postorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->key << " ";
}

void BST::displayBST(Node* node, int space) {
    if (node == nullptr) {
        return;
    }
    space += 5;
    displayBST(node->right, space);
    std::cout << std::endl;
    for (int i = 5; i < space; i++) {
        std::cout << " ";
    }
    std::cout << node->key << "\n";
    displayBST(node->left, space);
}

void BST::insert(int key) {
    insertNode(this->root, key);
}

Node* BST::search(int key) {
    return searchNode(this->root, key);
}

void BST::remove(int key) {
    deleteNode(this->root, key);
}

void BST::inorder() {
    inorderTraversal(this->root);
    std::cout << std::endl;
}

void BST::preorder() {
    preorderTraversal(this->root);
    std::cout << std::endl;
}

void BST::postorder() {
    postorderTraversal(this->root);
    std::cout << std::endl;
}

void BST::display() {
    displayBST(this->root, 0);
}
