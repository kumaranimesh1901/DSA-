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

int sumTree(Node* root)
{
    if(root==NULL) return 0;
    int left_Sum=sumTree(root->left);
    int right_Sum=sumTree(root->right);
    root->data+=left_Sum+right_Sum;
    return root->data;
}
void preorderTraversal(Node *root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);

}

int main()
{
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=build_Tree(preorder);

    sumTree(root);

    cout<<"preorderTraversal sum tree";
    preorderTraversal(root);
    
}