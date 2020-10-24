#include <iostream>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int solution(int N){
    while(N%2 == 0) N /= 2;
    int max_gap = 0;
    int cnt = 0;
    while(N!=1) {
        if (N % 2) {
            if (max_gap < cnt) max_gap = cnt;
            cnt = 0;
        }
        else cnt++;
        N /= 2;
    }
    return max(cnt,max_gap);
}


int main(){
    cout << solution(32);
}