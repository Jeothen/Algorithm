
p = "(()())()"


def isbalance(string):
    left = 0
    right = 0
    for i in range(len(string)):
        if string[i] == '(' :
            left += 1
        else :
            right += 1
    if left == right : return True
    return False

def iscorrect(string):
    stack = []
    if string[0] == ")" :
        return False
    for i in range(len(string)):
        if string[i] == '(' :
            stack.append('(')
        else :
            if stack[-1] == ')' :
                return False
            else :
                stack.pop()
    return True

def solution(p):
    if p== "" : return ""
    u = ""
    left = 0
    right = 0
    idx = 0
    while idx < len(p):
        if p[idx] == '(' :
            u += '('
            left += 1
        else :
            u += ')'
            right += 1
        if left != 0 and left == right :
            break
        idx += 1
    v = p[idx+1:]
    if iscorrect(u):
        answer = u + solution(v)
    else:
        answer = '('
        answer += solution(v)
        answer += ')'
        for i in range(1,len(u)-1):
            if u[i] == "(" :
                answer += ")"
            else :
                answer += "("
    return answer

print(solution(p))