#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the value of n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        //space 
        for(int j=0;j<n-1-i;j++)
    {
        cout<<" ";

    }
    //number 1
    for(int j=1;j<=i+1;j++)
    {
        cout<<j;
    }
   //number 2 
    for(int j=i;j>=1;j--)
    {
        cout<<j;
    }
    cout<<"\n";
    }
}