#include <bits/stdc++.h>
using namespace std;


bool IsValid(vector<vector<int>>& grid,int row,int col,int n,int expVal)
{
    if(row >= n || col >= n || col < 0 || row < 0 || grid[row][col]!=expVal)
    {
        return false;
    }
    if(expVal == n*n-1)
    {
        return true;
    }


    int ans1=IsValid(grid,row-2,col+1,n,expVal+1);
    int ans2=IsValid(grid,row-1,col+2,n,expVal+1);
    int ans3=IsValid(grid,row+1,col+2,n,expVal+1);
    int ans4=IsValid(grid,row+2,col+1,n,expVal+1);
    int ans5=IsValid(grid,row+2,col-1,n,expVal+1);
    int ans6=IsValid(grid,row+1,col-2,n,expVal+1);
    int ans7=IsValid(grid,row-1,col-2,n,expVal+1);
    int ans8=IsValid(grid,row-2,col-1,n,expVal+1);

    return  ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
       return  IsValid(grid,0,0,grid.size(),0);
    }
        int main()
{
    int n;
    cout << "Enter the size of the grid (n x n): ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the grid values (0 to " << n * n - 1 << "):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    if (checkValidGrid(grid))
    {
        cout << " The grid represents a valid Knight's Tour.\n";
    }
    else
    {
        cout << " The grid does NOT represent a valid Knight's Tour.\n";
    }

    return 0;
}