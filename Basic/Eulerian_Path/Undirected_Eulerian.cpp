#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int max_Ver =4;

vector<int>adj[max_Ver];
bool visited[max_Ver];

void dfs(int idx){
    visited[idx] = true;
    for (auto p = adj[idx].begin(); p != adj[idx].end(); p++)
    {
        if (!visited[*p]) dfs(*p);
    }
}

// check if all node of graph is connected using by dfs
bool isconnected(){ 
    memset(visited,0,sizeof(visited));
    
    int idx;
    for (idx=0; idx < max_Ver;idx++) {
        if(adj[idx].size() != 0) break;
    }
    // no-edge graph
    if (idx == max_Ver) return true;

    dfs(idx); // start node

    for (int i=0; i < max_Ver; i++){
        if (!visited[i] && adj[i].size()) return false;  // if node exists but not visited
    }
    return true;
}

int odd_node()
{
    if (!isconnected()) return 0;
    // count odd degree
    int odd = 0;
    for (int i=0; i< max_Ver; i++){
        if (adj[i].size() % 2) odd++;
    }
    if (odd > 2) return -1;
    return odd; // 2 or 0
}

string check_eulerian(){
    int res = odd_node();
    if (res == 2) return "euler path";
    else if (res == 0) return "euler circuit";
    else return "not eulerian";
}

void init(){
    memset(visited,0,sizeof(visited));
    cout << check_eulerian() << endl;
}

int main(){
/*    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);*/
    init();
}