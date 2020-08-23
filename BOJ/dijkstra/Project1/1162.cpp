#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define city 10001
#define packing 21
#define INF 100'000'000'000
typedef long long ll;
ll dist[city][packing];
vector <pair<int,int>> vc[city];

int N,M,K,a,b,c;
bool visited[city][packing]{0,};

void init(){
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        vc[a].push_back({c, b});
        vc[b].push_back({c, a});
    }
    for (int i=1; i<=N;i++){
        for (int j=0; j<=K;j++) {
            if (i==1) dist[i][j] = 0;
            else dist[i][j] = INF;
            visited[i][j] = false;
        }
    }
}

void dijkstra(){
    int s = 1, e = N;
    priority_queue<pair<ll,pair<int,int>>>pq; // value, city, k 
    pq.push({0,{1,0}});
    while(!pq.empty()){
        ll acc = -pq.top().first;
        int city_num = pq.top().second.first, k_val = pq.top().second.second;
        pq.pop();
        if (visited[city_num][k_val]) continue;
        visited[city_num][k_val] = true;        
        for (auto info : vc[city_num]) {
            if (!visited[info.second][k_val]) {
                if (info.first + acc < dist[info.second][k_val]) {
                    dist[info.second][k_val] = info.first + acc;
                    pq.push({-dist[info.second][k_val],{info.second,k_val}});
                }
            }
            if (k_val < K) {
                if (!visited[info.second][k_val+1]){
                    if (acc < dist[info.second][k_val+1])
                    {
                        dist[info.second][k_val+1] = acc;
                        pq.push({-dist[info.second][k_val+1], {info.second, k_val+1}});
                    }
                }
            }
        }
    }

}

int main(){
    freopen("1162.txt","r",stdin);
    init();
    dijkstra();
    ll maximum = INF;
    for (int i=0; i<=K; i++) {
        maximum = (dist[N][i] < maximum) ? dist[N][i] : maximum;
    }
    printf("%lld\n",maximum);
}