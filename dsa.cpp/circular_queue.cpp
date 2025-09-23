#include<bits/stdc++.h>
using namespace std;
 

class circularQueue
{
    int *arr;
    int currSize,cap;
    int f,r;

    public:
    circularQueue(int size)
    {
        cap=size;
        arr=new int[cap];
        currSize=0;
        f=0;
        r=-1;
    }
    void push(int data)
    {
        if(currSize==cap)
        {
            cout<<"Capacity is full";
            return;
        }
        r=(r+1)%cap;
        arr[r]=data;
        currSize++;
    }
    void pop()
    {
        if(empty())
        {
            cout<<"circularqueue is empty";
            return;
        }
        f=(f+1)%cap;
        currSize--;
    }

    int front()
    {
         if(empty())
        {
            cout<<"circularqueue is empty";
            return -1;
        }
        return arr[f];
    }

    bool empty()
    {
        return currSize==0;
    }

    void print()
    {
        for(int i=0;i<cap;i++)
        {
            cout<<arr[i]<<" ";
            
        }
    }

    
};

int main()
{
    circularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);

   // cq.print();

    while(!cq.empty())
    {
        cout<<cq.front()<< " ";
        cq.pop();
    }

    return 0;
}