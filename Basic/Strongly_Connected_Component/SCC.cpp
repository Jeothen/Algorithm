#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define NODE 4


int cnt, dfsn[NODE];
bool extract[NODE];
vector <int> adj[NODE];
vector<vector<int>> SCC;
stack<int> s;

int min(const int& a, const int& b)
{
    return a > b ? b : a;
}

int dfs(int cur)
{
    dfsn[cur] =  ++cnt; // count to node
    s.push(cur);
    int res = dfsn[cur];

    for (auto next : adj[cur])
    {
        if (!dfsn[next]) res = min(res, dfs(next));
        else if (!extract[next]) res = min(res, dfsn[next]);
    }

    if (res == dfsn[cur]) 
    {
        vector<int> tmpscc;
        while(1)
        {
            int val = s.top(); s.pop();
            tmpscc.push_back(val);
            extract[val] = true;
            if (val == cur) break;
        }
        sort(tmpscc.begin(), tmpscc.end());
        SCC.push_back(tmpscc);
    }
    return res;
}

void CreateSCC()
{
    // Create CSS by using DFS
    for (int i=0; i<NODE; i++)
    {
        if (!dfsn[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    cnt = 0;
    adj[1].push_back(2);
    adj[3].push_back(2);
    adj[0].push_back(1);
    adj[2].push_back(0);
    CreateSCC();

    for (auto& tmpscc : SCC)
    {
        for (auto val : tmpscc)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}