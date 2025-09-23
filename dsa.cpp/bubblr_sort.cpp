#include<iostream>
//#include<algorithium>
using namespace std;

void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        bool isSwap=false;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap)
        {
            return;
        }
    }
}

void printarr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
}
 int main()
 {
    int N=5;
    int arr[N]={1,2,3,4,5};
    bubbleSort(arr,N);
    printarr(arr,N);
 }