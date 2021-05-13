#include <iostream>
#include <vector>
#include <queue>

#define MAX_NODE 301

int f[MAX_NODE][MAX_NODE], c[MAX_NODE][MAX_NODE];
std::vector<int>adj[MAX_NODE];

void init()
{
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(c));
    for (int i=0;i<MAX_NODE;i++) adj[i].clear();
}

int maximum_flow(int target)
{
    int res = 0;
    

    return res;
}

int main()
{
    freopen("5651.txt","r",stdin);
    int K; scanf("%d",&K);
    for (int tc=1; tc <= K; tc++)
    {
        int N, M; scanf("%d %d",&N,&M);
        init();
        int f,t,b;
        for (int i=0; i<M; i++)
        {
            scanf("%d %d %d",&f,&t,&b);
            adj[f][t] = b;
            c[f][t] = 1;
        }
        printf("%d",maximum_flow(N));
    }
}