
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

const int MAX = 1000 + 1;

int arr[MAX][MAX], pSum[MAX][MAX];
int y[MAX], x[MAX];

//좌표 압축을 위해

unordered_map<int, int> yHash, xHash;

set<int> ySet, xSet;

int func(int y, int x, int y2, int x2)
{
	return pSum[y2][x2] - pSum[y2][x] - pSum[y][x2] + pSum[y][x];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> y[i] >> x[i];
		ySet.insert(y[i]);
		xSet.insert(x[i]);
	}
	int Y = 0, X = 0;
	for (int y : ySet)
		yHash[y] = Y++;
	for (int x : xSet)
		xHash[x] = X++;
	//좌표 압축한 결과
	for (int i = 0; i < N; i++)
		arr[yHash[y[i]]][xHash[x[i]]]++;
	//부분합 전처리
	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++)
			pSum[i + 1][j + 1] = pSum[i + 1][j] + pSum[i][j + 1] - pSum[i][j] + arr[i][j];
	int result = N;
	//i, j를 기준으로 울타리를 이어나갈 때 사분면에 존재하는 최소 소의 숫자를 구한다
	for (int i = 0; i <= X; i++)
		for (int j = 0; j <= Y; j++)
		{
			int temp = max(func(0, 0, i, j), func(i, j, Y, X));
			temp = max(temp, func(0, j, i, X));
			temp = max(temp, func(i, 0, Y, j));
			result = min(result, temp);
		}
	cout << result << "\n";
	return 0;
}