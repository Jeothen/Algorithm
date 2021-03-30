#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
int N, M;
#define MAX_NODE 402
#define INF 2'000'000'000

int f[MAX_NODE][MAX_NODE], c[MAX_NODE][MAX_NODE];

int min(int a, int b){
    return a > b ? b : a;
}

int max_flow()
{
    int res = 0;
    int s = 0, e = N+M+1;
    int prev[MAX_NODE];
    while(1)
    {
        memset(prev,-1,sizeof(prev));
        std::queue<int> q;
        q.push(s);
        while (!q.empty() && prev[e] == -1)
        {
            int cur = q.front(); q.pop();
            for (int next = 0; next <= N+M+1; next++) // all ways needed, if there's a way capacity is positive
            { 
                if (prev[next] == -1 && c[cur][next] > f[cur][next]) 
                {
                    q.push(next);
                    prev[next] = cur;
                    if (next == e) break;
                }
            }
        }
        if (prev[e] == -1) break;
        int min_flow = INF;
        for (auto i = e; i != s; i = prev[i])
        {
            min_flow = min(min_flow, c[prev[i]][i]-f[prev[i]][i]);
        }
        for (auto i = e; i != s; i = prev[i])
        {
            f[prev[i]][i] += min_flow; f[i][prev[i]] -= min_flow;
        }
        res += min_flow;
    }
    return res;
}   

int main()
{
    freopen("2188.txt","r",stdin);
    scanf("%d %d",&N,&M);
    for (int i=1;i<=N;i++)
    {
        int val, S; scanf("%d",&S);
        for (int j=0; j<S;j++)
        {
            scanf("%d",&val);
            val += N;
            // if there's a biparate matching, reverse way is not associate. just one way
            c[i][val] = 1;
        }
    }
    // virtual start 0, end node 401
    for (int i=1; i<=N;i++)
    {
        c[0][i] = 1; 
    }
    for (int i=1; i<=M; i++)
    {
        c[i +N][N+M+1] = 1;
    }
    printf("%d\n",max_flow());
}