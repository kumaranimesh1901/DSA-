#include<bits/stdc++.h>
using namespace std;


int trap(vector<int> &height)
{

    int n=height.size();
    int ans=0;

    vector<int> lmax(n,0);
    vector<int> rmax(n,0);

    lmax[0]=height[0];
    rmax[n-1]=height[n-1];

    for(int i=1;i<n;i++)
    {
        lmax[i]=max(lmax[i-1],height[i]);
    }

    for(int i=n-2; i>=0;i--)
    {
        rmax[i]=max(rmax[i+1],height[i]);

    }

    for(int i=0;i<n;i++)
    {
        ans+=min(rmax[i],lmax[i])-height[i];
    } 
    return ans;
}

/*
int trap(vector<int> &height)
{
    int n=height.size();
    int ans=0;
    int l=0,r=n-1,lmax=0,rmax=0;

    while(l<r)
    {
        lmax=max(lmax,height[l]);
        rmax=max(rmax,height[r]);

        if(lmax < rmax)
        {
            ans+=lmax-height[l];
            l++;
        }
        else
        {
            ans+=rmax-height[r];
            r--;
        }
    }
    return ans;
}
    */

int main()
{
    vector<int> height={4,2,0,3,2,5};

    cout<<trap(height);
    return 0;
}

