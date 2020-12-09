import sys
sys.stdin = open('최소신장.txt')

def mst():
    total = 0
    u = 0
    D[u] = 0

    for i in range(V+1):
        min = 987654321
        for v in range(V+1):
            if visited[v] == 0 and min > D[v]:
                min = D[v]
                u = v

        visited[u] = 1
        total += adj[PI[u]][u]

        for v in range(V+1):
            if adj[u][v]!=0 and visited[v] == 0 and adj[u][v] < D[v]:
                D[v] = adj[u][v]
                PI[v]=u
    # pprint.pprint(adj)
    # print(D)
    # print(PI)
    return total


T = int(input())
for tc in range(1, T+1):
    V, E = map(int, input().split())
    # V = 마지막 노드번호(시작 노드번호는 0번)
    # E = 간선의 갯수
    adj = [[0 for _ in range(V+1)] for _ in range(V+1)]
    # adj : 가중치 이중행렬
    D = [1000001] * (V+1)
    # 가중치
    PI = [x for x in range(V+1)]    #
    visited = [0] * (V+1)
    # print(weight)
    # print(parent)

    for i in range(E):
        edge = list(map(int, input().split()))
        print(edge)
        # edge[0] # 여기에서
        # edge[1] # 그곳으로 가는 길은
        # edge[2] # 가중치가 이렇다.
        adj[edge[0]][edge[1]] = adj[edge[1]][edge[0]] = edge[2]
        # 행에서 열로 가는 데에 가중치가 들어있다.

    print('# {} {}'.format(tc, mst()))