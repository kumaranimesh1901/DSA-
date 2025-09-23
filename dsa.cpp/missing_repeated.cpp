#include <iostream>
#include<vector>
#include <unordered_set>
using namespace std;

 vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> freq;
        int n = grid.size();
        vector<int> ans; 
        int a,b;
        int expected_sum=0,actual_sum=0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                actual_sum+=grid[i][j];
                if(freq.find(grid[i][j])!=freq.end())
                {
                    a=grid[i][j];
                    ans.push_back(a);
                }
              freq.insert(grid[i][j]);
            }
        }
        expected_sum= (n*n)*(n*n+1)/2;
        b=expected_sum-actual_sum+a;
        ans.push_back(b);

        return ans;
    }

int main() {

     int n;
    cout << "Enter the size of grid (n for n x n): ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the elements of the grid (" << n*n << " numbers):" << endl;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<int> result = findMissingAndRepeatedValues(grid);
    cout << "Repeated number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;

}