#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getper(vector<int> &nums,int idx,vector<vector<int>> &ans)
{
    if(idx==nums.size())
    
    {
        ans.push_back(nums);
        return;

    }
    for(int i=idx;i<nums.size();i++)
    {
        swap(nums[idx],nums[i]);
        getper(nums,idx+1,ans);
        swap(nums[idx],nums[i]);
        
    }
}
 vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        getper(nums,0,ans);

        return ans;
        
    }


int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> result = permute(nums);

    cout << "\nAll permutations are:\n";
    for (auto &vec : result)
    {
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}