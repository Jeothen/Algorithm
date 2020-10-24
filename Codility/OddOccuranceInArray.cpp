// you can use includes, for example:
// #include <algorithm>
#include<vector>
#include <iostream>
using namespace std;

#include <iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <unordered_map>
#include <vector>
using namespace std;

int solution(vector<int>& A){
    unordered_map<int,int> mp;
    vector<int> vc;
    for (unsigned int i=0; i<A.size();i++){
        mp[A[i]] += 1;
        vc.push_back(A[i]);
    }
    for (auto p : vc){
        if (mp[p] % 2 == 1) return p;
    }
}



int main(){
    vector <int> A = {9,3,9,4,4};
    cout << solution(A);
}