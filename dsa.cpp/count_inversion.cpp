#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr,int start,int mid,int end)
{
    vector<int> temp;
    int i=start,j=mid+1;
    int inv_count=0;
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
        temp.push_back(arr[i]);
        i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            inv_count+=(mid-i+1);
        }

    }
    while(i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx=0;idx < temp.size();idx++)
    {
        arr[idx+start]=temp[idx];
    }
    return inv_count;
}

int merge_sort(vector<int> &arr,int start,int end)
{
    if(start<end)
    {
        
        int mid=start+(end-start)/2;
        int left_inv_count= merge_sort(arr,start,mid);//left
        int right_inv_count=merge_sort(arr,mid+1,end);//right

      int inv_count=  merge(arr,start,mid,end);

        return left_inv_count+right_inv_count+inv_count;
    }
    return 0;
}
int main()
{
    vector<int>arr={6,3,5,2,7};

    int ans=merge_sort(arr,0,arr.size()-1);

   /*/for(int val:arr)
    {
        cout<< val <<" ";
    }*/
   cout<<ans<<"\n";
    return 0;
}