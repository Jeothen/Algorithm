#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int max_Ver = 4;

vector<int> adj[max_Ver];
bool visited[max_Ver];



bool eulerian_cycle()
{
    if (str_con()) {
        return false;
    }

    for (int i=0; i <max_Ver; i++) {
        if (adj[i].size() != in[i]) return false;
    }

    return true;
}

void init()
{
    memset(visited, 0, sizeof(visited));
    cout << eulerian_cycle() << endl;
}

int main()
{
    init();
}