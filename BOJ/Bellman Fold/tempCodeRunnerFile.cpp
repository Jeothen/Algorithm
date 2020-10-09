#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = -1e9;
int dist[101];
int past[101];
bool visited[101];

vector<pair<int,int>>vc[101];
vector<pair<int,int>>rev_vc[101];

int main(){
    freopen("1738.txt","r",stdin);
    int n,m; scanf("%d %d",&n,&m);
    int u,v,w;
    for (int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        vc[u].push_back({v,w});
        rev_vc[v].push_back({u,w});
    }
    queue <int> q;
    q.push(n);
    while(!q.empty()){
        int node = q.front(); q.pop();
        for (auto &p: rev_vc[node]){
            int to = p.first;
            if (!visited[to]){
                visited[to] = true;  
                q.push(to);
            }
        }
    }
    if (!visited[1]) {
        printf("-1"); return 0;
    }
    fill(dist, dist+n+1, INF);
    dist[1] = 0;
    bool cycle = false;
    // bellman_ford
    for (int i=1;i <= n; i++){
        for (int j=1; j <=n; j++){
            for (auto &p: vc[j]){
                int next = p.first, val = p.second;
                if (dist[j] != INF && dist[j]+ val > dist[next]) {
                    dist[next] = dist[j] + val;
                    past[next] = j;
                    if (i == n && visited[next]) cycle = true;
                }
            }
        }
    }
    if (cycle) printf("-1\n");
    else {
        vector<int>ans;
        int node = n;
        while(node != 1){
            ans.push_back(node);
            node = past[node];
        }
        ans.push_back(1);
        for (int i=ans.size()-1; i>=0;i--){
            printf("%d ",ans[i]);
        }
    }
}
    