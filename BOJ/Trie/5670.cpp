#include <iostream>
#include <vector>
using namespace std;

struct Trie
{
    int cnt; // 자식의 갯수 - 1이면 통과
    Trie *next[26];

    Trie()
    {
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
        cnt = 0;
    }
    ~Trie()
    {
        for (int i = 0; i < 26; i++)
            if (next[i])
                delete next[i];
    }

    void insert(const char *key)
    {
        if (*key == '\0')
            return;
        int i = *key - 'a';
        if (!next[i])
            next[i] = new Trie;
        next[i]->cnt += 1;
        next[i]->insert(key + 1);
    }

    int check(const char *key, int prev, int press)
    {
        if (*key == '\0')
            return press;
        int i = *key - 'a';
        if (prev == next[i]->cnt)
            return next[i]->check(key + 1, prev, press);
        else
            return next[i]->check(key + 1, next[i]->cnt, press + 1);
    }
};

vector<string> vc;

int main()
{
    freopen("5670.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != -1)
    {
        vc.clear();
        Trie *root = new Trie;
        char str[80];
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str);
            vc.push_back(str);
            root->insert(str);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += root->check(vc[i].c_str(), 0, 0);
        printf("%.2lf\n", double(ans) / n);
        delete root;
    }
}