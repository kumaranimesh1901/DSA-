#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() {
        head = NULL;
    }

    void push_back(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void makeCycle(int pos) {
        // Connect last node to the node at position pos (0-based)
        if (head == NULL) return;

        ListNode* temp = head;
        ListNode* cycleNode = NULL;
        int idx = 0;

        while (temp->next != NULL) {
            if (idx == pos) cycleNode = temp;
            temp = temp->next;
            idx++;
        }
        if (cycleNode != NULL) {
            temp->next = cycleNode; // last node points to pos-th node
        }
    }

    void print() {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL && count < 20) { 
            // limit printing to avoid infinite loop if cycle exists
            cout << temp->val << " ";
            temp = temp->next;
            count++;
        }
        cout << endl;
    }
};

bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    LinkedList ll;

    // Build linked list using push_back
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    cout << "List: ";
    ll.print();

    cout << "Checking cycle in normal list: ";
    cout << (hasCycle(ll.head) ? "Cycle Found" : "No Cycle") << "\n";

    // Create cycle (connect last node to node at position 1, i.e. value=2)
    ll.makeCycle(1);

    cout << "Checking cycle after creating a loop: ";
    cout << (hasCycle(ll.head) ? "Cycle Found" : "No Cycle") << "\n";

    return 0;
}
