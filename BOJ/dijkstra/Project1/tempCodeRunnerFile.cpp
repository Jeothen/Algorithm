#include <iostream>
#include <vector>
#include <queue>
#include "string.h"
using namespace std;
#define MAX_NODE 100'001
#define INF 1'000'000'000

typedef long long ll;

int N,M,D,E; int height[MAX_NODE];
vector <pair<int,int>> vc[MAX_NODE];

ll dist[MAX_NODE][2];

// H * E - D * dist   dist(최소)

void dijkstra(int start){
    int col = 0;
    if (start == N) col = 1;
    bool     visited[MAX_NODE] = {0,};
    priority_queue<pair<ll,int> > pq; //거리, point
 //   memset(visited,false,sizeof(visited));

    pq.push({0,start});
    while(!pq.empty()){
        ll acc = -pq.top().first; int now = pq.top().second;
        visited[now] = true;
        pq.pop();
        for (int i = 0; i < vc[now].size();i++){
            int dis = vc[now][i].first, next = vc[now][i].second;
            if (!visited[next] && height[next] > height[now]) {
                if (acc + dis < dist[next][col]){
                    dist[next][col] = acc + dis;
                    pq.push({-dist[next][col], next});
                }   
            }
        }
    }
}

int main(){
    freopen("16681.txt","r",stdin);
    scanf("%d %d %d %d",&N,&M,&D,&E);
    for (int i=1; i <= N; i++) scanf("%d",&height[i]);
    int a,b,n;
    for (int i=0;i<M;i++){
        scanf("%d %d %d",&a,&b,&n);
        vc[a].push_back({n,b});
        vc[b].push_back({n,a});
    }

    ll ans = -INF, tmp = -INF;
    for (int i=2; i<N;i++){
        dist[i][0] = INF; dist[i][1] = INF;
    }
    dijkstra(1); dijkstra(N);

    for (int i=2; i<N; i++){
        if (dist[i][0] == INF || dist[i][1] == INF) continue;
        tmp = height[i] * E - D * (dist[i][0] + dist[i][1]);
        ans =  max(tmp,ans);
    }
    if (ans != -INF) printf("%lld\n", ans);
    else printf("Impossible\n");
}