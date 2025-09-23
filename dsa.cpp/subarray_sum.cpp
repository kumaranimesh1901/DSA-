#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];

    // Compute prefix sums
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    unordered_map<int, int> m;

    for (int j = 0; j < n; j++) {
        // If prefix sum from 0 to j is equal to k
        if (prefixSum[j] == k) count++;

        int val = prefixSum[j] - k;

        // Check if any previous prefix sum == currentPrefixSum - k
        if (m.find(val) != m.end()) {
            count += m[val];
        }

        // Update frequency of current prefix sum
        m[prefixSum[j]]++;
    }

    return count;
}
 int main() {
    int n, k;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the target sum k: ";
    cin >> k;

    int result = subarraySum(nums, k);
    cout << "Number of subarrays with sum equal to " << k << " is: " << result << endl;

    return 0;
}