#include <iostream>
#include <vector>
using namespace std;

bool IsSafe(vector<vector<char>>& board,int row,int col,char digit) {
    for(int i=0;i<9;i++) {
        if(board[i][col]==digit) return false;   // check column
        if(board[row][i]==digit) return false;   // check row
    }
    int srow=(row/3)*3, scol=(col/3)*3;
    for(int i=srow;i<srow+3;i++) {
        for(int j=scol;j<scol+3;j++) {
            if(board[i][j]==digit) return false;  // check 3x3 box
        }
    }
    return true;
}

bool helper(vector<vector<char>>& board,int row,int col) {
    if(row==9) return true; // solved entire board
    
    int nextRow = row, nextCol = col+1;
    if(nextCol==9) { 
        nextRow=row+1; 
        nextCol=0; 
    }

    if(board[row][col] != '.') {
        return helper(board,nextRow,nextCol); // skip filled cell
    }

    for(char digit='1' ; digit<='9' ; digit++) {
        if(IsSafe(board,row,col,digit)) {
            board[row][col]=digit;
            if(helper(board,nextRow,nextCol))
                return true;
            board[row][col]='.'; // backtrack
        }
    }
    return false; // no valid digit
}

bool solveSudoku(vector<vector<char>>& board) {
    return helper(board,0,0);
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter Sudoku puzzle (9x9).\n";
    cout << "Use '.' for empty cells.\n\n";

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            char c;
            cin >> c;
            board[i][j] = c;
        }
    }

    cout << "\nOriginal Sudoku:\n";
    for(auto &row : board) {
        for(char c : row) cout << c << " ";
        cout << "\n";
    }

    if(solveSudoku(board)) {
        cout << "\nSolved Sudoku:\n";
        for(auto &row : board) {
            for(char c : row) cout << c << " ";
            cout << "\n";
        }
    } else {
        cout << "\nNo solution exists for this Sudoku.\n";
    }

    return 0;
}
