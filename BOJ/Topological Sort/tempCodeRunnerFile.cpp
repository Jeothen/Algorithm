#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector <int> adj[1001];
bool visited[1001], chk[1001], cycle;
vector <int> ans;

void dfs(int now){
    visited[now] = true;
    for (auto next: adj[now]) {
        if (!visited[next]) dfs(next);
        else if (!chk[next]) cycle = true;; // visited & chk 안 된 경우 -> cycle
    }
    chk[now] = true;
    ans.push_back(now);
}

int main(){
    freopen("2623.txt","r",stdin);
    int N,M, cnt, val;
    scanf("%d %d", &N, &M);
    cycle = false;
    memset(chk, false, sizeof(chk));
    memset(visited, false, sizeof(visited));
    for (int i=0;i<M;++i){
        vector<int> tmp = {};
        scanf("%d",&cnt);
        for (int j=0; j<cnt; ++j) {
            scanf("%d",&val); tmp.push_back(val);
            if (j) adj[tmp[j-1]].push_back(val);
        } 
    }
    for (int i=1; i<=N; i++) if(!cycle && !visited[i]) dfs(i);
    reverse(ans.begin(), ans.end());
    if (cycle) puts("0");
    for (auto output:ans) cout << output << endl;
}