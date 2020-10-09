#include <cstdio>

int dist[101][101];

int main(){
    freopen("11403.txt","r",stdin);
    int n; scanf("%d",&n);
    for (int i=1; i<= n; i++){
        for (int j=1; j<=n; j++){
            scanf("%d",&dist[i][j]);
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n ;j++) {
            for (int k=1; k <=n; k++) {
                if (dist[j][i] && dist[i][k]) dist[j][k] = 1;
            }
        }
    }   
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) {
            if (dist[i][j]) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
}