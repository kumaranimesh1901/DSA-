#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int maxwater=0;
    int n=height.size();
    int lp=0,rp=n-1;
    while(lp<rp)
    {
        int width=rp-lp;
        int ht=min(height[lp],height[rp]);
        int curr_water=ht*width;
        maxwater=max(maxwater,curr_water);
       height[lp]>height[rp]?rp--:lp++;
    }
    return maxwater;
   
}

int main()
{
    int n;
    vector<int>height;//;{1,2,3,4,5};
    
    cout<<"enter the value of height \n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int h;

        cout<<"HEIGHT AT INDEX ["<<i<<"] = ";
        cin>>h;

        height.push_back(h);
    }
    cout<<maxArea(height);
}