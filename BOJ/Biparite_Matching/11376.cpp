#include <iostream>
#include <vector>
#include <string.h>
#define MAX_NODE 1001

int N, M;

std::vector<std::vector<int>> vc;
int people[2 * MAX_NODE], work[MAX_NODE];
bool visited[2 * MAX_NODE];

bool dfs(int n)
{
    visited[n] = true;
    for (auto i : vc[n])
    {
        if (work[i] == -1 || (!visited[work[i]] && dfs(work[i])))
        {
            work[i] = n;
            people[n] = i;
            return true;
        }
    }
    return false;
}

int biparite_matching()
{
    int res = 0;
    memset(people, -1, sizeof(people));
    memset(work, -1, sizeof(work));
    for (int i = 0; i < 2 * N; i++)
    {
        memset(visited, false, sizeof(visited));
        if (dfs(i/2)) res++;
    }
    return res;
}
/*
bool dfs(int n)
{
    visited[n] = true;
    for (auto i : vc[n])
    {
        if (work[i] == -1 || (!visited[work[i]] && dfs(work[i])))
        {
            work[i] = n;
            people[n] = i;
            return true;
        }
    }
    return false;
}

int biparite_matching()
{
    int res = 0;
    memset(people, -1, sizeof(people));
    memset(work, -1, sizeof(work));
    for (int i = 1; i <= 2 * N; i++)
    {
        if (people[i] == -1)
        {
            memset(visited, false, sizeof(visited));
            if (dfs(i))
                res++;
        }
        else if (people[N + i] == -1)
        {
            memset(visited, false, sizeof(visited));
            if (dfs(i))
                res++;
        }
    }
    return res;
}
*/
int main()
{
    freopen("11376.txt","r",stdin);
    scanf("%d %d", &N, &M);
    vc.resize(2 * N + 1, std::vector<int>(0, 0));
    int cnt, val;
//    for (int i = 1; i <= N; i++)
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; j++)
        {
            scanf("%d", &val);
            vc[i].push_back(val);
            vc[N + i].push_back(val);
        }
    }
    printf("%d\n", biparite_matching());
}
