#include<iostream>
#include<vector>

using namespace std;


int search(vector<int>&a,int tar)
{
    int start=0,end=a.size()-1;

    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==tar)
        {
            return mid;
        }
        if(a[start]<=a[mid])  //left part sorted
        {
        if(a[start]<=tar&&tar<=a[mid])
        {
            end=mid-1;
        }
        else {
            start=mid+1;
        }
    }
        else       //right part sorted
        {
        if(a[mid]<=tar &&tar<=a[end])
        {
            start=mid+1;
        }
        else
        {
        end=mid-1;
    }
}
}
return -1;
}
int main()
{
  vector<int>nums={6,7,0,1,2,3,4,5};
  int target=7;

  cout<<search(nums,target);
}
