#include <bits/stdc++.h>
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

int idx = -1;

Node* build_Tree(vector<int>& preorder) {
    idx++;
    if (preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = build_Tree(preorder);
    root->right = build_Tree(preorder);
    return root;
}

bool isIdentical(Node* root, Node* subRoot) {
    if (root == NULL || subRoot == NULL)
        return root == subRoot;

    bool isleft = isIdentical(root->left, subRoot->left);
    bool isright = isIdentical(root->right, subRoot->right);

    return isleft && isright && root->data == subRoot->data;
}
int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> subRoot = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    idx = -1;
    Node* root = build_Tree(preorder);

    idx = -1; // reset before building again
    Node* subroot = build_Tree(subRoot);

    cout << "Is subtree: " << (isIdentical(root, subroot) ? "Yes" : "No") << endl;
}
