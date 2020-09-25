
def isway(x,y,n):
    if x < 0 or x >= n : return False
    if y < 0 or y >= n : return False
    return True

dx = [1,0,-1,0]
dy = [0,-1,0,1]  # visited 1,2,3,4

import queue

def rotate(head,tail, going, contro):

    if not contro:
        gx, gy = tail[0] + dx[going], tail[1] + dy[going]
        cross = [head[0]+dx[going], head[1]+dy[going]]
        return [[gx,gy], tail, cross, going]
    else :
        gx, gy = head[0] + dx[going], head[1] + dy[going]
        way = going + 2
        if way >= 4 : way-=4
        cross = [tail[0]+dx[going], tail[1]+dy[going]]
        return [head,[gx,gy],cross, way]

def solution(board):
    n = len(board)
    visited = [[[0]*n for _ in range(n)] for _ in range(4)]
    head, tail = [1,0], [0,0]
    q = queue.Queue()
    q.put([head,tail,0,1])
    while not q.empty():
        tmp = q.get()
        head, tail, way, cnt = tmp
        if visited[way][head[1]][head[0]]  : continue
        visited[way][head[1]][head[0]] = cnt
        if tail == [n-1,n-1] or head == [n-1,n-1] : return cnt-1
#        visited[way][head[1]][head[0]] = cnt
#        visited[way][tail[1]][tail[0]] = cnt
        for i in range(4): # 직진
            if way % 2 :
                if i % 2 == 0 : continue
            else :
                if i %2 : continue
            hx,hy = head[0] + dx[i], head[1] + dy[i]
            tx,ty = tail[0] + dx[i], tail[1] + dy[i]
            if isway(hx,hy,n) and isway (tx,ty,n) :
                if board[hy][hx] == 0 and board[ty][tx] == 0 :
                    q.put([[hx,hy],[tx,ty],way,cnt+1])
        for c in range(2):
            for i in range(4): # 회전
                if way % 2 == 0 :
                    if i % 2 == 0 : continue
                else :
                    if i % 2 : continue


                h, t,cross, w = rotate(head, tail, i, c)
                hx, hy = h
                tx, ty = t
                if isway(h[0], h[1], n) and isway(t[0], t[1], n) and isway(cross[0], cross[1], n):
                    if board[h[1]][h[0]] == 0 and board[t[1]][t[0]] == 0 and board[cross[1]][cross[0]] == 0:
                        q.put([h, t, w, cnt + 1])



board = [[0, 0, 0, 1, 1], [0, 0, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 0, 1], [0, 0, 0, 0, 0]]
print(solution(board))