#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n,0);
        vector<int> right(n,0);

        stack<int> s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()] >=heights[i])
            {
                s.pop();
            }
            right[i]=s.empty()?n:s.top();
            s.push(i);
        }
        while(!s.empty())
        {
            s.pop();
        }
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()] >=heights[i])
            {
                s.pop();
            }
            left[i]=s.empty()?-1:s.top();
            s.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int width=right[i]-left[i]-1;
            int currArea=heights[i]*width;
            ans=max(ans,currArea);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> heights1 = {2,1,5,6,2,3};
    cout << "Largest Rectangle Area (Test 1): " 
         << sol.largestRectangleArea(heights1) << endl;

    vector<int> heights2 = {2,4};
    cout << "Largest Rectangle Area (Test 2): " 
         << sol.largestRectangleArea(heights2) << endl;

    vector<int> heights3 = {6,2,5,4,5,1,6};
    cout << "Largest Rectangle Area (Test 3): " 
         << sol.largestRectangleArea(heights3) << endl;

    return 0;
}
