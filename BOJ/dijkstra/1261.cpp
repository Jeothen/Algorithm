#include <iostream>
#include <queue>
using namespace std;

int arr[101][101], N, M;

struct dir{
    int x, y;
};

dir d[4] = {{1,0},{-1,0},{0,-1},{0,1}};

bool notwall(int x, int y){
    if (x < 0 || x >= N) return false;
    if (y < 0 || y >= M) return false;
    return true;
}

int dijkstra(){
    priority_queue<pair<int,pair<int,int>>>pq;
    pq.push({0,{0,0}});
    int val, x, y;
    while(!pq.empty()){
        val = -pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();
        if (x == N-1 && y == M-1) break;
        for (int i=0; i<4; i++){
            int nx = x + d[i].x, ny = y + d[i].y;
            if (notwall(nx,ny)){
                if (arr[ny][nx] == 1) {
                    pq.push({-val-1, {nx, ny}});
                }
                else if (arr[ny][nx] == 0) {
                    pq.push({-val, {nx,ny}});
                }
                arr[ny][nx] = -1;
            }
        }
    }
    return val;
}

int main(){
    freopen("1261.txt","r",stdin);
    scanf("%d %d",&N,&M);
    for (int i=0; i<M;i++){
        for (int j=0; j<N;j++) scanf("%1d",&arr[i][j]);
    }
    printf("%d\n",dijkstra());
}