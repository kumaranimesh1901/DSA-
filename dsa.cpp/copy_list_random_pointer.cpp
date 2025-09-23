#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        unordered_map<Node*, Node*> m;

        Node* newhead = new Node(head->val);
        Node* oldtemp = head->next;
        Node* newtemp = newhead;
        m[head] = newhead;

        while (oldtemp != NULL) {
            Node* copyNode = new Node(oldtemp->val);
            m[oldtemp] = copyNode;

            newtemp->next = copyNode;

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        oldtemp = head;
        newtemp = newhead;

        while (oldtemp != NULL) {
            if (oldtemp->random != NULL)
                newtemp->random = m[oldtemp->random];
            else
                newtemp->random = NULL;

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        return newhead;
    }
};

// Helper function to print list (val + random->val)
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node(" << temp->val << ")";
        if (temp->random)
            cout << " -> random(" << temp->random->val << ")";
        else
            cout << " -> random(NULL)";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Step 1: Create nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    // Step 2: Link next pointers
    n1->next = n2;
    n2->next = n3;

    // Step 3: Link random pointers
    n1->random = n3;  // 1 -> 3
    n2->random = n1;  // 2 -> 1
    n3->random = NULL; // 3 -> NULL

    cout << "Original List:" << endl;
    printList(n1);

    // Step 4: Copy list
    Solution s;
    Node* copiedHead = s.copyRandomList(n1);

    cout << "\nCopied List:" << endl;
    printList(copiedHead);

    return 0;
}
