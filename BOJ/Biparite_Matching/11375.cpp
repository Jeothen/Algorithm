#include <iostream>
#include <vector>

#define MAX_NODE 1001
int N,M;

std::vector<std::vector<int>>vc;
int people[MAX_NODE], work[MAX_NODE];
bool visited[MAX_NODE];

bool dfs(int n)
{
    visited[n] = true;
    for (auto next : vc[n])
    {
        if (work[next] == -1 || (!visited[work[next]] && dfs(work[next])))
        {
            work[next] = n;
            people[n] = next;
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
    for (int i=1; i<=N; i++)
    {
        if (people[i] == -1) // not visited
        {
            memset(visited,false,sizeof(visited));
            if (dfs(i)) res++;
        }
    }
    return res;
}

int main()
{
    freopen("11375.txt","r",stdin);
    scanf("%d %d",&N,&M);
    vc.resize(N+1,std::vector<int>(0,0));
    int cnt, val;
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&cnt);
        for (int j=0; j<cnt;j++)
        {
            scanf("%d",&val);
            vc[i].push_back(val);
        }
    }
    printf("%d\n",biparite_matching());
}