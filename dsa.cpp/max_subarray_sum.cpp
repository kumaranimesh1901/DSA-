#include<iostream>
using namespace std;

int main()
{
    int n=5;
    int arr[n]={1,2,3,4,5};

    int max_sum=0;

    for(int st=0;st<n;st++)
    {
        int currSum=0;
        for(int end=st;end<n;end++)
        {
            currSum+=arr[end];
            max_sum=max(currSum,max_sum);

        }
    }
    cout<<"max subarray sum= "<<max_sum<<"\n";

    return 0;
}