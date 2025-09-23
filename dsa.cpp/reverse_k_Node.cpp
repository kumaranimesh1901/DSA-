#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) 
    {
        val=x;
        next=NULL;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while (count < k) {
            if (temp == NULL) return head; 
            temp = temp->next;
            count++;
        }

        ListNode* prevNode = reverseKGroup(temp, k);

        temp = head;
        count = 0;
        while (count < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;
            count++;
        }

        return prevNode;
    }
};

ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    
    vector<int> vals = {1, 2, 3, 4, 5};
    int k = 3;

    ListNode* head = createList(vals);

    cout << "Original List:" << endl;
    printList(head);

    Solution sol;
    head = sol.reverseKGroup(head, k);

    cout << "\nReversed in groups of " << k << ":" << endl;
    printList(head);

    return 0;
}
