#include <string>
#include <iostream>
using namespace std;

const int Alphabet = 26;

int A[Alphabet][Alphabet];
int B[Alphabet][Alphabet];

int low_to_prime(char word)
{
    return word - 32;
}

bool isalphabet(char word1, char word2)
{
    if (65 <= word1 && word1 <= 90)
    {
        if (65 <= word2 && word2 <= 90)
        {
            return true;
        }
        return false;
    }
    return false;
}

void transform(string s, int array_rec)
{
    for (int i = 0; i < s.length() - 1; i++)
    {
        char tmp1 = s[i], tmp2 = s[i + 1];
        if (97 <= s[i] && s[i] <= 122)
            tmp1 = low_to_prime(s[i]);
        if (97 <= s[i + 1] && s[i + 1] <= 122)
            tmp2 = low_to_prime(s[i + 1]);
        if (isalphabet(tmp1, tmp2))
        {
            tmp1 = static_cast<int>(tmp1), tmp2 = static_cast<int>(tmp2);
            if (array_rec) A[tmp1-65][tmp2-65] += 1;
            else B[tmp1-65][tmp2-65] += 1;
        }
    }
    cout << endl;
}

int common;
int unite;


int solution(string str1, string str2)
{
    cout << str1 << endl;
    // 소문자 97 ~ 122  / 대문자 65 ~ 90
    transform(str1,1);
    transform(str2,0);

    for (int i=0; i<Alphabet;i++){
        for (int j=0; j<Alphabet; j++){
            int bigger = max(A[i][j],B[i][j]);
            int smaller = min(A[i][j], B[i][j]);

            common += smaller;
            unite += bigger;
        }
    }
    cout << unite << " " << common << endl;
    int answer;
     if (unite = 0) answer = 65536;
    else answer = common * 65536 / unite;
    return answer;
}

string str1 = " E=M *C ^ 2 ", str2 =" e = m * c ^ 2 ";

int main() {
    printf("%d",solution(str1, str2));
}