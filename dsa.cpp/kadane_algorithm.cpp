#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
    int n=5;
    int arr[5]={-10,-20,-30,-40,-50};
    int curr_max=0;int max_val=INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr_max+=arr[i];
        max_val=max(curr_max,max_val);
        if(curr_max<0)
        {
            curr_max=0;
        }

    }
    cout<<max_val;
}