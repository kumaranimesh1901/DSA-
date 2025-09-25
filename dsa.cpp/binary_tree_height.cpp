#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data =val;
        left=right=NULL;
    }
};

int idx=-1;

Node* build_Tree(vector<int> preorder)
{
    idx++;
    if(preorder[idx]==-1) return NULL;

    Node* root=new Node(preorder[idx]);
    root->left= build_Tree(preorder);
    root->right=build_Tree(preorder);
    return root;
}

// height

int height(Node* root)
{
    if(root==NULL) return 0;

    int left_height=height(root->left);
    int right_height=height(root->right);
    return max(left_height,right_height)+1;

}

//count Node

int count(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftCount=count(root->left);
    int rightCount=count(root->right);
    return leftCount+rightCount+1;
}

//SUM of Nodes

int sum(Node* root)
{
    if(root==NULL) return 0;

    int left_sum=sum(root->left);
    int right_sum=sum(root->right);
    return right_sum+left_sum+root->data;
}

int main()
{
   vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
   Node* root = build_Tree(preorder);

   cout<<"sum:"<<sum(root);
}
