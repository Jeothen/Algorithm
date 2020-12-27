#include <cstring>
#include <vector>

int ascii[256];

void create_Bad_Match_table(char pattern[]){
    int len_p;
    for (len_p = 0; pattern[len_p] != '\0'; len_p++);
    
    // value 0 is filled to length of pattenr    
    for (int i=0; i<256;i++){
        if (ascii[i] == 0) ascii[i] = len_p;
    }

    for (int i=0; i<len_p-1; i++){ // last character is skip
        ascii[pattern[i]] = len_p - i - 1;
    }

}

std::vector<int>Hospool(char* text, char* pattern){
    std::vector<int> res;
    int len_p, len_t;
    for (len_t = 0; text[len_t] != '\0'; len_t++);
    for (len_p = 0; pattern[len_p] != '\0'; len_p++);
    create_Bad_Match_table(pattern);

    int i =0, j =0, k =0;
    while(i <= len_t-len_p) {
        j = len_p-1; // pattern index from right
        k = i + len_p-1; // text index from right
        while(j >= 0 && pattern[j] == text[k]) {
            --j; --k;
        }
        if (j == -1) {
            printf("%d\n",i);
            res.push_back(i); // start index
        }
        i += ascii[text[i + len_p - 1]]; // text index from right
    }
    return res;
}
