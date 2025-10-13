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

static int idx = -1;

// Build tree from preorder traversal where -1 represents NULL
Node* build_Tree(vector<int> preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = build_Tree(preorder);
    root->right = build_Tree(preorder);
    return root;
}

// Find LCA using node 
Node* lowestCommonAncestor(Node* root, int p, int q) {
    if (root == NULL) return NULL;

    if (root->data == p || root->data == q)
        return root;

    Node* left_LCA = lowestCommonAncestor(root->left, p, q);
    Node* right_LCA = lowestCommonAncestor(root->right, p, q);

    if (left_LCA && right_LCA)
        return root;

    return (left_LCA != NULL) ? left_LCA : right_LCA;
}

int main() {
    vector<int> preorder = {1, 2, 7, -1, -1, 4, -1, -1, 5, -1, -1};
    Node* root = build_Tree(preorder);

    Node* lca = lowestCommonAncestor(root, 4, 5);

    if (lca)
        cout << "LCA of 4 and 5 is: " << lca->data << endl;
    else
        cout << "Nodes not found." << endl;

    return 0;
}
