#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int INF = 1e9;
int dist[101][101];

int main(){
    freopen("11404.txt","r",stdin);
    int n,m; scanf("%d %d",&n,&m);
    fill(&dist[1][1],&dist[n+1][n+1],INF);

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    int a, b, c;

    for (int i=0; i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        dist[a][b] = min(dist[a][b],c);
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }

        for (int z = 1; z <= n; z++)
        {
            for (int y = 1; y <= n; y++)
            {
                printf("%d ", dist[z][y]);
            }
            printf("\n");
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) printf("0 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}