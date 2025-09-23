#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert node at end
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Reverse the linked list
    void reverseList() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next; // save next node
            curr->next = prev; // reverse the link
            prev = curr;       // move prev forward
            curr = next;       // move curr forward
        }
        head = prev; // update head to new first node
    }

    // Print the linked list
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;

    // Build list: 1 -> 2 -> 3 -> 4 -> 5
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    cout << "Original List: ";
    ll.print();

    ll.reverseList();

    cout << "Reversed List: ";
    ll.print();

    return 0;
}
