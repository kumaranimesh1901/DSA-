#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int val) {
        data = val;
        next = prev = child = NULL;
    }
};

// Function to flatten multilevel doubly linked list
Node* flatten(Node* head) {
    if (head == NULL) return head;

    Node* curr = head;

    while (curr != NULL) {
        if (curr->child != NULL) {
            Node* next = curr->next;

            // Flatten the child list
            Node* childHead = flatten(curr->child);

            // Connect curr with child
            curr->next = childHead;
            childHead->prev = curr;
            curr->child = NULL;

            // Find the tail of the child list
            Node* tail = childHead;
            while (tail->next != NULL) {
                tail = tail->next;
            }

            // Connect tail with next (if exists)
            if (next != NULL) {
                tail->next = next;
                next->prev = tail;
            }

            // Move curr to tail
            curr = tail;
        }
        curr = curr->next;
    }

    return head;
}

// Helper function to print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create main list: 1 -> 2 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(5);
    head->next->next->prev = head->next;

    // Create child list: 3 -> 4 (child of 2)
    Node* child1 = new Node(3);
    child1->next = new Node(4);
    child1->next->prev = child1;

    head->next->child = child1; // Attach child to node 2

    cout << "Original multilevel list (level-wise):" << endl;
    cout << "Level 1: 1 2 5" << endl;
    cout << "Level 2 (child of 2): 3 4" << endl;

    head = flatten(head);

    cout << "\nFlattened list:" << endl;
    printList(head);

    return 0;
}
