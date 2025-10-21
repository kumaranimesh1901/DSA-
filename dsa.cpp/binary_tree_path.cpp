#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Binary Tree Node
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

// Build tree from preorder traversal (-1 = NULL)
static int idx = -1;
Node* build_Tree(vector<int> preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1)
        return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = build_Tree(preorder);
    root->right = build_Tree(preorder);
    return root;
}


class Solution {
public:
    void allpath(Node* root, string path, vector<string>& ans) {
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        if (root->left)
            allpath(root->left, path + "->" + to_string(root->left->data), ans);

        if (root->right)
            allpath(root->right, path + "->" + to_string(root->right->data), ans);
    }

    vector<string> binaryTreePaths(Node* root) {
        vector<string> ans;
        if (!root) return ans;

        string path = to_string(root->data);
        allpath(root, path, ans);
        return ans;
    }
};

int main() {
    vector<int> preorder = {1, 2, -1, 5, -1, -1, 3, -1, -1};
    Node* root = build_Tree(preorder);

    Solution s;
    vector<string> paths = s.binaryTreePaths(root);

    cout << "All Root-to-Leaf Paths:\n";
    for (string p : paths)
        cout << p << endl;

    return 0;
}
