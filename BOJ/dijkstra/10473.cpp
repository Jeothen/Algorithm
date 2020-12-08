#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#define node 102
#define INF 987764321
int n;
double sx,sy,ex,ey, point[node][2];

double calt(const double& x1, const double& y1, const double& x2, const double& y2) {
    double dist =  sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    return min(dist/5,abs(dist - 50)/5 + 2);
}

double dijkstra(){
    
    priority_queue<pair<double,pair<int,pair<double,double>>>>pq;
    pq.push({0,{0,{point[0][0],point[0][1]}}});
    bool visit[node]; memset(visit,false,sizeof(visit));
    double t[node]; memset(t,INF,sizeof(t));
    bool flag = false;
    while(!pq.empty()){
        double val = -pq.top().first; // time
        int idx = pq.top().second.first;
        double x = pq.top().second.second.first, y = pq.top().second.second.second;
        pq.pop();
        if (visit[idx]) continue;
        visit[idx] = true;
        for (int i=1; i<=n+1 ;i++){ // maximum n * n
            if (!visit[i]){
                double nt;
                if (flag) nt = calt(x, y, point[i][0], point[i][1]);
                else nt = sqrt((x-point[i][0])*(x-point[i][0]) + (y-point[i][1])*(y-point[i][1]))/5;

                if (t[i] > nt + val) {
                    t[i] = nt + val;
                    pq.push({-t[i],{i,{point[i][0],point[i][1]}}});
                }
            }
        }
        flag = true;
    }
    return t[n+1];
}

int main(){
    freopen("10473.txt","r",stdin);
    scanf("%lf %lf", &sx, &sy);
    scanf("%lf %lf", &ex, &ey);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%lf %lf",&point[i][0], &point[i][1]);
    }
    point[0][0] = sx, point[0][1] = sy;
    point[n+1][0] = ex, point[n+1][1] = ey;
    printf("%.6f",dijkstra());
    return 0;
}