/*
 * Static Queue - using array
 * Front will point to the first element
 * Rear will point to the last element
 */

#include <bits/stdc++.h>

using namespace std;

class Queue {

    // private members
    int arr[5];
    int front;
    int rear;
    int size;

    // public members
public:
    void enqueue(int value);
    void dequeue();
    void printQueue();

    Queue() {
        front = rear = -1;
        size = 5;
    }

    int peek() {
        if (front == -1) {
            cout << "\nQueue is Empty!!!";
            return 0;
        }
        return arr[front];
    }
};

void Queue::enqueue(int value) {
    // if queue is full
    if ((rear + 1) % size == front) {
        cout << "\nQueue is Full!!!";
        return;
    }

    // if queue is empty
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % size;

    arr[rear] = value;
}

void Queue::dequeue() {
    // if queue is empty
    if (front == -1) {
        cout << "\nQueue is Empty!!!";
        return;
    }

    // if the queue only has a single element
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
}

void Queue::printQueue() {
    // if stack is empty
    if (front == -1) {
        cout << "\nQueue Empty!!!";
        return;
    }

    cout << "\nQueue: ";
    int temp = front;
    do {
        cout << arr[temp]<<" ";
    } while ((temp++)%size != rear);
}

int main() {
    Queue q;
    q.printQueue();
    q.enqueue(1);
    q.enqueue(2);
    cout<<"\nFront: "<<q.peek();
    q.printQueue();
    q.dequeue();
    q.printQueue();
    q.dequeue();
    q.dequeue();
    return 0;
}