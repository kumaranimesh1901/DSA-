#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        //1st window
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for (int i = k; i < nums.size(); i++) {
            res.push_back(nums[dq.front()]);

            //remove not part of curr window

            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            //remove the smaller val

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Sliding window maximums: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
