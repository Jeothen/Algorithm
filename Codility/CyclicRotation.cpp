#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> &A, int K)
{
    int N = A.size();
    if (N == 0) return {}; // empty

    int rotate = K % N;
    vector <int> res;
    for (int i= N - rotate; i < N; i++){
        res.push_back(A[i]);
    }
    for (int i=0; i < N-rotate; i++){
        res.push_back(A[i]);
    }
    return res;
}



int main(){
    vector<int> A = { }; int K = 0;
    vector<int> res = solution(A,K);
    for (auto p: res){
        cout << p << " ";
    }
}