#include <iostream>
#include <vector>
#include <queue>
#include "string.h"
using namespace std;
#define NODE 501
#define INF 1'000'000'000

bool chk[NODE][NODE];
vector <pair<int,int>> vc[NODE];
vector <pair<int,int>> rev[NODE];

int dist[NODE];

void init(int N){
    for (int i=0; i<=N;i++) vc[i].clear();
    for (int i=0; i<=N; i++) rev[i].clear();
    memset(chk,false,sizeof(chk));
}

void dijkstra(int S, int E){
    bool visited[NODE] = {0,};
    fill(dist, dist + NODE, INF);
    priority_queue<pair<int,int>> pq;
    pq.push({0,S});
    dist[S] = 0;
    while(!pq.empty()){
        int acc = -pq.top().first, now = pq.top().second;
        pq.pop();
        if (now == E) break;
        if (visited[now]) continue;
        visited[now] = true;
        for (auto s : vc[now]) {
            int val = s.first, next = s.second;
            if (!visited[next] && !chk[now][next]){
                if (dist[next] > val + acc) {
                    dist[next] = acc + val;
                    pq.push({-dist[next],next});    
                }
            }
        }
    }
}

void delnode(int E, int S) {
    bool visited[NODE] = {0,};
    visited[E] = true;
    queue <pair<int,int>> q;
    q.push({dist[E], E});
    while(!q.empty()){
        int acc = q.front().first, now = q.front().second; 
        q.pop();
        for (auto p : rev[now]){
            int val = p.first, next = p.second;
            if (dist[next] + val == acc) {
                chk[next][now] = true;
                q.push({dist[next], next});
            }
        }
    }
}

int main(){
    freopen("5719.txt","r",stdin);
    while(1){
        int N,M; scanf("%d %d",&N,&M);
        if (N == 0 && M == 0) break;
        int S,E; scanf("%d %d",&S,&E);
        int u,v,p;
        init(N);

        for (int i=0; i<M;i++) {
            scanf("%d %d %d",&u,&v,&p);
            vc[u].push_back({p,v});
            rev[v].push_back({p,u});
        }
        dijkstra(S,E);
        delnode(E,S);
        dijkstra(S,E);
        if (dist[E] == INF) printf("-1\n");
        else printf("%d\n",dist[E]);
    }
    
}