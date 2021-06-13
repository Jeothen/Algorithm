#include <iostream>
#include <vector>
#include <queue>

#define MAX_NODE 301
#define START 1
#define INF 1'000'000'000

int F[MAX_NODE][MAX_NODE], C[MAX_NODE][MAX_NODE];
std::vector<int> adj[MAX_NODE];
std::vector<std::pair<int,int>> edges;

void init()
{
    memset(F,0,sizeof(F));
    memset(C,0,sizeof(C));
    edges.clear();
    for (int i=0;i<MAX_NODE;i++) adj[i].clear();
}

int min(int a, int b)
{
    return a > b ? b : a;
}

bool other_path(int source, int target)
{
    std::queue<int>q; q.push(source);
    std::vector<int> prev(MAX_NODE, -1);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto next : adj[cur])
        {
            if (prev[next] == -1 && C[cur][next] > F[cur][next]) 
            {
                q.push(next);
                prev[next] = cur;
                if (next == target) return true;
            }
        }
    }
    if (prev[target] == -1) return false;
    return true;
}

void maximum_flow(int END)
{
    int prev[MAX_NODE];
    while (1)
    {
        memset(prev,-1,sizeof(prev));
        std::queue<int>q; q.push(START);
        while(!q.empty())
        {
            int cur = q.front(); q.pop();
            for (auto next : adj[cur])
            {
                if (prev[next] == -1 && C[cur][next] > F[cur][next])
                {
                    prev[next] = cur;
                    q.push(next);
                }
            }
        }
        if (prev[END] == -1) break; // Not visit target
        int min_flow = INF;
        for (auto i = END; i != START; i = prev[i])
        {
            min_flow = min(C[prev[i]][i]-F[prev[i]][i], min_flow);
        }
        for (int i = END; i != START; i = prev[i])
        {
            F[prev[i]][i] += min_flow;
            F[i][prev[i]] -= min_flow;
        }
    }
}

int main()
{
    freopen("5651.txt","r",stdin);
    int tc; scanf("%d",&tc);
    while(tc--)
    {
        int N, M; scanf("%d %d",&N,&M);
        init();
        int f,t,b;
        for (int i=0; i<M; i++)
        {
            scanf("%d %d %d",&f,&t,&b);
            adj[f].push_back(t);

            adj[t].push_back(f); // reverse way
            C[f][t] += b;
            edges.push_back({f,t});
        }
        maximum_flow(N);
        int res = 0;
        for (int i= 0; i < edges.size() ; i++) 
        {
            if (!other_path(edges[i].first, edges[i].second)) res++;
        }
        printf("%d\n",res);
    }
}