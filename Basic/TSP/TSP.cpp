#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define INF 1e9;
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

char lists[17];
int n, cnt, dist[17][17], dp[17][1 << 16];

// Traveling Salesman Problem
int TSP(int cur, int visit)  // cur : current / visit = sum of visit city  - 5 : 0 1 0 1
{
	if (visit == (1 << n) - 1) // all city visit   ( if n == 4  ->  visit == 16000 - 1 = 1111 : 1 2 3 4)
	{
	/*	if (arr[cur][0] != 0) // possible to return start point
			return arr[cur][0];
		return INF;				// Imposibble to return start point
	*/
		return dist[cur][0] ? dist[cur][0] : INF;
	}
	int& ret = dp[cur][visit];
	if (ret != -1) return ret; // already visit  cur -> visit 

	ret = INF;
	for (int next = 0; next < n; next++)
	{
		if (visit & (1 << next)) continue;					// already vit city i
		if (dist[cur][next] == 0) continue;					// not destinated
		ret = MIN(ret, dist[cur][next] + TSP(next, visit | (1 << next))); // minimum distance  current->next + tsp(start next)
	}
	// minimum of current to visit
	return ret;
}

void Solve(){
	memset(dp, -1, sizeof(dp)); // 4 (int) * 2^16 (1<<16) * 17
	printf("%d\n", TSP(0, 1));	// if INF, Not TSP;
}
