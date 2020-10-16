#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 2e5+1;

int p[N];

struct node {
    int x,y,z;
    bool operator<(const node& n) const{
        return z < n.z;
    }
}query[N];

int find(int a){
    if (p[a] == -1) return a;
    return p[a] = find(p[a]);
}


int main(){
    freopen("6497.txt","r",stdin);
    int m,n;
    for (;;) {
        scanf("%d %d",&m,&n);
        if (!n && !m) break;
        fill(p,p+n+1,-1);
        int answer = 0;
        for (int i=0; i < n; ++i){
            scanf("%d %d %d",&query[i].x,&query[i].y,&query[i].z);
            answer += query[i].z;
        }
        sort(query,query+n);
        int cnt = 0;
        for (int i=0;;++i){
            int s = find(query[i].x), e = find(query[i].y);
            if (s != e) {
                p[e] = s;
                answer -= query[i].z;
                if (++cnt == m-1) break;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}