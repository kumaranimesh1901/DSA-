#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board,int row,int col,int n)
{
    // check column
    for(int i=0;i<row;i++) {
        if(board[i][col]=='Q') return false;
    }

    // check upper-left diagonal
    for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--) {
        if(board[i][j]=='Q') return false;
    }

    // check upper-right diagonal
    for(int i=row-1,j=col+1; i>=0 && j<n; i--,j++) {
        if(board[i][j]=='Q') return false;
    }

    return true;
}

void Nqueen(vector<string> &board,int row,int n,vector<vector<string>> &ans)
{
    if(row==n) {
        ans.push_back(board);
        return;
    }

    for(int col=0; col<n; col++) {
        if(isSafe(board,row,col,n)) {
            board[row][col]='Q';
            Nqueen(board,row+1,n,ans);
            board[row][col]='.'; // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n,'.'));
    vector<vector<string>> ans;
    Nqueen(board,0,n,ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<vector<string>> result = solveNQueens(n);

    cout << "Total solutions: " << result.size() << "\n\n";

    for(auto &board : result) {
        for(auto &row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
