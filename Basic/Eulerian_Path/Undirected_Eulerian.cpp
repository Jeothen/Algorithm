#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int max_Ver = 1001;

vector<int>adj[max_Ver];


// check if all node of graph is connected using by dfs  - tomorrow
bool isconnected(){ 

}

int odd_node()
{
    if (!isconnected()) return 0;
    // count odd degree
    int odd = 0;
    for (int i=0; i< max_Ver; i++){
        if (adj[i].size() % 2) odd++;
    }
    if (odd > 2) return 2;
    return odd;
}

string check_eulerian(){
    int res = odd_node();
    if (res == 1) return "euler path";
    else if (res == 0) return "euler circuit";
    else "not eulerian";
}

int main(){
    cout << check_eulerian();
}