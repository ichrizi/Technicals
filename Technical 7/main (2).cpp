#include <iostream>
#include "tree.h"

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal: ";
    bst.inorder();

    std::cout << "Preorder traversal: ";
    bst.preorder();

    std::cout << "Postorder traversal: ";
    bst.postorder();

    std::cout << "Displaying BST:\n";
    bst.display();

    Node* searchedNode = bst.search(60);
    if (searchedNode == nullptr) {
        std::cout << "Node not found in the BST\n";
    } else {
        std::cout << "Node found in the BST: " << searchedNode->key << std::endl;
    }

    bst.remove(30);

    std::cout << "Inorder traversal after deleting a node: ";
    bst.inorder();

    return 0;
}
