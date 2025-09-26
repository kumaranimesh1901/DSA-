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

int height(Node* root) { // time-complx=O(n2)
    if (root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int diameterOfBinaryTree(Node* root) {
    if (root == NULL) return 0;

    int leftDiam = diameterOfBinaryTree(root->left);
    int rightDiam = diameterOfBinaryTree(root->right);
    int currDiam = height(root->left) + height(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

int main() {
    
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root = build_Tree(preorder);

    cout << "Diameter of the tree: " << diameterOfBinaryTree(root) << endl;

    return 0;
}


/*  

time-complx=O(n)




int ans=0;
int height(TreeNode* root)
{
    if(root==NULL) return 0;
    
        int leftht=height(root->left);
        int rightht=height(root->right);
        ans=max(ans,leftht+rightht);    current diameter of root node

        return max(leftht,rightht)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        height(root);

        return ans;
        
    }*/