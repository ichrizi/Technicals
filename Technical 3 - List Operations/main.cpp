#include <iostream>
#include <list>
#include <limits>
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
	if (pos < 0) {
void insertAfter(int val, int pos); // Add a semicolon at the end of the function declaration

void insertAfter(int val, int pos) {
    if (pos < 0) {
        cout << "Invalid position, must be a non-negative integer." << endl;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            return;
        }
        temp = temp->next;
    }

    Node* newNode = new Node;
    // Rest of the code...
}
    newNode->data = val;

    if (temp == NULL) { // If position is at the end of the list
        newNode->next = NULL;
        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
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

int main() {
    LinkedList list;
    int choice, position, data;

    do {
    	system("cls");
        cout << "\nList Operations:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Remove at position\n";
        cout << "5. Search\n";
        cout << "6. Display list\n";
        cout << "7. Get size\n";
        cout << "8. Check if list is empty\n";
        cout << "9. Check if list is full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "invalid input. please enter numbers 1-0: ";
			cin  >> choice;
		}
        switch (choice) {
            case 1:
                cout << "Enter data to be inserted at beginning: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;

            case 2:
                cout << "Enter data to be inserted at end: ";
                cin >> data;
                list.insert(data);
                break;

            case 3:
                cout << "Enter data to be inserted: ";
                cin >> data;
                cout << "Enter position to insert data: ";
                cin >> position;
                list.insertAfter(data, position);
                break;

            case 4:
                cout << "Enter position of data to be removed: ";
                cin >> position;
                list.removeAt(position);
                break;

            case 5:
                cout << "Enter data to search: ";
                cin >> data;
                if (list.search(data))
                    cout << "Element found in the list\n";
                else
                    cout << "Element not found in the list\n";
                break;

            case 6:
                cout << "Elements in the list are: ";
                list.printList();
                break;

            case 7:
                cout << "Size of the list is: " << list.getSize() << endl;
                break;

            case 8:
                if (list.isEmpty())
                    cout << "List is empty\n";
                else
                    cout << "List is not empty\n";
                break;

            case 9:
                if (list.isFull())
                    cout << "List is full\n";
                else
                    cout << "List is not full\n";
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice, please try again\n";
                break;
        }
        cout << "Press Enter to Continue...";
        cin.ignore();
        cin.get();
    } while (choice != 0);

    return 0;
	}


