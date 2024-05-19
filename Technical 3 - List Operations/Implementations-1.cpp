#include <iostream>
#include <list>
#include "list_operations.h"

using namespace std;
struct Node {
    int data;
    struct Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }
    
    // Inserts an element at the beginning of the list
    void insertAtBeginning(int val) {
   		Node* newNode = new Node;
   		newNode->data = val;
   		newNode->next = head;
   		
   		head = newNode;
    }
    
    // Inserts an element at a specific position
    void insertAfter(int val,int pos) {
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            return;
        }
        temp = temp->next;
    }
    Node* newNode = new Node;
    newNode->data = val;
    if(temp == NULL) { // If position is at the end of the list
        newNode->next = NULL;
        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

    // Inserts an element at the end of the list
    void insert(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    // Removes the element at a specified location from a non-empty list
    void removeAt(int pos) {
        Node* temp1 = head;
        if (pos == 1) {
            head = temp1->next;
            delete temp1;
            return;
        }
        for (int i = 1; i < pos - 1; i++) {
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
    
    // Searches for an element in the list
    bool search(int val) {
  		Node* current = head;
  		while(current != NULL) {
  			if(current->data == val){
  				return true;
			  }
			  current = current->next;
		  }
		  return false;
    }

	// Returns the number of elements in the list
    int getSize() {
    	int count = 0;
    	Node* temp = head;
    	while (temp != NULL) {
    		++count;
    		temp = temp->next;
		}
		return count;
    }

    // Returns true if the list is empty, otherwise returns false
    bool isEmpty() {
        return head == NULL;
    }

    // Returns true if the list is full, otherwise returns false
    bool isFull() {
    	return false; // linked lists grow dynamically, therefore never reaching a max capacity.
    }

    // Displays the elements in the list
    void printList() {
		Node* temp = head;
		while(temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
