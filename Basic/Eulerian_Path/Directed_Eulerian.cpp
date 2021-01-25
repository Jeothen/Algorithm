#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int max_Ver = 4;

bool visited[max_Ver];
vector<int>adj[max_Ver];

void dfs(vector<int>* vc, int idx){

}

vector<int>* create_rev_adj(){  
    vector<int>rev[max_Ver];
    for (int i=0; i<max_Ver;i++){
        for (int j=0; j<adj[i].size();j++){
            rev[j].push_back(i);
        }
    }
    return rev;
}

bool is_connected(){

    memset(visited, 0, sizeof(visited));
    int idx;
    for (idx = 0; idx < max_Ver; idx++)
    {
        if (adj[idx].size() != 0)
            break;
    }
    dfs(adj,idx);
    for (int i = 0; i < max_Ver; i++)
    {
        if (!visited[i] && adj[i].size())
            return false; // if node exists but not visited
    }
    // reverse graph
    vector<int> *rev_adj;
    rev_adj = create_rev_adj(adj);


} 

int check_eulerian()
{
    if (!is_connected()) return 0;

    vector<int> inward(max_Ver, 0);
    vector<int> outward(max_Ver, 0);

    for (int i = 0; i < max_Ver; i++)
    {
        for (int j = 0; j < max_Ver; j++)
        {
            if (adj[i][j])
            {
                inward[j]++; 
                outward[i]++;
            }
        }
    }
    bool path_in = false;
    bool path_out = false;

    bool chk_path = true;
    bool chk_cycle = true;
    for (int i=0;i<max_Ver;i++){
        if (inward[i] != outward[i]) {
            chk_cycle = false;
            if (inward[i]+1 == outward[i]) {
                if (path_in) { chk_path = false; break; }
                path_in = true;
            }
            else if (inward[i] == outward[i] + 1){
                if (path_out) { chk_path = false; break; }
                path_out = true;
            }
        }
    }
    if (chk_cycle) return 2;
    if (chk_path && path_in && path_out) return 1;
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