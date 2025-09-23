#include<iostream>
#include<vector>

using namespace std;

//minimun possible maximum time

bool isPossible(vector<int> &arr,int n,int m,int maxAllowedTime)
{
    int painter=1,time=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxAllowedTime)
        {
            return false;
        }
        if(time+arr[i]<=maxAllowedTime)
        {
            time+=arr[i];
        }
        else
        {
            painter++;
            time=arr[i];
        }
    }
     return painter>m?false:true;
}

int minTimeToPaint(vector<int> &arr,int n,int m)
{
    int sum=0,maxValue=arr[0];
    if(m>n)
    {
        return -1;
    }

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        maxValue=max(maxValue,arr[i]);
    }
    int start=maxValue,end=sum,ans=-1;

    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(arr,n,m,mid))//left
        {
            ans=mid;
            end=mid-1;
        }
        else//right
        {
            start=mid+1;
        }
    }
    return ans;

}

int main()
{
    vector<int> arr;//={40,30,10,20};
    int k;
    cout<<"enter the number of array to be inputed";
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int x;
        cin>> x;
        arr.push_back(x);
    }
    int n=4,m=2;
    cout<<minTimeToPaint(arr,n,m);
}
