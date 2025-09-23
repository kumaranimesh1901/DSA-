#include<iostream>
#include<vector>

using namespace std;


int mount_array(vector<int>& A)
{
    int start=0,end=A.size()-1;

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(A[mid-1]<A[mid] && A[mid]>A[mid+1])
        {
            return mid;
           // return A[mid];  to return the highest value 
        }
        else if(A[mid-1]<A[mid])
        {
            start=mid+1;
        }
        else
        {
            end=mid+1;
        }
    }
    return -1;
}

int main()
{
  
    int value;
    cout<<"enter the number of array to be inputed";
    cin>>value;
    vector<int> nums(value);
    for(int val=0;val<value;val++)
    {
        cin>>nums[val];
    }

    cout<<"index value = " <<mount_array(nums);
}