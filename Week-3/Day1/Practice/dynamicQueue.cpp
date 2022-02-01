/*
 * Dynamic Queue - using array
 * Front will point to the first element
 * Rear will point to the last element
 */

#include <bits/stdc++.h>

using namespace std;

class Queue {

    // private members
    int *arr;
    int front;
    int rear;
    int size;

    // public members
public:
    void enqueue(int value);
    void dequeue();
    void printQueue();
    void increaseQueueSize();

    Queue() {
        front = rear = -1;
        size = 2;
        arr = new int[size];
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
        cout << "\nQueue is Full!!! Increasing size";
        increaseQueueSize();
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

void Queue::increaseQueueSize() {
    
    // create a new array of new size
    int *temp = new int[size*2];
    //copy data to new array
    int itr = front;
    int k = 0;
    do {
        temp[k++] = arr[itr];
    } while ((itr++)%size != rear);
    //assign temp to arr
    arr = temp;
    
    // Update front, rear, size
    front = 0;
    rear = k-1;
    size*=2;

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
        cout << arr[temp] << " ";
    } while ((temp++)%size != rear);
}

int main() {
    Queue q;
    q.printQueue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "\nFront: " << q.peek();
    q.printQueue();
    q.dequeue();
    q.printQueue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(1);
    q.printQueue();
    q.enqueue(2);
    q.enqueue(3);
    q.printQueue();

    return 0;
}