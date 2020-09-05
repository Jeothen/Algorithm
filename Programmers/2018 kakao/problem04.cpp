#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

char arr[30][30];

void getarr(string str, int row)
{
    for (int i = 0; i < str.size(); i++)
    {
        arr[row][i] = str[i];
    }
}

int del_box(const int &m, const int &n)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i + 1][j]) && (arr[i][j] == arr[i + 1][j + 1]))
            {
                if (arr[i][j] != '0')
                {
                    q.push({i, j});
                    cnt++;
                }
            }
        }
    }

    while (!q.empty())
    {
        int y = q.front().first, x = q.front().second;
        q.pop();
        for (int i = y; i <= y + 1; i++)
        {
            for (int j = x; j <= x + 1; j++)
                arr[i][j] = '0';
        }
    }
    return cnt;
}

void move_down(const int &m, const int &n)
{
    for (int i = 0; i < n; i++)
    {
        queue<char> q;
        for (int j = m - 1; j >= 0; j--)
        {
            if (arr[j][i] != '0')
            {
                q.push(arr[j][i]);
                arr[j][i] = '0';
            }
        }
        int idx = m - 1;
        while (!q.empty())
        {
            char tmp = q.front();
            q.pop();
            arr[idx--][i] = tmp;
        }
    }
}

int solution(int m, int n, vector<string> board)
{
    for (int i = 0; i < board.size(); i++)
        getarr(board[i], i);
    while (del_box(m, n))
        move_down(m, n);

    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (arr[i][j] == '0') answer++;
    }
    return answer;
}

int main() {

    int m = 4, n = 5;
    vector<string> board = {"aaaaa", "aaaaa", "aaaaa", "aaaaa"};
    cout << solution(m,n,board) << endl;
}