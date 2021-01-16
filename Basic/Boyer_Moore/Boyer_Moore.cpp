#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int diff;
vector<int> G;

bool cmp(int i, int j)
{
    if (G[i] != G[j])
        return G[i] < G[j];           // if groups are different
    return G[i + diff] < G[j + diff]; // same group case
};

vector<int> getsfx(string &str)
{
    int n = str.size();
    G.resize(n); // group

    vector<int> SA, tmp;
    SA.resize(n);  // suffix Array - index
    tmp.resize(n); // new group

    // preprocessing
    for (int i = 0; i < n; i++)
    {
        SA[i] = i;
        G[i] = str[i];
    }

    for (diff = 1; diff < 2 * n; diff <<= 1)
    {                                    // logn
        sort(SA.begin(), SA.end(), cmp); // align suffix array // compared by group
        // if using counting sort, time complexity can be reduced.

        // new group create
        for (int i = 0; i < n - 1; i++)
        {
            tmp[SA[i + 1]] = tmp[SA[i]] + cmp(SA[i], SA[i + 1]); // if rank is differ, assign next rank
        }
        G = tmp;
    }
    return SA;
}
/////////           SUFFIX Array        //////




int main()
{

}
