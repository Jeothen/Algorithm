#include<stdio.h>
using namespace std;

int psum[100001];

int main(){
    freopen("11659.txt","r",stdin);
    int val, n,m; scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++) {
        scanf("%d",&val);
        psum[i+1] = psum[i] + val;
    }
    int s,e;
    for (int i=0; i<m;i++){
        scanf("%d %d",&s,&e);
        printf("%d\n",psum[e]-psum[s-1]);
    }
}