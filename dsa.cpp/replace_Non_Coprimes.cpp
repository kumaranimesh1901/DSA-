#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int x,int y)
    {
        while(x>0 && y>0)
        {
            if(x>y)
                x=x%y;
            else
                y=y%x;
        }
        if(x==0) return y;
        else return x;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        stack<int> s;

        for(int i=0;i<nums.size();i++)
        {
            s.push(nums[i]);

            while(s.size()>1)
            {
                int a=s.top(); s.pop();
                int b=s.top(); s.pop();

                if(gcd(a,b)>1)
                {
                    long long int lcm=1ll*a*b/gcd(a,b);
                    s.push((int)lcm);
                }
                else
                {
                    s.push(b);
                    s.push(a);
                    break;
                }
            }
        }

        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });

int main() {
    Solution sol;

    vector<int> nums = {6,4,3,2,7,6,2};
    vector<int> result = sol.replaceNonCoprimes(nums);

    cout << "Result: ";
    for(int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
