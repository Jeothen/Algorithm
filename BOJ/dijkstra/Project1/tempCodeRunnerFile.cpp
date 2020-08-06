#include <iostream>
#include <queue>
using namespace std;

int arr[101][101], N, M;

struct dir{
    int x, y;
};

dir d[4] = {{1,0},{-1,0},{0,-1},{0,1}};

bool notwall(int x, int y){
    if (x < 0 || x >= M) return false;
    if (y < 0 || y >= N) return false;
    return true;
}

int dijkstra(){
    priority_queue<pair<int, pair<int, int>>>pq;
    pq.push({0,{0,0}});
    int val, x, y;
    while(!pq.empty()){
        val = -pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        arr[y][x] = -1;
        pq.pop();
        cout << x <<  " " << y << " " << val << endl;
        if (x == M-1 && y == N-1) break;
        for (int i=0; i<4; i++){
            int nx = x + d[i].x, ny = y + d[i].y;
            if (notwall(nx,ny)){
                if (arr[ny][nx] == 1) {
                    pq.push({-val-1, {nx, ny}});
                    cout << -val-1 << nx << ny << endl;
                }
                else {
                    pq.push({-val, {nx,ny}});
                    cout << -val << " " << nx << ny << endl;
                }
            }
        }
    }
    cout << val << endl;
    return val;
}

int main(){
    freopen("1261.txt","r",stdin);
    scanf("%d %d",&N,&M);
    for (int i=0; i<N;i++){
        for (int j=0; j<M;j++) scanf("%d",&arr[i][j]);
    }
    printf("%d\n",dijkstra());
}