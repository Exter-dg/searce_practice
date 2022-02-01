#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int val) {
        data = val;
        next = NULL;
    }
};

/*
 * Create a new node(temp) with data as val.
 * Return new node as head if head is NULL.
 * Iterate to the end of the list and set temp as the next of last node
*/
Node *insertNode(Node *head, int val) {
    Node *temp = new Node(val);
    if (head == NULL)
        return temp;
    else {
        Node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

void printLinkedList(Node *temp) {
    if (temp == NULL) {
        return;
    }
    cout<<"\nLinked List:\n";
    while (temp != NULL) {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}

int main() {
    Node *head = NULL;
    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int data;
        cin>>data;
        head = insertNode(head, data);
    }
    printLinkedList(head);

    return 0;
}