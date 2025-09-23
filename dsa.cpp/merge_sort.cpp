#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr,int start,int mid,int end)
{
    vector<int> temp;
    int i=start,j=mid+1;
    while(i<=mid &&j<=end)
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

    for(int idx=0;idx<temp.size();idx++)
    {
        arr[idx+start]=temp[idx];
    }
    /*for(int val:temp)
    {
        cout<< val <<" ";
    }
    cout<<"\n";
    */
   //cout<<"start value"<<start<<"\n";

}

void merge_sort(vector<int> &arr,int start,int end)
{
    if(start<end)
    {
        int mid=start+(end-start)/2;
        merge_sort(arr,start,mid);//left
        merge_sort(arr,mid+1,end);//right

        merge(arr,start,mid,end);

        
    }
}

int main()
{
    vector<int>arr={8, 4, 7, 2};

    merge_sort(arr,0,arr.size()-1);

   for(int val:arr)
    {
        cout<< val <<" ";
    }
    return 0;
}