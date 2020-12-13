#include <iostream>
#Include <vector>
#include <algorithm>
using namespace std;
#define nodecount 100
#define INF 1e9
int dist[nodecount][nodecount];

void floyd_warshall(){
    // init dist
    fill_n(dist,dist+nodecount*nodecount; INF);
    
    for (int i=0; i<nodecount; i++){
        for (int j=0; j<nodecount; j++){
            if (i==j) dist[i][j] = 0;
            else {
                int a, b, c;
                dist[a-1][b-1] = c;
                // If Bidirectional,  j = i; j<nodecount; j++ ;    dist[a-1][b-1] = dist[b-1][a-1] = c;
            }
        }
    }
    for (int i=0; i<nodecount; i++){ // through node
        for (int src=0; src<nodecount; src++){ // source
            for (int tgt=0; tgt < nodecount; tgt++){ // target
                dist[src][tgt] = min(dist[src][i] + dist[i][tgt], dist[src][tgt]);
            }
        }
    }
}
