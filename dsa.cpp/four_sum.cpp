#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        int n=nums.size();

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            for(int j=i+1;j<n; )
            {
               
                int p=j+1,q=n-1;

                while(p<q)
                {
                 long long sum=(long long)nums[i]+(long long)nums[j]
                 + (long long)nums[p]+(long long)nums[q];
                    
                    if(sum>target)
                    {
                        q--;
                    }
                    else if(sum<target)
                    {
                        p++;
                    }
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        p++;q--;
                        while(p<q && nums[p]==nums[p-1])
                        p++;
                    }
                }
               j++;
                while(j<n && nums[j]==nums[j-1])
                j++; 
            }
        }
        return ans;
    }

    int main() {
        
    vector<int> nums;
    int n, target;

    // Input
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "Enter target: ";
    cin >> target;

    // Find quadruplets
    vector<vector<int>> result = fourSum(nums, target);

    // Output
    cout << "Quadruplets that sum to target:\n";
    for (const auto& quad : result) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
