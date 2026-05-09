#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;   

class edge
{
public:
    int v;
    int wt;

    edge(int v,int wt)
    {
        this->v = v;
        this->wt = wt;
    }
    void bellaman(int src,vector<vector<edge>> g,int V)
    {
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        for(int i=0;i<V-1;i++)
        {
            for(int u=0;u<V;u++)
            {
                for(auto e:g[u])
                {
                    if(dist[e.v] > dist[u]+e.wt)
                    {
                        dist[e.v]=dist[u]+e.wt;
                    }
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    int V=5;
    vector<vector<edge>> g(V);
    g[0].push_back(edge(1,2));
    g[0].push_back(edge(2,4));

    g[1].push_back(edge(4,-1));
    g[1].push_back(edge(2,-4));

    g[2].push_back(edge(3,2));

    g[3].push_back(edge(4, 4));

        edge e(0,0);
        e.bellaman(0,g,V);


    return 0;
}