#include <iostream>
#include "string.h"
#include <queue>
using namespace std;

#define INF 1e9
typedef pair<int,pair<int,int>> pp;
const int nodecount = 1001;
int dist[nodecount], start, idx;
vector<pp> vc[nodecount];

int prim(){
	priority_queue<pp, vector<pp>, greater<pp>> pq;
	for (auto& p : vc[start]) pq.push(p);  // start node edge upload
	fill_n(dist,sizeof(dist),INF);
	int ret = 0;
	dist[start] = -1;

	while(!pq.empty()){
		int val = pq.top().first;
		pair<int,int> node = pq.top().second;
		if (dist[node.first] == -1) continue; // already visited
		dist[node.first] = -1; // start visited check
		pq.pop();
		for (auto& p: vc[node.second]) {
			if (dist[p.second.first] != -1) // not visited
				pq.push(p);
		}
		ret += val;
		// if n count break;
	}
	return ret;
}



int square_n(){
	int graph[nodecount][nodecount];
	fill_n(graph, sizeof(graph),INF); // default : not arrived
	// input graph a->b = c
	for (int i=1; i<=nodecount; i++){
        graph[i][i] = 0;
    }    
	int ret = 0;
	for (int i = 1; i <= nodecount; i++)
		dist[i] = graph[start][i]; // if not arrived, INF

	dist[start] = -1; // -1 is visited
	for (int i = 1; i < nodecount; i++) // mst need to find minimum distance from node to node 
	{
		int minimum = INF;
		for (int j = 1; j <= nodecount; j++)
		{
			if (dist[j] != -1) {
				if (minimum > dist[j]) {
					minimum = dist[j];
					idx = j;
				}
			}
		}
		ret += minimum;  // plus minimum distance
		dist[idx] = -1; // idx is visited (minimum distance index)
		for (int j = 1; j <= nodecount; j++) { // update if  idx to j is smaller than original distance to j
			if (dist[j] > graph[idx][j]) dist[j] = graph[idx][j];
		}
	}
	return ret;
}
