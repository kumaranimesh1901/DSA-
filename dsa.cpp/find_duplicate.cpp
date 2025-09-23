
//using SLOW AND FAST POINTER





#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& arr) {
    int slow = arr[0], fast = arr[0];

   
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

   
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    int n;
    cout << "Enter the number of elements (n+1): ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " numbers (each from 1 to " << n-1 << "):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int duplicate = findDuplicate(nums);
    cout << "Duplicate number is: " << duplicate << endl;

    return 0;
}

/*  ANOTHER APPROACH 



int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return num;  // Found duplicate
            }
            seen.insert(num);
        }

        return -1;  // Should never happen if there's guaranteed duplicate
    }


    
*/
