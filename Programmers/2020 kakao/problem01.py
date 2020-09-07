s = "a"

def solution(string):
    length = len(string)
    if len(string) == 1 :
        ans = 1
    else :
        ans = 0x7777df
    for i in range(1,length): # i 개 단위로 짤랐을 때
        tmp = 1 # 중복된 갯수
        idx = 0
        val = ""
        while idx < length :
            substr = string[idx:idx+i]
            idx2 = idx + i
            while idx2 < length :
                comp = string[idx2:idx2+i]
                if comp == substr :
                    tmp += 1
                    idx2 += i
                else :
                    break
            if tmp > 1 :
                val += str(tmp) + substr
            else :
                val += substr
            idx += tmp * i
            tmp = 1
        if ans > len(val) :
            ans = len(val)
    return ans

print(solution(s))