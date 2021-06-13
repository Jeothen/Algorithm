#include <iostream>
#include <string.h>
#include <vector>
#define MAX_ 1001
int N, M;
int book[MAX_], people[MAX_];
int range[MAX_][2];
bool visited[MAX_];

void init()
{
    memset(range,0,sizeof(range));
    scanf("%d %d", &N, &M);
}

bool dfs(int cur)
{
    visited[cur] = true;
    for (int i = range[cur][0]; i <= range[cur][1]; i++)
    {
        if (book[i] == -1 || (!visited[book[i]] && dfs(book[i])))
        {
            book[i] = cur;
            people[cur] = i;
            return true;
        }
    }
    return false;
}

int biparite_matching()
{
    int res = 0;
    memset(book, -1, sizeof(book));
    memset(people, -1, sizeof(people));
    for (int i=1; i<=M; i++)
    {
        if (people[i] == -1)
        {
            memset(visited,false,sizeof(visited));
            if (dfs(i)) res++;
        }
    }


    return res;
}

int main()
{
    freopen("9576.txt","r",stdin);
    int tc; scanf("%d",&tc);
    while(tc--)
    {
        int a,b;
        init();
        for (int i=1; i<= M; i++)
        {
            scanf("%d %d",&a,&b);
            range[i][0] = a; range[i][1] = b;
        }
        printf("%d\n",biparite_matching());
    }
}