#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define node 1001
#define INF 100'000'000
int n, dist[node];
vector <pair<int,int>> vc[node];

void dijkstra(){
    memset(dist,100,sizeof(dist));
    for (int i=2;i<=n;i++) cout << dist[i] << endl;
    dist[1] = 0;
    priority_queue<pair<int,int>>pq;  // distance, index
    bool visit[node]; memset(visit,false,sizeof(visit));
    cout << endl;
    pq.push({0,1});
    while(!pq.empty()){
        int val = pq.top().first, idx = pq.top().second;
        visit[idx] = true;
        pq.pop();
        for (auto i=0; i<vc[idx].size(); i++){
            int d = vc[idx][i].first, nidx = vc[idx][i].second;
            cout << d << endl;
            if (!visit[nidx]){
                if (d + val < dist[nidx]){
                    dist[nidx] = d + val;
                    pq.push({dist[nidx], nidx});
                }
            } 
        }
    }
    for (int i=2; i<=n;i++){
        if (dist[i] != INF){
            printf("%d %d\n", i, dist[i]);
        }
    }
}

int main(){
    freopen("2211.txt","r",stdin);
    int m; scanf("%d %d",&n,&m);
    int a,b,c;
    for (int i=0; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        vc[a].push_back({c,b});
        vc[b].push_back({c,a});
    }
    dijkstra();
}