// you can use includes, for example:
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    for (unsigned int i = 1; i <= A.size(); i++)
    {
        if (A[i-1] != i) return 0;
    }
    return 1;
}

int main(){
    vector<int>tmp = {1,2,3,4};
    cout << solution(tmp);
}
