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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }
        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    // Create two sorted linked lists
    vector<int> list1 = {1, 3, 5};
    vector<int> list2 = {2, 4, 6};

    ListNode* head1 = createList(list1);
    ListNode* head2 = createList(list2);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Solution s;
    ListNode* mergedHead = s.mergeTwoLists(head1, head2);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}
