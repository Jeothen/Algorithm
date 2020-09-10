#include <string>
#include <iostream>
#include <vector>

using namespace std;

// ?는 접두사 or 접미사
struct Trie
{
    bool isend;
    int count;
    Trie *next[27];
    Trie()
    {
        for (int i = 0; i < 27; i++)
            next[i] = nullptr;
        isend = false;
        count = 0;
    }
    ~Trie()
    {
        for (int i = 0; i < 27; i++)
            if (next[i])
                delete next[i];
    }

    void insert(const char *key)
    {
        if (*key == '\0')
        {
            isend = true;
            return;
        }
        int i = *key - 'a';
        if (!next[i])
            next[i] = new Trie;
        count++;
        next[i]->insert(key + 1);
    }

    int check(const char *key, int cnt)
    {
        if (*key == '\0')
        {
            if (isend)
                return cnt + 1;
            else
                return cnt;
        }
        int i;
        if (*key == '?')
            i = 26;
        else
            i = *key - 'a';
        if (*key + 1 == '?')
            return count; // 접미사 처리
        if (i == 26)
        {
            for (int j = 0; j < 26; j++)
            {
                if (next[j])
                {
                    cnt = next[j]->check(key + 1, cnt);
                }
            }
        }
        else
        {
            if (next[i])
            {
                cnt = next[i]->check(key + 1, cnt);
            }
        }
        return cnt;
    }
};

fill(a,s,v);
string reverse_char(string str) {
    cout << "str = " << str << endl;
    string reverse_str;
    for (int j = str.size() - 1; j >= 0; j--)
    {
        reverse_str += str[j];
    }
    return reverse_str;
}

vector<int> solution(vector<string> words, vector<string> queries)
{
    Trie *root = new Trie;
    // reverse root를 하나 더 만들어서 문자열을 반대로 넣음
    // 처음 문자열이 ?인 경우 reverse root로
    Trie *reroot = new Trie;

    for (int i = 0; i < words.size(); i++)
    {
        const char *str = words[i].c_str();
        root->insert(str);
        string re_str = reverse_char(words[i]);
        reroot->insert(re_str.c_str());
    }

    vector<int> answer;
    int val;
    for (int i = 0; i < queries.size(); i++)
    {
        int length = queries[i].length();
        if (queries[i][0] == '?')
        {
            cout << "go" << endl;
            string re_str = reverse_char(queries[i]);
            cout << "return " << re_str << endl;
            val = reroot->check(re_str.c_str(), 0);
        }
        else val = root->check(queries[i].c_str(), 0);
        answer.push_back(val);
    }
    return answer;
}

int main(){
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    solution(words, queries);
}