#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,pair<int,int>> st;
priority_queue<st, vector<st>, greater<st>>pq;
int parent[1001];

int find(int a){
    if (parent[a] < 0) return a;
    return parent[a] = find(parent[a]);
}

bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a ==b) return true;
    parent[b] = a;
    return false;
}

int main(){
    freopen("1922.txt","r",stdin);
    int n; scanf("%d",&n);
    int m; scanf("%d",&m);
    int a,b,c;
    for (int i=0; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        pq.push({c,{a,b}});
    }
    fill(parent,parent+n+1,-1);
    int answer = 0, cnt = 0;
    while(!pq.empty()){
        int val = pq.top().first, s = pq.top().second.first, e = pq.top().second.second;
        pq.pop();
        if (!unite(s,e)){
            answer += val;
            cnt++;
            if (cnt == n-1) break;
        }
    }
    printf("%d\n",answer);
}
