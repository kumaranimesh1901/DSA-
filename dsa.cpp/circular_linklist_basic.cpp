#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data=val;
        next=prev=NULL;
    }
};

class circularList
{
    Node*head;
    Node*tail;

    public:
    circularList()
    {
        head=tail=NULL;
    }

    void insert_at_head(int val)
    {
        Node* newNode=new Node(val);

        if(tail==NULL)
        {
            head=tail=newNode;
            tail->next=head;;
        }
        else
        {
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }

    void insert_at_tail(int val)
    {
        Node* newNode=new Node(val);
        if(tail==NULL)
        {        
            head=tail=newNode;
            tail->next=head;
        }        
        else
        {
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
        }
    }

    void delete_at_head()
    {
        if(head==NULL)  return;

        else if(head==tail)
        {
            delete head;
            head=tail=NULL;
        }
        else
        {
            Node* temp=head;
            head=head->next;
            tail->next=head;

            temp->next=NULL;
            delete temp;
        }
    }

    void delete_at_tail()
    {
        

        if(tail==NULL) return ;

        else if(tail==head)
        {
            delete tail;
            head=tail=NULL;
        }

        else
        {
            Node* temp=tail;
            Node*prev=head;

            while(prev->next !=tail)
            {
                prev=prev->next;
            }
            tail=prev;
            tail->next=head;

            temp->next=NULL;
            delete temp;
        }
    }
     void print()
    {
        if(head==NULL)  return ;

        cout<<head->data<<"->";
        Node *temp=head->next;
        while(temp!= head)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data;
    }
};

int main()
{
    circularList cll;
    cll.insert_at_head(1);
    cll.insert_at_head(2);
    cll.insert_at_head(3);

    cll.insert_at_tail(10);
    cll.insert_at_tail(11);
    cll.insert_at_tail(12);

    cll.delete_at_head();
    cll.delete_at_tail();

    cll.print();

    return 0;

}