#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100
#define INF 100000000
using namespace std;

int N, M;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

void maxFlow(int start, int end)
{
    while (1)
    {
        fill(d, d + MAX, -1);
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < a[x].size(); i++)
            {
                int y = a[x][i];
                if (c[x][y] - f[x][y] > 0 && d[y] == -1)
                {
                    q.push(y);
                    d[y] = x; 
                    if (y == end)
                        break; 
                }
            }
        }
        if (d[end] == -1)
            break;
        int flow = INF;
        for (int i = end; i != start; i = d[i])
        {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }
        for (int i = end; i != start; i = d[i])
        {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
        result += flow;
    }
}

int main()
{
    freopen("2188.txt","r",stdin);
    scanf("%d %d",&N,&M);
    int s_node, e_node;
    for (int i=0; i<N; i++)
    {
        scanf("%d",&s_node);
        for (int j=0; j<s_node; j++)
        {
            scanf("%d",&e_node);
        } 
    }
}
