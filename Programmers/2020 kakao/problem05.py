import copy


def check(ans):
    for tmp in ans:
        x, y, a = tmp
        if a == 0:  # 기둥
            if y != 0 and [x, y - 1, 0] not in ans and [x - 1, y, 1] not in ans and [x, y, 1] not in ans:
                return False
        else:  # 보
            if [x, y - 1, 0] not in ans and [x + 1, y - 1, 0] not in ans and not ([x - 1, y, 1] in ans and [x + 1, y,
                                                                                                            1]) in ans:
                return False
    return True


def solution(n, build_frame):
    answer = []

    for tmp in build_frame:
        x, y, a, b = tmp
        if b == 1:  # 추가
            answer.append([x, y, a])
            if not check(answer):
                answer.remove([x, y, a])
        else:
            answer.remove([x, y, a])
            if not check(answer):
                answer.append([x, y, a])
    answer = sorted(answer)
    return answer


n, lists = 5, [[1, 0, 0, 1], [1, 1, 1, 1], [2, 1, 0, 1], [2, 2, 1, 1], [5, 0, 0, 1], [5, 1, 0, 1], [4, 2, 1, 1], [3, 2, 1, 1]]

print(solution(n,lists))