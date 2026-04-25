#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;
class graph
{
    int v;
    list<int>*l;
    public:
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void bfs()
    {
        queue<int> Q;
        vector<bool> visisted(v,false);
        Q.push(0);
        visisted[0]=true;
        while(Q.size()>0)
        {
            int u=Q.front();
            Q.pop();
            cout<<u;
            for(auto v:l[u])
            {
                if(!visisted[v])
                {
                    visisted[v]=true;
                    Q.push(v);
                }
                
            }
        }
    }
    void dfshelper(int u, vector<bool> &visited)
    {
        cout<<u;
        visited[u]=true;
        for(auto v:l[u])
        {
            if(!visited[v])
            {
                dfshelper(v,visited);
            }
        }
    }
    void dfs()
    {
        vector<bool> visited(v,false);
        dfshelper(0,visited);
    }
};
int main()
{
    graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    
    g.addEdge(2,4);
    g.bfs();
    cout<<endl;
    g.dfs();

}   