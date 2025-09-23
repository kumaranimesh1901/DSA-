#include<iostream>
#include<vector>
#include <algorithm>
using  namespace std;

 vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int j=i+1,k=n-1;

            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0)
                {
                    k--;
                }
                else if(sum<0)
                {
                    j++;
                }
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1])
                    {
                        j++;
                    }
                }
            }
            
        }
        return ans;
    }

    int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " numbers (can include negative and duplicates):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets with sum 0 are:" << endl;
    for (int i = 0; i < result.size(); i++) {
    vector<int> triplet = result[i];
    for (int j = 0; j < triplet.size(); j++) {
        cout << triplet[j] << " ";
    }
    cout << endl;
}    
    return 0;
}


/* for main function we can replace this 
line 58-64

for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }*/
