/*
 * Static Stack - using array
 */

#include <bits/stdc++.h>

using namespace std;

class Stack {

    // private members
    int arr[5];
    int top;
    int size;

    // public members
public:
    void push(int value);
    void pop();
    void printStack();

    Stack() {
        top = 0;
        size = 5;
    }

    int peek() {
        if (top == 0) {
            cout << "\nStack is Empty!!!";
            return 0;
        }
        return arr[top - 1];
    }
};

void Stack::push(int value) {
    // if stack is full
    if (top == size) {
        cout << "\nStack Overflow!!!";
        return;
    }
    arr[top++] = value;
}

void Stack::pop() {
    // if stack is empty
    if (top == 0) {
        cout << "\nStack Underflow!!!";
        return;
    }
    top--;
}

void Stack::printStack() {
    // if stack is empty
    if (top == 0) {
        cout << "\nStack Empty!!!";
        return;
    }
    cout << "\nStack: ";
    for (int i = top - 1; i >= 0; i--)
        cout << arr[i] << " ";
}

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    cout << "\nTop of the stack is: " << st.peek();
    st.printStack();
    st.pop();
    st.printStack();
    st.pop();
    st.printStack();
    st.pop();

    return 0;
}