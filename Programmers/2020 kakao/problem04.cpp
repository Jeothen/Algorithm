#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    bool isend;
    Trie* next[27];
    Trie(){
        for (int i=0; i<27; i++) next[i] = nullptr;
        isend = false;
    }
    ~Trie(){
        for (int i=0; i<27; i++) if (next[i]) delete next[i];
    }

    void insert(const char* key){
        if (*key == '\0') {
            isend = true;
            return;
        }
        int i;
        if (*key =='?') i = 26;
        else i = *key - 'a';
        if (!next[i]) next[i] = new Trie;
        next[i]->insert(key+1);        
    }
};

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;
    for (int i=0; i<answer.size(); i++){
        const char* str = words[i].c_str();
        cout << str << endl;
    }



    for (auto i=0; i<answer.size(); i++){
        cout << answer[i] << endl;
    }
    return answer;
}




int main(){
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    solution(words, queries);
}