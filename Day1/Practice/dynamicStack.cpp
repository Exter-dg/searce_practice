/*
 * Dynamic Stack - using array
 */

#include <bits/stdc++.h>

using namespace std;

class Stack {

    // private members
    int *arr;
    int top;
    int size;

    // public members
public:
    void push(int value);
    void pop();
    void printStack();
    void increaseStackSize();

    Stack() {
        top = 0;
        size = 2;
        arr = new int[2];
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
        cout << "\nStack Overflow!!! Increasing the size.";
        increaseStackSize();
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

void Stack::increaseStackSize() {
    // double the size
    size*=2;
    // create a new array of new size
    int *temp = new int[size];
    //copy data to new array
    for(int i=0;i<top;i++)
        temp[i] = arr[i];
    //assign temp to arr
    arr = temp;
}

int main() {
    Stack st;
    st.push(1);
    st.push(2);
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