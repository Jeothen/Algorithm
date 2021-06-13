#include <iostream>
#include <vector>
#include <string.h>
#define MAX_NODE 201
int N,M;
std::vector<int> adj[MAX_NODE];

int cow[MAX_NODE], loc[MAX_NODE];
bool visited[MAX_NODE];

bool dfs(int cur)
{
    visited[cur] = true;
    for (int next : adj[cur])
    {
        if (loc[next] == -1 || (!visited[loc[next]] && dfs(loc[next])))
        {
            cow[cur] = next;
            loc[next] = cur;
            return true;
        } 
    }

    return false;
}

int biparite_matching(int n)
{
    memset(cow, -1, sizeof(cow));
    memset(loc, -1, sizeof(loc));
    int res = 0;
    for (int i=1; i <= n; i++)
    {
        if (cow[i] == -1) // not visit
        {
            memset(visited, false,sizeof(visited));
            if (dfs(i)) res++;
        }
    }
    return res;
}

int main()
{
    freopen("2188.txt","r",stdin);
    scanf("%d %d", &N, &M);
    int cnt, val;
    for (int i=1; i<=N; i++)
    {
        scanf("%d",&cnt);
        for (int j=0;j<cnt; j++)
        {
            scanf("%d",&val);
            adj[i].push_back(val);
        }
    }
    printf("%d\n",biparite_matching(N));
}