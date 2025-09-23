#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralorder(vector<vector<int>>&mat)
{
    int m=mat.size(),n=mat[0].size();
    int startRow=0,startCol=0,endRow=m-1,endCol=n-1;
    vector<int>ans;  //to return the matrix

    while(startRow<=endRow && startCol<=endCol)
    {
        //TOP ROW
        for(int i=startCol;i<=endCol;i++)
        {
            ans.push_back(mat[startRow][i]);
        }
        
        // RIGHT COLUMN
        for(int i=startRow+1;i<=endRow;i++)
        {
            ans.push_back(mat[i][endCol]);
        }
        //BOTTOM ROW
        
         for(int i=endCol-1;i>=startCol;i--)
        {
            if(startRow==endRow)
        {
            break;
        }
            ans.push_back(mat[endRow][i]);
        }
        
        //LEFT COLUMN
         for(int i=endRow-1;i>=startRow+1;i--)
        {
            if(startCol==endCol)
        {
            break;
        }
            ans.push_back(mat[i][startCol]);
        }
        startRow++;startCol++;
        endRow--;endCol--;
    }
    return ans;

}

int main()
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));

    cout << "Enter matrix elements row by row:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<"MATRIX ["<<i<<"]"<<"["<<j<<"]  ";
            cin >> mat[i][j];
        }
    }

    vector<int> result = spiralorder(mat);

    cout << "Spiral order: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}