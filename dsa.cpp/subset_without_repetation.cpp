//Given an integer array nums of unique elements, 
//return all possible subsets



#include<iostream>
#include <vector>
using namespace std;

void print_subset(vector<int> &arr,vector<int> ans,int i)
{
    if(i==arr.size())
    {
        for(int val:ans)
        {
            cout<<val<<" ";
        }
        cout<<"\n";
        return;
    }
    //include part
    ans.push_back(arr[i]);
    print_subset(arr,ans,i+1);
    ans.pop_back(); //backtrack
    //exclude
    print_subset(arr,ans,i+1);

}
int main()
{
    vector<int> arr={1,2,3};
    vector<int> ans;

    print_subset(arr,ans,0);
    return 0;
}