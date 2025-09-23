#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &mat,int row,int col,string path,vector<string>&ans)
{
    int n=mat.size();
    if(row < 0 || col < 0 || row >= n || col >= n || mat[row][col]==0 || mat[row][col]==-1)
    return;

    if(row == n-1 && col == n-1)
    {
        ans.push_back(path);
        return ;
    }
    mat[row][col]=-1; 

    helper(mat,row+1,col,path+"D",ans);//down
    helper(mat,row-1,col,path+"U",ans);//up
    helper(mat,row,col+1,path+"R",ans);//right
    helper(mat,row,col-1,path+"L",ans);//left
    mat[row][col]=1;

}
vector<string> Find_Path(vector<vector<int>> &mat)
{

    int n=mat.size();
    //vector<vector<bool>>visit(n,vector<bool>(n,false));
    vector<string>ans;
    string path="";

    helper(mat,0,0,path,ans);

    return ans;
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter matrix (0 for blocked, 1 for open):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<string> paths = Find_Path(mat);

    if (paths.empty()) {
        cout << "No path exists.\n";
    } else {
        cout << "Possible paths:\n";
        for (string &p : paths) {
            cout << p << endl;
        }
    }

    return 0;
}