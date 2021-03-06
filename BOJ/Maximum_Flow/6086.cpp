#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
// 65 ~ 90 / 97 ~ 122
#define MAX_NODE 60
#define INF 2'100'000'000

int min(int a, int b){
    return a > b ? b : a;
}

int f[MAX_NODE][MAX_NODE]; // flow
int c[MAX_NODE][MAX_NODE]; // capacity
std::vector <int> adj[MAX_NODE]; // adjacent


int maximum_flow(){
    int res = 0;
    int start = 'A'-'A', end = 'Z'-'A';
    int prev[MAX_NODE]; // register previous path
    while(1)
    {
        memset(prev,-1,sizeof(prev));
        // Edmond-Karp Algorithm - BFS
        std::queue<int> q; q.push(start);
        while(!q.empty() && prev[end] == -1)
        {
            int cur = q.front(); q.pop();
            for (auto next : adj[cur])
            {
                if (c[cur][next] > f[cur][next] && prev[next] == -1)  // capacity is bigger than flow / next is not visited
                {
                    q.push(next);
                    prev[next] = cur;
                    if (next == end) break; // arrived end node
                }
            }
        }
        if (prev[end] == -1) break; // there's no way to end node

        int min_flow = INF;
        for (auto i = end; i != start; i =prev[i])
        {
            min_flow = min(min_flow, c[prev[i]][i]-f[prev[i]][i]);
        }

        // Flow min_flow 
        for (auto i=end; i != start; i = prev[i])
        {
            f[prev[i]][i] += min_flow;
            f[i][prev[i]] -= min_flow;  // reverse way
        }
        res += min_flow;
    }
    return res;
}

int main()
{
    freopen("6086.txt","r",stdin);
    int N; scanf("%d",&N);
    char F, S; int V;
    for (auto i=0; i<N; ++i) {
        scanf(" %1c %1c %d",&F,&S,&V);
        int s = F-'A', e = S-'A';
        // paraller
        c[s][e] += V; c[e][s] += V;
        adj[s].push_back(e);
        adj[e].push_back(s); // reverse way
    }
    printf("%d",maximum_flow());
}