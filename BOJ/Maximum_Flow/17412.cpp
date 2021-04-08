#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define MAX_NODE 401
#define START 1
#define END 2
#define INF 2'000'000'000
int N,P;
std::vector<int> adj[MAX_NODE];
int f[MAX_NODE][MAX_NODE], c[MAX_NODE][MAX_NODE];

void init()
{
    memset(adj, false, sizeof(adj));
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
}

int min(int a, int b)
{
    return a > b ? b : a;
}

int maximum_flow()
{
    int res = 0;
    int prev[MAX_NODE];

    while(1)
    {
        memset(prev,-1,sizeof(prev));
        std::queue<int>q;
        q.push(START);
        while(!q.empty() && prev[END] == -1)
        {
            int cur = q.front(); q.pop();
            for (auto next : adj[cur])
            {
                if (prev[next] == -1 && c[cur][next] > f[cur][next])
                {
                    q.push(next);
                    prev[next] = cur;
                    if (next == END) break;
                }            
            }

        }
        if (prev[END] == -1) break;
        int min_flow = INF;
        for (auto i = END; i != START; i = prev[i])
        {
            min_flow = min(min_flow,c[prev[i]][i]-f[prev[i]][i]);
        }
        for (auto i= END; i != START; i = prev[i])
        {
            f[prev[i]][i] += min_flow;
            f[i][prev[i]] -= min_flow;
        }
        res++;
    }
    return res;
}

int main()
{
    freopen("17412.txt","r",stdin);
    scanf("%d %d",&N,&P);
    int s,e;
    init();
    for (int i=0; i<P; i++)
    {
        scanf("%d %d",&s,&e);
        adj[s].push_back(e);
        adj[e].push_back(s);
        c[s][e] = true; // one direct way
    }
    printf("%d\n",maximum_flow());
}