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

Node *deleteNode(Node *head, int val) {
    if(head == NULL)
        return head;

    // if the value to be deleted is the first node
    if(head->data == val) 
        return head->next;

    Node *curr = head->next;
    Node *prev = head;
    while(curr != NULL) {
        if(curr->data == val) {
            prev->next = curr->next;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

void printList(Node *temp) {
    if (temp == NULL) {
        cout << "\nList is Empty!";
        return;
    }
    cout << "\nLinked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node *head = NULL;
    head = insertNode(head, 4);
    head = insertNode(head, 18);
    head = deleteNode(head, 18);
    printList(head);

    return 0;
}