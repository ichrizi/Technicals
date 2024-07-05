#include <iostream>
#include "Datas.h"
#include "Implementation.cpp"
using namespace std;

int main() {
    Queue q;
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(8);
    q.displayQueue();
    cout << "Front element: " << q.getFront() << endl;
    q.dequeue();
    q.dequeue();
    q.displayQueue();
    cout << "Front element: " << q.getFront() << endl;
    return 0;
}
