#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


    void get_all_subset(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allsubset) {
        if (i == nums.size()) {
            allsubset.push_back(ans);
            return;
        }

        // Include nums[i]
        ans.push_back(nums[i]);
        get_all_subset(nums, ans, i + 1, allsubset);
        ans.pop_back();

        // Skip duplicates
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        // Exclude nums[i] and all duplicates
        get_all_subset(nums, ans, i + 1, allsubset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort first
        vector<vector<int>> allsubset;
        vector<int> ans;
        get_all_subset(nums, ans, 0, allsubset);
        return allsubset;
    }
int main() {
    vector<int> nums = {4,4,4,1,4};   // example input

    vector<vector<int>> result = subsetsWithDup(nums);

    cout << "Unique subsets are:\n";
    for (auto &subset : result) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}
