#include<iostream>

using namespace std;


int GCD(int n,int m)
{
    while(n>0 && m>0)
    {
         if(n>m)
    {
        n=n%m;
    }
    if(m>n)
    {
        m=m%n;
    }

    }
   
    if(n==0) return m;
    else return n;
}
int main()
{
int n=20,m=28;
cout<<GCD(n,m);

}