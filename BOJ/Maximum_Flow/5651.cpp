#include <iostream>
#include <vector>
#include <queue>

#define MAX_NODE 301
#define START 1
#define INF 1'000'000'000

int F[MAX_NODE][MAX_NODE], C[MAX_NODE][MAX_NODE], CNT[MAX_NODE][MAX_NODE];
std::vector<int>adj[MAX_NODE];
int path[MAX_NODE];

void init()
{
    memset(F,0,sizeof(F));
    memset(C,0,sizeof(C));
    for (int i=0;i<MAX_NODE;i++) adj[i].clear();
}

int min(int a, int b)
{
    return a > b ? b : a;
}

bool other_path(int source, int target)
{
    std::queue<int>q; q.push(source);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto next : adj[cur])
        {
            if (!(cur == source && next == target) && C[cur][next] > F[cur][next]) 
            {
                if (next == target) return true;
                q.push(next);
            }
        }
    }
    return false;
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
        for (int i = END; i != START; i = prev[i]) path[i] = prev[i];
        int min_flow = INF;
        for (auto i = END; i != START; i = prev[i])
        {
            min_flow = min(C[prev[i]][i]-F[prev[i]][i], min_flow);
        }
        for (int i = END; i != START; i = prev[i])
        {
            F[prev[i]][i] += min_flow;
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
            C[f][t] = b;
            CNT[f][t] += 1;
        }
        maximum_flow(N);
        int res = 0;
        for (int i= N; i != START; i = path[i]) 
        {
            if ( C[path[i]][i] == F[path[i]][i] && !other_path(path[i], i)) res += CNT[path[i]][i];
        }
        printf("%d\n",res);
    }
}