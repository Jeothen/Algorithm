#include <iostream>
#include <vector>
using namespace std;
#define ROAD 10000
typedef long long ll;

bool chk[ROAD][ROAD];
vector <pair<ll,int>> vc[ROAD];

int main(){
    freopen("1162.txt","r",stdin);
    int N,M,K,a,b,c;
    scanf("%d %d %d",&N,&M,&K);
    for (int i=0; i< M; i++){
        scanf("%d %d %d",&a,&b,&c);
        vc[a].push_back({c,b});
        vc[b].push_back({c,a});
    }

}