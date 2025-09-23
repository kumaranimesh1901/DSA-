#include<bits/stdc++.h>

using namespace std;


    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int> s;
        for(int i=0;i<mat.size();i++)
        {
            s.push(i);
        }
        while(s.size()>1)
        {
            int i=s.top();s.pop();
            int j=s.top();s.pop();
            
            if(mat[i][j]==0)
            {
                s.push(i);
            }
            else
            s.push(j);
        }
        
        int celeb=s.top();
        
        for(int i=0;i<mat.size();i++)
        {
            if((i != celeb)  && (mat[i][celeb]==0  || mat[celeb][i]==1) )
            {
                return -1;
            }
        }
        
            return celeb;
    }


int main()
{
    vector<vector<int>> arr={{0,1,0},{0,0,0} ,{0,1,0}};

    int ans=celebrity(arr);

    cout<<ans;
}