#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

// Build tree from preorder traversal where -1 represents NULL
Node* build_Tree(vector<int>& preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1)
        return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = build_Tree(preorder);
    root->right = build_Tree(preorder);
    return root;
}

class Solution {
    Node* nextright = NULL;
public:
    void flatten(Node* root) {
        if (root == NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextright;
        nextright = root;
    }
};


void printList(Node* root) {
    while (root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
  
    vector<int> preorder = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, 6, -1, -1};

    idx = -1; 
    Node* root = build_Tree(preorder);

    Solution obj;
    obj.flatten(root);

    cout << "Flattened binary tree to linked list: ";
    printList(root);

    return 0;
}
