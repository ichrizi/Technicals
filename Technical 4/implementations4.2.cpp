#include "head.h"

template <typename T>
Stack<T>::Stack(int size) {
    n = size;
    a = new T[n];
    top = -1;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] a;
}

template <typename T>
void Stack<T>::push(T element) {
    if (top == n - 1) {
        cout << "Stack is full\n";
    } else {
        ++top;
        a[top] = element;
    }
}

template <typename T>
T Stack<T>::pop() {
    if (top == -1) {
        cout << "Stack is empty. No elements to pop\n";
        return -1; // Use a default value or handle T type appropriately
    } else {
        T poppedElement = a[top];
        --top;
        return poppedElement;
    }
}

template <typename T>
void Stack<T>::display() {
    if (top == -1) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack elements are: ";
        for (int i = 0; i <= top; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void Stack<T>::operations() {
    int ch;
    while (true) {
        cout << "\nStack Operations Menu\n1- Push an element\n2- Pop\n3- Display the elements\n4- Exit\nSelect an operation: ";
        cin >> ch;
        switch (ch) {
            case 1: {
                T element;
                cout << "Enter the element to push: ";
                cin >> element;
                push(element);
                break;
            }
            case 2: {
                T val = pop();
                if (val != -1) { // Adjust this check based on T type
                    cout << "Popped element: " << val << endl;
                }
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                cout << "Invalid choice.\n";
            }
        }
    }
}

// Explicitly instantiate templates
template class Stack<int>;
template class Stack<float>;
template class Stack<double>;

