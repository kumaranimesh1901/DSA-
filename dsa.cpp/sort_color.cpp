#include<iostream>
#include<vector>

using namespace std;

void sortcolor(vector<int>&nums)
{
    int n=nums.size();
    int mid=0,low=0,high=n-1;

    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[low],nums[mid]);
            mid++;
            low++;
        }
        else if(nums[mid]==1)
        {
            mid++;
        }
        else 
        {
            swap(nums[mid],nums[high]);
            high--;
        }

    }
}

int main()
{
    vector<int> nums = {0,1,2,0,2,1,2,0,1,0,2,2};
    
    sortcolor(nums); // sort in-place

    for(int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}