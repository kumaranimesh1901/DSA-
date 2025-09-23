#include<bits/stdc++.h>
using namespace std;

class Minstack
{
public:
stack<long long int> s;
long long int minval;
Minstack()
{}
void push(int val)
{
    if(s.empty())
    {
        s.push(val);
        minval=val;
    }
    else
    {
        if(val <minval)
        {
            s.push(2*val-minval);
            minval=val;
        }
        s.push(val);
    }
}
void pop()
{
    if(s.top()<minval)
    {
        minval=2*minval-s.top();

    }
    s.pop();
}
int top()
{
    if(s.top()<minval)
    {
        return minval;
    }
    return s.top();
}
int getMin()
{
    return minval;
}
};

int main() {
    Minstack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Current Min: " << ms.getMin() << endl;
    cout << "Current Top: " << ms.top() << endl;

    ms.pop();
    cout << "After popping one element:" << endl;
    cout << "Current Min: " << ms.getMin() << endl;
    cout << "Current Top: " << ms.top() << endl;

    ms.pop();
    cout << "After popping again:" << endl;
    cout << "Current Min: " << ms.getMin() << endl;
    cout << "Current Top: " << ms.top() << endl;

    return 0;
}

/*
basic approach

class Minstack
{
public:
stack<pair<int,int> s;

Minstack()
{}
void push(int val)
{
    if(s.empty())
    {
    s.push({val,val})
    }
    else
    {
    int minval=min(val,s.top.second)
    s.push({val,minval});
    }
}
void pop()
{
    s.pop();
}
int top()
{
    
    return s.top().first;
}
int getMin()
{
    return s.top().second;
}
};

*/