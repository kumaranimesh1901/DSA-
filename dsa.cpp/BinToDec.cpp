#include<iostream>
using namespace std;


int BinToDec(int binnum)
{
    int pow=1,ans=0;
    while(binnum>0)
    {
       int rem=binnum%10;
       ans+=rem*pow;
       binnum /=10;
       pow*=2;

    }

    return ans;
}
int main()
{
int binaryNumber;
cout<<"enter binary number to convert into decimal  ";
cin>>binaryNumber;
cout<<"converted number= "<<BinToDec(binaryNumber);
}