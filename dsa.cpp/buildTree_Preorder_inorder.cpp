#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        int preidx = 0;
        return build(preorder, inorderIndex, preidx, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorderIndex,
                    int& preidx, int left, int right) {
        if (left > right) return nullptr;

        int val = preorder[preidx++];
        TreeNode* root = new TreeNode(val);

        int mid = inorderIndex[val];

        root->left = build(preorder, inorderIndex, preidx, left, mid - 1);
        root->right = build(preorder, inorderIndex, preidx, mid + 1, right);

        return root;
    }
};


void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "-1 "; 
            }
        }
        cout << endl;
    }
}


int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Level Order Traversal of Constructed Tree:\n";
    printLevelOrder(root);

    return 0;
}
