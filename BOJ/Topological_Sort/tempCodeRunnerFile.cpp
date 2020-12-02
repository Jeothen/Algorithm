#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];
int indegree[1001];
int ans[1001];
int N, M;
queue<int> q;

void solve()
{
    for (int i=1; i<=N; i++) if (!indegree[i]) q.push(i);  // 이전 값이 없는 node
    // topological sort
    for (int i=1; i<=N; i++){ // N개
        if (q.empty()) {
            cout << 0 << endl;
            return;
        }
        int curr = q.front();  q.pop();
        ans[i] = curr;
        for (auto next : adj[curr]){
            if (!--indegree[next]) q.push(next);
        }
    }
    for (int i=1; i<=N; ++i) cout << ans[i] << endl;
}

int main()
{
    freopen("2623.txt", "r", stdin);
    int cnt, prev, curr;
    cycle = false;
    scanf("%d %d", &N, &M);
    fill(indegree,indegree+N+1, 0);
    for (int i = 0; i < M; ++i)
    {
        vector<int> tmp = {};
        scanf("%d", &cnt);
        scanf("%d", &prev);
        for (int j = 0; j < cnt-1; ++j)
        {
            scanf("%d", &curr);
            adj[prev].push_back(curr);
            indegree[curr]++;
            prev = curr;
        }
    }
    solve();
}


    /*
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
}*/