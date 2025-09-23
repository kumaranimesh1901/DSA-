#include<iostream>
#include<vector>
#include <set>

using namespace std;

 set<vector<int>> s;

    void get_all_combination(vector<int> &arr,int idx,int target,vector<vector<int>> &ans, vector<int> &combination)
    {
        if(idx==arr.size() || target < 0)
        {
            return;
        }

        if(target==0)
        {
            if(s.find(combination)==s.end())
            {
            ans.push_back(combination);
            s.insert(combination);
            }
            
            return;
        }
        


        combination.push_back(arr[idx]);

        get_all_combination(arr,idx+1,target-arr[idx],ans,combination);

       get_all_combination(arr,idx,target-arr[idx],ans,combination);
        combination.pop_back();

        get_all_combination(arr,idx+1,target,ans,combination);
      
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {

        vector<vector<int>> ans;
        vector<int> combination;

        get_all_combination(arr,0,target,ans,combination);
        return ans;
        
    }

    int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    vector<vector<int>> result = combinationSum(arr, target);

    cout << "\nCombinations that sum to " << target << ":\n";
    if (result.empty()) {
        cout << "No combinations found.\n";
    } else {
        for (auto &vec : result) {
            cout << "[ ";
            for (int num : vec) cout << num << " ";
            cout << "]\n";
        }
    }

    return 0;
}