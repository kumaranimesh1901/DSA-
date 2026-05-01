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
    bool isCyclicHelper(int u, vector<bool> &visited, int parent)
    {
        visited[u]=true;
        for(auto v:l[u])
        {
            if(!visited[v])
            {
                if(isCyclicHelper(v,visited,u))
                {
                    return true;
                }
            }
            else if(v!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCyclic()
    {        vector<bool> visited(v,false);
        for(int i=0;i<v;i++)        {
            if(!visited[i])            {
                if(isCyclicHelper(i,visited,-1))
                {
                    return true;                
                }
            }
        } 
        return false;
    }
    bool iscyclcBfs(int src,vector<bool> &visited)
    {
        queue<pair<int,int>> Q;
        Q.push({src,-1});
        visited[src]=true;
        while(Q.size()>0)
        {
            int u=Q.front().first;
            int parent=Q.front().second;
            Q.pop();
            for(auto v:l[u])
            {
                if(!visited[v])
                {
                    visited[v]=true;
                    Q.push({v,u});
                }
                else if(v!=parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCyclicBfs()
    {
        vector<bool> visited(v,false);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                if(iscyclcBfs(i,visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    void dfstopologicalsort(int u, vector<bool> &visited, stack<int> &S)
    {
        visited[u]=true;
        for(auto v:l[u])
        {
            if(!visited[v])
            {
                dfstopologicalsort(v,visited,S);
            }
        }
        S.push(u);
    }
    void toposort()
    {
        vector<bool>vis(v,false);
        stack<int>s;
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                dfstopologicalsort(i,vis,s);
            }
        }
        while (s.size()>0)
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};
int main()
{
    graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    g.toposort();
    cout<<"topological sort"<<endl;
    g.bfs();
    cout<<endl;
    cout<<g.isCyclic();
    cout<<endl;
    cout<<g.isCyclicBfs();//O(V+E)
    cout<<endl;
    g.dfs();

}  