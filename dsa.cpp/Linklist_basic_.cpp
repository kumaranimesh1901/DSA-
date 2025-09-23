#include <bits/stdc++.h>
using namespace std;

class Node
{
    public :
    int data;
    Node*next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class Linklist
{
Node *head;
Node *tail;

public:
 Linklist()
{
    head=tail=NULL;
}
void push_front(int val)
{
    Node* newNode=new Node(val); //dynamic
  //  Node newNode(val); //static (AS WE COME OUT OF THIS FUNCTION DATA WILL BE DELETED)
  if(head==NULL)
  {
    head=tail=newNode;
    return;
  }
  else
  {
    newNode->next=head;//(*newNode).next=head
    head=newNode;
  }
}

void push_back(int val)
{
  Node *newNode=new Node(val);
  if(head==NULL)
  {
    head=tail=newNode;
    return;
  }
  else
  {
    tail->next=newNode;
    tail=newNode;
  }
}


void pop_front( )
{
  if(head==NULL)
  {
    cout<<"Linklist is empty\n";
    return;
  }
  Node *temp=head;
  head=head->next;
  temp->next=NULL;
}

void pop_back()
{
  if (head==NULL)
  {
    return;
  }
  Node *temp=head;

  while(temp->next!=tail)
  {
    temp=temp->next;
  }
  temp->next=NULL;
  delete tail;
  tail=temp;

}

void Insert(int val,int pos)
{
  if(pos<0)
  {
    cout<<"invalid position"<<" ";
    return;

  }
  if(pos==0)
  {
    push_front(val);
    return;
  }
  Node *temp=head;
  for(int i=0; i < pos-1;i++)
  {
    if(temp==NULL)
    {
      cout<<"invalid position\n";
      return;
    }
    temp=temp->next;
  }
  Node *newNode=new Node(val);
  newNode->next=temp->next;
  temp->next=newNode;
  if(temp==tail)
  {
    tail=newNode;
  }
}

int search(int key)
{
  int idx=0;
  Node *temp=head;
  while(temp!=NULL)
  {
    if(temp->data==key)
    {
      return idx;
    }
    temp=temp->next;
    idx++;
  }
  return -1;
}


void print()
{
  Node*temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;

  }
  cout<<endl;
}
};


int main()
{
  Linklist ll;
  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);

  ll.Insert(4,2);
  cout<<"search idx="<<ll.search(4)<<"\n";
  ll.print();


}