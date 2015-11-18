/*
Graph, BFS, DFS
Multiple Times Graph Simulation
*/

#include<bits/stdc++.h>
#define CLR(a,b) memset(a,b,sizeof(a))
#define LL long long

using namespace std;

vector<int>graph[30005];
vector<int>cost[30005];
bool visited[30005];
int dis[30005], dis2[30005] ;

void BFS(int x, int &y)
{
    CLR(visited,false);
    CLR(dis,0);
    queue<int>q;
   // while(!q.empty()){ q.pop(); }
    q.push(x);
    visited[x]=true;
    dis[x]=0;
    int maxi = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            int c = cost[u][i];
            if(!visited[v])
            {
                visited[v]=true;
                dis[v] = dis[u]+cost[u][i];
                if(dis[v]>maxi)
                {
                    maxi=dis[v];
                    y = v;
                }
                q.push(v);
            }
        }
    }

}

int main()
{
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        int nodes;
        scanf("%d", &nodes);
        for(int i=0; i<30005; i++)
            graph[i].clear();
        for(int i=0; i<30005; i++)
            cost[i].clear();
        CLR(dis2, 0);
        for(int i=1; i<nodes; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            graph[x].push_back(y);
            graph[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
        }
        int s, t, w;
        BFS(0,s);
        BFS(s,t);
        for(int i=0; i<nodes; i++)
        {
            dis2[i] = dis[i];
        }
        BFS(t,w);
        //cout<<s<<' '<<t<<' '<<w<<endl;
        printf("Case %d:\n", caseno);
        for(int i=0; i<nodes; i++)
        {
            printf("%d\n", max(dis[i], dis2[i]));
        }
    }
    return 0;
}
