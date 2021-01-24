#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int max_Ver = 4;

vector<int> adj[max_Ver];
bool visited[max_Ver];

void dfs(){

}

bool is_connected(){
    
} 

int check_eulerian()
{
    if (!is_connected()) return 0;

    vector<int> inward(max_Ver, 0);
    vector<int> outward(max_Ver, 0);

    for (int i = 0; i < max_Ver; i++)
    {
        int sum = 0;
        for (int j = 0; j < max_Ver; j++)
        {
            if (adj[i][j])
            {
                inward[j]++; 
                sum++;       
            }
        }
        outward[i] = sum;
    }

    return 0;
}

void init()
{
    memset(visited, 0, sizeof(visited));
    if (check_eulerian() == 2) printf("Eulerian Cycle");
    else if (check_eulerian() == 1) printf("Eulerian Path");
    else printf("Not Eulerian");
}

int main()
{
    init();
}