#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define node 1001
#define INF 100000000
int n, dist[node];

vector <pair<int,int>> vc[node];
int link[node];

void dijkstra(){
    fill(dist, dist+node, INF);
    fill(link, link + node, -1);
    dist[1] = 0;
    priority_queue<pair<int,int>>pq;  // distance, index

    pq.push({0,1}); 
    while(!pq.empty()){
        int val = pq.top().first, idx = pq.top().second;
        pq.pop();
        for (auto i=0; i<vc[idx].size(); i++){
            int d = vc[idx][i].first, next = vc[idx][i].second;
            if (d + val < dist[next]) {
                dist[next] = d + val; // minimum distance
                pq.push({ dist[next], next });
                link[next] = idx;
            }
        }

    }
    int cnt = 0;
    for (int i=1; i<=n;i++){
        if (link[i] != -1) cnt++;
    }
    printf("%d\n",cnt);
    for (int i=1; i<=n; i++){
        if (link[i] !=-1) printf("%d %d\n",i, link[i]);
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