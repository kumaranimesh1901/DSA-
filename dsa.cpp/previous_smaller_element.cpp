#include<bits/stdc++.h>
using namespace std;


vector<int> next_greater(vector<int> &num)
{
    stack<int> s;
    vector<int> ng(num.size(),0);
    for(int i=0;i<num.size();i++)
    {
        while(s.size()>0  && s.top()>=num[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            ng[i]=-1;
        }
        else
        ng[i]=s.top();

        s.push(num[i]);
    }
    return ng;
}
int main()
{
    vector<int> num={3,1,0,8,6};
    vector<int>ans;
   ans=next_greater(num);

    for(int val:ans)
    {
        cout<<val<<" ";
    }
}