#include<iostream>
using namespace std;


int linearSearch(int size,int target,int arr[])
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}
// REVERSE OF NUMBER
void reverseArray(int arr[],int sz)
{
    int start=0,end=sz-1;
    while(start<end)
    {
        swap(arr[start],arr[end]);
        start++;end--;
    }
}
int main()
{
    int arr[]={4,5,9,8,6,3};
    int size=6;
    int target=4;
    reverseArray(arr,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;


}