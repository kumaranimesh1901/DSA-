 #include<iostream>
 #include<vector>
 using namespace std;

 bool searchrow(vector<vector<int>>&mat,int target,int row)
 {
        int  n=mat[0].size();
        int start=0,end=n-1;

        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target==mat[row][mid])
            {
                return true;
            }
            else if(target>mat[row][mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
       return false;
 }

 bool searchmatrix(vector<vector<int>>&mat,int target)
 {
    int m=mat.size(), n=mat[0].size();

    int startrow=0,endrow=m-1;

    while(startrow<=endrow)
    {
        int midrow=startrow+(endrow-startrow)/2;

        if(target>=mat[midrow][0] && target<=mat[midrow][n-1])
        {
               // found the row 

             return  searchrow(mat,target,midrow);
        }
        else if(target>=mat[midrow][n-1])
        {
            startrow=midrow+1;
        }
        else
        {
            endrow=midrow-1;
        }
    }

return false;
}

 int main()
 {
    int n,m,target=22;
cout<<"enter the size of  array"<<endl;
cin>>n>>m;
vector<vector<int>>mat(n,vector<int>(m));
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cout<<"matrix["<<i<<"]"<<"["<<j<<"]"<<" ";
        cin>>mat[i][j];
    }
}
cout<<searchmatrix(mat,target);
return 0;

 }
 
 /*

 APPROACH 

 1 2 3  - increasing order matrix in left to right and top to bottom 
 4 5 6
 7 8 9

 
 */