#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        int first = nums[i];
        int second = target - first;

        if (m.find(second) != m.end()) {
            ans.push_back(m[second]); // first index
            ans.push_back(i);         // second index
            break;
        }
        m[first] = i; // store current number's index
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
        cout << "Values: " << nums[result[0]] << " " << nums[result[1]] << endl;
    } else {
        cout << "No two numbers sum up to target." << endl;
    }

    return 0;
}

/*vector<int>ans;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return{};*/