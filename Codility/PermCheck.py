
def solution(A):
    A = set(A)
    A = sorted(A)
    idx = 0
    while(idx < len(A)):
        if (A[idx] > 0):
            val = 1
            while(idx < len(A) and A[idx] == val):
                val+=1
                idx+=1
            return val
        else : idx += 1
    return 1
    

A = [1,3,6,1,4,2]
A = [-1,1]
print(solution(A))