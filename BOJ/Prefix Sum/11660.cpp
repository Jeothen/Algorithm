#include <stdio.h>

int psum[1025][1025];
int main(){
    freopen("11660.txt","r",stdin);
    int val, n, m; scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d",&val);
            psum[i+1][j+1] = psum[i][j+1] + psum[i+1][j] - psum[i][j] + val;
        }
    }
    // x - row / y - col
    for (int i=0; i <m ;i++){
        int x1,y1,x2,y2; scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",psum[x2][y2]-psum[x2][y1-1]-psum[x1-1][y2]+psum[x1-1][y1-1]);
    }
}