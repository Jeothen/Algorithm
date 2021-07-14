# Strongly Connected component

* 하나의 정점에서 동일한 SCC 내에 있는 정점으로 이동할 수 있다 
  * 직/간접적인 경로 존재



### 타잔 알고리즘

* Robert Tarjan이 개발한 알고리즘으로, DFS와 Stack을 이용
* 방문을 안했으면 정방향 간선, 이미 방문을 했으면 역방향 간선으로 구분
* 모든 노드를 DFS로 탐색하면서 Stack에 담음
  * 노드/자식의 노드에서 조상 노드로 돌아갈 수 없을 때 SCC 생성
  * SCC가 생성되면 Stack에서 제거
  * Stack이 비게 되면 SCC 생성이 완료됨

* 모든 정점과 간선에 한번씩 접근하기 때문에 시간복잡도는 O(V+E)

