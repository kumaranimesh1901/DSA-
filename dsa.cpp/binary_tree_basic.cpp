#include<bits/stdc++.h>
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
static int idx=-1;
Node* build_Tree(vector<int> preorder)
{
    idx++;
    if(preorder[idx]==-1) return NULL;

    Node* root=new Node(preorder[idx]);
    root->left= build_Tree(preorder);
    root->right=build_Tree(preorder);
    return root;
}

//PRE-ORDER

void preOrder(Node* root)
{
    if(root==NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//IN-ORDER

void inorder(Node* root)
{
    if(root==NULL) return;
    
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    
}

//POST-ORDER

void postOrder(Node* root)
{
    if(root==NULL) return;

    postOrder(root->left);
    postOrder(root->right);
     cout<<root->data<<" ";
}

void Level_order(Node* root)
{
    queue<Node*>q;

    q.push(root);
    q.push(NULL);
    while(q.size()>0)
    {
        Node* curr=q.front();
        q.pop();

        if(curr==NULL) {
            if(!q.empty())
            {
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else break;

        }
        
        cout<<curr->data << " ";

        if(curr->left != NULL)
        {
            q.push(curr->left);
        }
         if(curr->right != NULL)
        {
            q.push(curr->right);
        }

    }
    
    
}



int main()
{
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

   Node* root= build_Tree(preorder);

   Level_order(root);
   cout<<endl;
   

    return 0;
}   