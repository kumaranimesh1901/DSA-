
#include <iostream>
using namespace std;


int DecimalToBinary(int decnum)
{
    int pow=1,ans=0;
    while (decnum>0)
    {
        int rem=decnum%2;
        decnum /=2;
        ans+=rem*pow;
        pow*=10;
    }
    return ans;
    
}
int  main()
{
int decimalnumber;
cout<<"enter the decimal number to convert into binary";
cin>>decimalnumber;
cout<<"convert number= "<< DecimalToBinary(decimalnumber);
}