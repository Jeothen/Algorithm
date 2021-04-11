#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define START 401
#define END 2
#define INF 2'000'000'000
#define MAX_NODE 400
#define MAX_SIZE 801
#define INF 2'000'000'000

int f[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];
std::vector<int> adj[MAX_SIZE];
// in 1 ~ 400
// out 401 ~ 800

int N,P;

auto min(const int& a, const int& b)
{
    return a > b ? b : a;
}

auto Maximum_Flow()->int
{
    int res = 0;
    int prev[MAX_SIZE];
    while(1)
    {
        memset(prev,-1,sizeof(prev));
        std::queue<int>q; q.push(START); // start : outer
        // already seeting inner to outer / outer to inner
        while(!q.empty() && prev[END] == -1)
        {
            int cur = q.front(); q.pop();
            for (auto next : adj[cur]) 
            {
                if (prev[next] == -1 && c[cur][next] > f[cur][next]) 
                {
                    q.push(next); 
                    prev[next] = cur; 
                }
            }
        }
        if (prev[END] == -1) break;
        int min_flow = INF;
        for (auto i = END; i != START; i = prev[i])
        {
            min_flow = min(min_flow, c[prev[i]][i]-f[prev[i]][i]);
        }
        for (auto i=END; i != START; i = prev[i])
        {
            f[prev[i]][i] += min_flow;
            f[i][prev[i]] -= min_flow;
        }
        res ++;
    }
    return res;
}

// setting out to in

int main()
{
    freopen("2316.txt","r",stdin);
    scanf("%d %d",&N,&P);
    int s,e;
    for (auto i=0; i<P;i++)
    {
        scanf("%d %d",&s,&e);
        c[s+MAX_NODE][e] = 1; c[e + MAX_NODE][s] = 1;
        // s in -> e out   e out -> s in  / s out -> e in / e in -> s out
        adj[e + MAX_NODE].push_back(s); adj[s].push_back(e + MAX_NODE);
        adj[s+MAX_NODE].push_back(e); adj[e].push_back(s + MAX_NODE);
    }
    //inner to outer
    for (auto i=3; i<=N; i++)
    {
        c[i][i+MAX_NODE] = 1;
        adj[i].push_back(i+MAX_NODE); 
        adj[i+MAX_NODE].push_back(i);
    }
    printf("%d\n",Maximum_Flow());
}