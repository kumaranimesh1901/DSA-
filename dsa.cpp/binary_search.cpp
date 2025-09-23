#include<iostream>
#include<vector>

using namespace std;

/*int binarysearch(vector<int> arr,int tar)
{
    int start=0,end=arr.size()-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(tar>arr[mid])
        {
            start=mid+1;
        }
        else if(tar<arr[mid])
        {
            end=mid-1;
        }
        else return mid;
    } 
    return -1;
}*/

int recBinarySearch(vector<int>arr,int tar,int start,int end)
{
    if(start<=end)
    {
        int mid=start+(end-start)/2;

        if(tar>arr[mid])
        {
            return recBinarySearch(arr,tar,mid+1,end);
        }
        else if(tar<arr[mid])
        {
            return recBinarySearch(arr,tar,start,mid-1);
        }
        else return mid;
    }
    return -1;
}
int main()
{
    vector<int> arr1={-1,0,3,4,5,9,12};
    int tar=12;

   // cout<<binarysearch(arr1,tar)<<"\n";

    vector<int>arr2={-1,0,3,5,9,12};
    int tar1=3;

    cout<<"binary value of arrray 2 =  "<<recBinarySearch(arr2,tar1,0,arr1.size()-1);
}


/*int recBinarySearch(vector<int>arr,int tar,int start,int end)
{
    if(start<=end)
    {
        int mid=start+(start-end)/2;

        if(tar>arr[mid])
        {
            return recBinarySearch(arr,tar,mid+1,end);
        }
        else if(tar<arr[mid])
        {
            return recBinarySearch(arr,tar,start,mid-1);
        }
        else return mid;
    }
    return -1;
}*/