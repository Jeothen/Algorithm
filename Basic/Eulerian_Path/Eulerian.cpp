#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define maxnode 1001

vector<int> adj[maxnode];
vector<int> path;

// dfs
void recursive_circuit(int now, const int& new_maxnode)
{
    for (int i=0; i< new_maxnode; i++){
        cout << 1;
    }
    path.push_back(now);
}

void euler_circuit(){
    recursive_circuit(1,7); // start from any node, but register reversed
    reverse(path.begin(), path.end());
}
int main()
{
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[5].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[3].push_back(1);
    adj[1].push_back(3);
    adj[5].push_back(7);
    adj[7].push_back(5);
    adj[7].push_back(6);
    adj[6].push_back(7);
    adj[6].push_back(5);
    adj[5].push_back(6);
    euler_circuit();
    for (int v : path)
    {
        cout << v << " ";
    }
    cout << '\n';
}
