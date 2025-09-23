#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque <int> dq;

    dq.push_front(1);
    dq.push_front(2);
    dq.push_front(3);
    dq.push_back(13);
    dq.push_back(14);


    while(!dq.empty())
    {
        cout<<dq.back()<<" ";
       dq.pop_back();
    }
    return 0;

}