import itertools


def solution(n, weak, dist):
    if n == 1 or len(weak) == 1:
        return 1

    weak_list = []
    for w in weak: weak_list.append(w)
    for w in weak: weak_list.append(n + w)
    length = len(weak)
    len_people = len(dist)
    answer = 0x88888f
    for i in range(length):
        tmp_weak = weak_list[i:i + length]
        people_list = list(itertools.permutations(dist))
        people_idx = 0
        for peoples in people_list:
            chk = True
            tmp = 0 # 사람수
            start_idx = 0 # 시작 위치
            idx = 0
            print(tmp_weak)
            print(peoples)
            while idx < length and tmp < len_people:
                max_length = tmp_weak[start_idx] + peoples[tmp]
                while idx < length and tmp_weak[idx] <= max_length:
                    idx += 1
                tmp += 1
                start_idx = idx
            if idx == length :
                answer = min(answer, tmp)
    if answer == 0x88888f:
        return -1
    return answer

n, weak, dist = 12, [1, 3, 4, 9, 10], [3, 5, 7]
print(solution(n,weak,dist))