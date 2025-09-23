#include<iostream>
#include<vector>
using namespace std;

int diaonalSum(vector<vector<int>>& mat,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                sum+=mat[i][j];
            }
            else if(j==n-1-i)
            {
                sum+=mat[i][j];
            }
        }
    }
    return sum;
}

int main()
{
int n;
cout<<"enter the size of  array"<<endl;
cin>>n;
vector<vector<int>>mat(n,vector<int>(n));
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<"matrix["<<i<<"]"<<"["<<j<<"]"<<" ";
        cin>>mat[i][j];
    }
}
cout<<diaonalSum(mat,n);
return 0;
}

/* optimized way

int sum=0;

for(int i=0;i<n;i++)
{
sum+=mat[i][i];
if(i!=n-1-i)
{
sum+=mat[i][n-1-i];
}
}
*/