#include <string>
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> rotate(vector<vector<int>> arr, int ro, int n)
{
    vector<vector<int>> tmp = arr;
    while (ro--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp[i][j] = arr[j][n - 1 - i];
            }
        }
        arr = tmp;
    }
    return tmp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    int n = lock.size();
    for (int r= 0; r < 4; r++){
        vector<vector<int>> rot = rotate(lock,r,n);
        for (int j=0; j< 2*n; j++){
            for (int i=0; i < 2*n; i++){ // 시작위치 0부터 2*n-1까지
                vector<vector<int>> board;
                for (int i=0; i<3*n; i++){
                    vector<int>tmparr;
                    tmparr.resize(3*n);
                    board.push_back(tmparr);
                }
                for (int y=0; y<n; y++){
                    for (int x=0; x<n; x++){
                        board[n+y][n+x] = rot[y][x];
                    }
                }
                for (int y=0; y<key.size(); y++){
                    for (int x=0; x < key[0].size(); x++){
                        board[j+y][i+x] += key[y][x];
                    }
                }
                bool chk= true;
                
                for (int y=n; y<2*n; y++){
                    for (int x=n; x < 2*n; x++){
                        if (board[y][x] != 1) {
                            chk = false;
                            break;
                        }
                    }
                }
                if (chk) return true;

            }
        }        
    }
    return false;
}

int main(){
    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    cout << solution(key, lock) << endl;
    return 0;
}