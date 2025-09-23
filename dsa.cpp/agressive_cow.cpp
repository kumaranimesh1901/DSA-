#include<iostream>
#include<vector>
#include<algorithm>

//maximum possible minimum distance

using namespace std;

bool isPossible(vector<int>&nums,int m,int n,int maxPossibleValue)
{
    int cow=1,stall=nums[0];
    for(int i=0;i<m;i++)
    {

        if(nums[i]-stall >= maxPossibleValue)
        {
           
            cow++;
            stall=nums[i];
        }
        if(cow==n)
        {
            return true;
        }
    }
    return false;
}

int Aggressive_Cow(vector<int> &nums,int m,int n)
{
    sort(nums.begin(),nums.end());
    int ans=-1;
    if(n>m)
    {
        return -1;
    }
    
    int start=1,end=nums[m-1]-nums[0];
    while(start <= end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(nums,m,n,mid))
        {
            ans=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }

    }
   return ans;
}

int main()
{
    vector<int> nums={1,2,8,4,9};
    int m=5,n=3;
    cout<<Aggressive_Cow(nums,m,n);

}