#include <iostream>
#include "Datas.h"
using namespace std;

Queue::Queue() {
    front = rear = -1;
    size = 0;
}
bool Queue::isEmpty() {
    if(front == -1){
        return true;
    }else
        return false;
}
bool Queue::isFull() {
    if(rear == MAX_SIZE){
        return true;
    }else
        return false;
}
void Queue::enqueue(int x) {
    if (isFull()) {
        cout << "Error: Queue is full!" << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    arr[rear] = x;
    size++;
}
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Error: Queue is empty!" << endl;
        return -1;
    }   

    int x = arr[front];
    if (front == rear) {
        front = rear = -1;
    }else {
        front++;
    }

    size--;
    return x;
}
int Queue::getSize() {
    return size;
}
void Queue::displayQueue() {
    cout << "The Values in the Queue are: ";
    if (isEmpty()){
        cout << "Queue is empty!";
    }
    else{
        for (int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}
int Queue::getFront() {
    int x = arr[front];
    return x;
}