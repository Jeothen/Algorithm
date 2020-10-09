#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
vector<pair<int,int>>vc[501];
ll dist[501];

int main(){
    freopen("11657.txt","r",stdin);
    int n,m; scanf("%d %d",&n,&m);
    int a,b,c;
    for (int i=0; i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        vc[a].push_back({b,c});
    }
    fill(dist, dist+n+1, INF);
    dist[1] = 0;
    bool cycle = false;
    for (int i=0; i<n; i++){ // loop
        for (int j=1; j<=n; j++) { // start point
            for (auto &p: vc[j]){
                int next = p.first, val = p.second;
                if (dist[j] != INF && dist[next] > dist[j] + val) {
                    dist[next] = dist[j] + val;
                    if (i == n-1) cycle = true; // last loop에서 update
                } 
            }
        }
    }
    if (cycle) printf("-1\n");
    else {
        for (int i=2;i<=n;i++) {
            printf("%lld\n",dist[i]!=INF?dist[i]:-1);
        }
    }
}