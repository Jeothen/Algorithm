#include <vector>
#include <iostream>
using namespace std;

int arr[100001];
int solution(vector<int> &A)
{  
    int right = 0;
    for (unsigned int i= 0; i < A.size(); i++) if (A[i]) right++;
    int answer = 0;
    for (unsigned int i= 0; i < A.size(); i++) {
        if (A[i] == 0) answer += right;
        else right--;
        if (answer > 1e9) return -1;
    }
    return answer;
    // write your code in C++14 (g++ 6.2.0)
}


int main(){
    vector<int> vc = {0,1,0,1,1};
    cout <<  solution(vc);
}