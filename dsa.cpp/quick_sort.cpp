#include <bits/stdc++.h>
using namespace std;

int prartition(vector<int>&arr,int start,int end)
{
    int idx=start-1 , pivot=arr[end];

    for(int j=start;j<end;j++)
    {
        if(arr[j] <= pivot)
        {
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}

void quick_sort(vector<int> &arr,int start,int end)
{
    if(start < end)
    {
        int pivtIdx=prartition(arr,start,end);
        quick_sort(arr,start,pivtIdx-1);//left
        quick_sort(arr,pivtIdx+1,end);//right
    }
}

int main()
{
vector<int> arr={6,5,4,3,2,1};
quick_sort(arr,0,arr.size()-1);

for(int val:arr)
{
    cout<<val<<" ";
}
cout<<"\n";
return 0;

}

//TC => O(nlogn)
//worst case O(n^2) only when the pivot element
//always smallest or largest ex=1 2 3 4 5 6
