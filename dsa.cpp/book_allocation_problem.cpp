#include<iostream>
#include<vector>

using namespace std;

bool isValid(vector<int> &arr,int n,int m,int maxAllowedPage)
{
    int student=1,pages=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxAllowedPage)
        {
            return false;
        }
        if(pages+arr[i]<=maxAllowedPage)
        {
            pages+=arr[i];
        }
        else
        {
            student++;
            pages=arr[i];
        }
    }
    return student>m?false:true;
}
int allocateBooks(vector<int> &arr,int n,int m)
{
    if(m>n)
    {
        return -1;
    }
int sum=0;
for(int i=0;i<n;i++)
{
    sum+=arr[i];
}
int start=0,end=sum;
int ans=-1;
while(start<=end)
{
    int mid=start+(end-start)/2;
    if(isValid(arr,n,m,mid))//left
    {
        ans=mid;
        end=mid-1;
    }
    else  //right
    {
        start=mid+1;
    }
}
return ans;
}
int main()
{
    vector<int> arr={2,1,3,4};
    int n=4,m=2;
    cout<<allocateBooks(arr,n,m);
}
