#include <stdio.h>
using namespace std;

struct Trie{
    Trie* next[10];
    bool isend;
    bool isnext;

    Trie(){
        for (int i=0;i<10;i++) next[i] = nullptr;
        isend = false, isnext = false;
    }
    ~Trie(){
        for (int i=0; i<10; i++) if (next[i]) delete next[i];
    }

    bool insert(const char* key){
        if (*key == '\0') {
            isend = true;
            return !isnext; // 자식이 없어야 한다.  // 이전에 있던것에 포함되는지
        }
        int val = *key - '0';
        if (!next[val]) next[val] = new Trie;
        isnext = true;
        return !isend && next[val]->insert(key+1);  // 이전에 있던걸 포한하는지
    }
};

int main(){
    freopen("5052.txt","r",stdin);
    int te; scanf("%d",&te);
    while(te--){
        int N; scanf("%d",&N);
        Trie* root = new Trie;
        char str[11];
        bool ans = true;
        while(N--) {
            scanf("%s", str);
            if (ans && !root->insert(str)) {
                ans = false; // break; ?? - 다음에 받는 값이 int n 이 아니라 string을 받게 되네...
            }
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
        delete root;
    }
}