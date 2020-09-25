# Segment Tree

```reStructuredText
주어진 쿼리에 대해 빠르게 응답하기 위해 만들어진 자료구조이다.
예를들어보자.
1 2 3 4 5 6이라는 배열 arr이 있었고,
arr[2] + arr[3] + arr[4]를 구하라는 쿼리가 있었다.
(쿼리란 주어진 요구사항에 대해 맞는 결과물을 제시하라는 뜻이다.)
지금 당장은 3+4+5로 간단히 해결할 수 있지만, arr[3]을 10으로 바꾸고 
다시 arr[2] + arr[3] + arr[4]를 구하라는 쿼리가 오면 또 다시 arr[2] + arr[3] + arr[4]를 해야한다.
이렇게 되면 한번 실행하는데 걸리는 시간은
수를 바꾸는데 O(1), 수를 더하는데 O(N)이니 M번 수행한다 치면 O(MN + M) -> O(MN)의 시간이 걸린다.
```

방금 위에서 본 내용중 수를 바꾸는 과정과 수를 더하는 과정이 세그먼트 트리에서는

**수를 바꾸는 과정 :: O(lgN)**

**수를 더하는 과정 :: O(lgN)**으로 변하게 된다.

M번 실행한다 치면 **O(MlgN + MlgN) -> O(MlgN)**이 걸리게 된다.



시각적으로 확인해 볼 수있는 방법은 M = 100, N = 2^20이라 치자



O(MN)에서는 100*2^20 = 10,000,000(대략)

O(MlgN)에서는 100*20 = 2,000으로 데이터와 반복수행이 잦아질 수록 시간 복잡도 차이가 기하급수적으로 커진다.



**(세그먼트 트리는 대부분 완전 이진 트리이다. 아래 그림을 통해 확인하자)**



**그림을 통한 세그먼트 트리 확인**



![img](https://t1.daumcdn.net/cfile/tistory/256DB33B58BF06FB1D)





위의 그림은 N = 12일때 모습이다.



제일 아래 **리프 노드**로 달린 것들이 **실제 우리가 처음 받아온 데이터**들을 의미한다.

(여기서는 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11이라 적힌 노드들을 의미)



**x~y의 의미는** 

**x부터 y까지의 합의 범위**를 나타낸 것이다.



즉, arr[0] = 1, arr[1] = 2였다면 위의 0노드에는 1, 1노드에는 2 그리고 0~1노드에는 3이 들어간다.



결국 가장 최상위 루트 노드는 0~11이라 적혀있고, 처음 받아온 데이터들의 총 합을 의미한다.





**세그먼트 트리의 전체 크기 구하기**



**아래 init함수를 만들기 전에 우선 하나 알고 가야할 사실이 있다.**



N = 12일 때의 **세그먼트 트리의 전체 크기(배열 사이즈 정하기)**를 구하기 위해서는 

**2^k로 12보다 바로 큰 값을 만들 수 있는 k**를 찾아야한다. 즉, k는 4이다.



그리고 난 뒤 **2^k를 하면 16이 되고 16에 \*2**를 하면 우리가 원하는 세그먼트 트리의 크기를 구할 수 있다.  



이 과정이 귀찮다면 그냥 **N \* 4**를하면(여기서는 48이 세그먼트 트리 크기가 될 것이다.)

메모리는 조금 더 먹지만, 편리하게 이용할 수 있다.

```c
 int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));  
```

이렇게 나타낼 수 있는데 ceil은 올림을 하겠다는 의미이고, log2N에서 도출되는 값을 올림한 값을 h에 저장한다.

즉 log2(12) = 3.xxx이고 올림한 4를 h에 저장한다.



1 << (4+1) = 1 << 5 = 32가 결국 tree_size가 된다.







**Segment Tree node에 값들이 쌓이는 원리**

![img](https://t1.daumcdn.net/cfile/tistory/251C113758BF11D220)



우리는 세그먼트 트리를 형성할 때 **루트 노드**를 **1**로 생각한다.

이때 **루트노드 왼쪽 노드는** **2**번 노드가 될 것이고 **오른쪽 노드는 3**번 노드가 될 것이다.

그리고 **2번노드의 왼쪽 노드**는 **4**번, **오른쪽 노드는 5**번이 될 것이다.

또한 **3번 노드의 왼쪽 노드는 6**번, **오른쪽 노드는 7**번이 될 것이다.



무슨 말인지 이해가 되는가?

그림을 보면 알다시피 현재 우리는 **포인터로 동적할당을 통한 트리가 아닌 배열로 트리를 만들고 있다**.

그 이유는 **세그먼트 트리**는 **full binary tree**에 가깝기에 **배열에 모든 값들이 꽉꽉차서 올 가능성이 매우 높기**때문에 

포인터보다는 배열을 이용하게 된다. 그리고 **각 노드마다의 왼쪽, 오른쪽 자식 노드는 항상 규칙이 정해져 있다****.**



**<< 현재 노드의 번호가 node 일 때 >>**

노드의 왼쪽 자식 배열 번호 :: **node \* 2**

노드의 오른쪽 자식 배열 번호 :: **node \* 2  + 1**



이 방식은 아래에 나오는 init 함수 및 다른 함수에서 node*2 , node*2+1이 어떻게 이용되는지 알 수 있다.



















**세그먼트 트리를 만드는 방법**



**이 내용을 보면서 tree배열과 arr배열을 햇갈리지 말아야 한다.**



**tree 배열은 세그먼트 트리가 만들어지는 배열이고**

**arr 배열은 처음에 입력받아 생성된 배열이다.**



**1. 초기화 과정(init)**



초기화라는 의미는 결국 위의 그림과 같은 트리를 생성하는 것이다.(가장 초기상태의 트리)



이 초기화 과정을 거치고 나면 결국 구간 합 트리가 형성된다.



![img](https://t1.daumcdn.net/cfile/tistory/2232BA4058BF0B8420)

만약 arr[12] = {3, 5, 6, 7, 2, 9, 4, 5, 2, 8, 1, 5}였다면 다음과 같은 구간 합 세그먼트 트리가 나올 것이다.

```c
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end); 
}
```

위의 그림을 통해 init의 함수에 대해 알아보자.

(ll은 long long 타입입니다.)

* 우선 인자로는 **arr벡터(배열), tree벡터(배열), 노드번호, 노드의 시작번호, 노드의 끝번호**이다.

* start == end일 때 tree[node] = arr[start]를 받는다. -> start == end라는 의미는 아래 코드를 확인해야 해석이 가능하다.

* start != end일때는 위의 return tree[node] = init(~) + init(~)로 들어가게 된다.

  init인자로 자세히 보면 node*2와 node*2+1이 있다.



위에서 언급했다시피 **각 노드의 왼쪽 자식과 오른쪽 자식으로 분리되는 과정**을 보여주는 것이다.



그리고 **왼쪽 자식쪽에는 start ~ mid**를 보내고, **오른쪽 자식에는 mid+1 ~ end**를 보낸다.

(mid :: (start + end) / 2)

이 의미는 arr의 값을 반틈씩 쪼개어 계속 보내고 있는 것을 의미한다.

arr[12] = {3, 5, 6, 7, 2, 9, 4, 5, 2, 8, 1, 5}라고 했을 때



첫 init(arr, tree, node * 2, start, mid)에 의해 들어가는 인자를 숫자로 표현해보면



init(arr, tree, 2, 0, 5)이 들어간다.

즉, 1번 루트 노드의 왼쪽 자식(2번 노드)에는 arr[0~5] ( = arr[start~mid) )값이 들어간다는 것이다.



그다음 init(arr, tree, node * 2 + 1, mid+1, end)는

init(arr, tree, 3, 6, 11) 다음과 같이 들어간다.

즉, 1번 루트 노드의 오른쪽 자식(3번 노드)에는 arr[6~11]] ( = arr[mid+1~end) )값이 들어간다는 것이다.



------



이제 다시 start == end의 의미를 파악해보자.

```
if (start == end)
	return tree[node] = arr[start];
```

노드가 계속 분할되어 결국 start와 end가 같아지는 부분이 생길 것이다.

이때 의미는 arr[start~end]가 결국 arr[start]와 같다는 의미이고, 결국 노드의 범위가 1인 리프 노드를 의미한다.



따라서 가장 아래까지 내려왔다면 현재 node번째인 tree[node]에 arr[start]값을 대입해준다는 의미이다.



그림으로 확인해 본다면 다음과 같은 과정이 이루어 지는 것이다.

![img](https://t1.daumcdn.net/cfile/tistory/2502C34458BF17AE2D)







이렇게 init함수를 재귀를 통해 반복하면 위의 그림이 완성된다.

**2. 갱신 과정(update)**


  ```c
void update(vector<ll> &tree, int node, int start, int end, int index, ll diff)
{
    if (!(start <= index && index <= end))
        return;
    
    tree[node] += diff;
 
    if(start != end)
    {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
 
}
  ```

* tree 벡터(배열), node번호, start, end 그리고 바꾸고자하는 인덱스 번호(바꾸고자 하는 노드 번호), 차이를 인자로 한다
* start와 end사이에 index가 있지 않다면? retrun 해버린다.   그림으로 확인해보면 다음과 같다.

![img](https://t1.daumcdn.net/cfile/tistory/245F7B3A58BF1E1E31)

현재 세그먼트 트리 기준으로 21번 노드의 값을 2에서 10으로 변경하려 한다.

```c
void update(vector<ll> &tree, int node, int start, int end, int index, ll diff)
```

우리는 **node**를 1번 노드부터 시작할 것이고, **start**는 0번, **end**는 11번, **index**는 4번, **diff**는 10 - 2를뺀 8이다.

```c
if (!(start <= index && index <= end))
        return;
```

현재 index :: 4는 0 <= 4 <= 11이다.

따라서 if문에는 걸리지 않고 넘어간다.

```c
tree[node] += diff;
 
    if(start != end)
    {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
```

tree[node] += diff;

tree[1] += 8;

이 말은 무엇이냐면, 아까 2에서 10으로 값이 변했을 때 변화값이 8이니

전체 구간 합(tree[1])도 8만큼 값을 증가시켜야 한다는 말이다.



이제 start != end이니 각 update로 다시 들어가보자.



update(tree, 2, 2, 5, 4, 8);

update(tree, 3, 6, 11, 4, 8);으로 받아지게 될 것이다.



위의 update를 타고 들어가면 start = 2, end = 5가 되어있어서

```c
if (!(start <= index && index <= end))
        return;
```

2 <= 4 <= 5라 걸리지 않고 tree[node] += diff를 하게 되지만,



아래 update는 타고 들어가면 start = 6, end = 11이어서



6<= 4 <= 11에 걸리게 된다.





**이 과정이 무얼 의미하는지 그림을 통해 보자**







![img](https://t1.daumcdn.net/cfile/tistory/2401604558BF20C32F)







**결국 update과정을 모두 마치게 되면 다음과 같은 모습이 나타나게 된다.(빨간색 값으로 update가 되었다.)**





![img](https://t1.daumcdn.net/cfile/tistory/2204344558BF20C430)











**3. 합 과정(sum)**





**합을 구하는 과정은 4가지 경우로 나눌 수 있다.**



**1. [left, right]와 [start, end]가 겹치지 않는 경우**

-> 즉 아에 구간 합을 구하고자 하는 범위와 상관이 없는 경우



:: **if(left > end || right < start)**로 표현 할 수 있다.



**2. [left, right]가 [start, end]를 완전히 포함하는 경우**

-> 즉, 구하고자 하는 구간 합 구간에 포함되는 경우



:: **if(left <= start && end <= right)로 표현할 수 있다.**



**3. [start, end]가 [left, right]를 완전히 포함하는 경우** 

-> 즉, 구하고자 하는 구간 합 범위보다는 크게 있지만 그 내부에 구하고자 하는 구간 합 범위가 있는 경우



**:: return sum(tree, node\*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right)로 표현할 수 있다.**



**4. [left, right]와 [start, end]가 겹쳐져 있는 경우(1,2,3을 제외한 나머지 경우)**

-> 즉, left <= start <= right <= end같은 방식인 경우



**:: return sum(tree, node\*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right)로 표현할 수 있다.**



결론적으로 3,4는 재탐색을 해야하고 1,2,3,4를 합치면 아래 코드처럼 표현할 수 있다.

```c
ll sum(vector<ll> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
 
    if (left <= start && end <= right)
        return tree[node];
 
    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}
```

인자를 보면 다음과 같다.



tree, node번호, start번호, end번호, left, right



여기서 left와 right는 구간 left~right의 합을 구해달라는 의미이다.



합 과정 또한 그림으로 확인해보자.





다음과 같이 8~11의 구간합을 구하고 싶다고 가정한다.

이때 left는 8, right는 11이 될 것이다.



![img](https://t1.daumcdn.net/cfile/tistory/2219B13558BF246E06)



루트노드부터 관찰해 보자.

```c
if (left > end || right < start)
    return 0;
```

if(8 > 11 || 11 < 0)이니 둘다 만족하지 않는다. 따라서 다음 단계로 간다.

```c
if (left <= start && end <= right)
    return tree[node];
```

if(8 <= 0 && 11 <= 11)이니 다음 단계로 간다.

```c
int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
```


![img](https://t1.daumcdn.net/cfile/tistory/27115D3758BF26C532)





이제 2번 노드(arr 0~5번 배열의 구간합을 가진 노드)와 3번 노드(arr 6~11번 배열의 구간합을 가진 노드)를 관찰해야 한다.



2번 노드부터 보자.

```c
 if (left > end || right < start)
        return 0;
```

left(8)는 end(5)보다 크다. 그리고 right(11)은 start(0)보다 크다.



따라서 left > end가 만족하므로 return 0;을 해버린다.



![img](https://t1.daumcdn.net/cfile/tistory/2413983D58BF27650E)





다음은 3번 노드(arr 6~11번 배열의 구간합을 가진 노드)를 관찰해야 한다.

```c
if (left > end || right < start)
        return 0;
```

해당사항이 없으니 넘어간다.

```c
 if (left <= start && end <= right)
        return tree[node];
```

left :: 8 start :: 6 right :: 11 end :: 11이다.

if(0 && 1)이니 넘어간다.

```c
int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
```

위의 코드에 의해 다음과 같이 그림이 생성된다.







![img](https://t1.daumcdn.net/cfile/tistory/221F614458BF284201)





이러한 방식으로 모두 마무리 짓게 되면 다음과 같이 형성된다.







최종적으로 

0~5는 관련없으므로 return 0; 

6~7도 관련 없으므로 return 0;

8은 if(left <= start && end <= right)이므로 return 2; ((즉, 구간에 포함되는 노드라는 의미))

9~11또한 8처럼 구간에 포함되는 노드이기에 return 14;



![img](https://t1.daumcdn.net/cfile/tistory/25292A3F58BF297904)







return sum() + sum();이었으니 또 그 위 단계로 return 해준다.





![img](https://t1.daumcdn.net/cfile/tistory/2109A83F58BF297A3D)







![img](https://t1.daumcdn.net/cfile/tistory/2765B23F58BF297B03)





최종적으로 16이 return 된다.

![img](https://t1.daumcdn.net/cfile/tistory/262ADA3F58BF297C04)





---

---







배열 A가 있고, 여기서 다음과 같은 두 연산을 수행해야하는 문제를 생각해봅시다.

1. 구간 l, r (l ≤ r)이 주어졌을 때, A[l] + A[l+1] + ... + A[r-1] + A[r]을 구해서 출력하기
2. i번째 수를 v로 바꾸기. A[i] = v

수행해야하는 연산은 최대 M번입니다.

세그먼트 트리나 다른 방법을 사용하지 않고 문제를 푼다면, 1번 연산을 수행하는데 O(N), 2번 연산을 수행하는데 O(1)이 걸리게 됩니다. 총 시간 복잡도는 O(NM) + O(M) = O(NM)이 나오게 됩니다.

2번 연산이 없다고 생각해봅시다.

수를 바꾸는 경우가 없기 때문에, 합도 변하지 않습니다. 따라서, 앞에서부터 차례대로 합을 구해놓는 방식으로 문제를 풀 수 있습니다.

S[i] = A[1] + ... + A[i] 라고 했을 때, i~j까지 합은 S[j] - S[i-1]이 됩니다.

i~j까지 합은 A[i] + ... + A[j]인데, S[j] = A[1] + ... + A[j], S[i-1]= A[1] + ... + A[i-1] 이기 때문입니다.

```
S[0] = A[0];
for (int i=1; i<n; i++) {
    S[i] = S[i-1] + A[i];
}
```

여기서 2번 연산을 하려면, 수가 바뀔때마다 S를 변경해줘야 합니다. 가장 앞에 있는 0번째 수가 바뀐 경우에는 모든 S 배열을 변경해야 하기 때문에, 시간복잡도는 O(N)이 걸리게 됩니다.

따라서, M과 N이 매우 큰 경우에는 시간이 너무 오래걸리게됩니다.



### 세그먼트 트리

세그먼트 트리를 이용하면, 1번 연산을 O(lgN), 2번 연산도 O(lgN)만에 수행할 수 있습니다.

세그먼트 트리의 리프 노드와 리프 노드가 아닌 다른 노드는 다음과 같은 의미를 가집니다.

- 리프 노드: 배열의 그 수 자체
- 다른 노드: 왼쪽 자식과 오른쪽 자식의 합을 저장함

어떤 노드의 번호가 x일때, 왼쪽 자식의 번호는 2*x, 오른쪽 자식의 번호는 2*x+1이 됩니다.

N = 10인 경우에 세그먼트 트리는 다음과 같습니다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg1.png)

위의 그림은 각 노드가 저장하고 있는 합의 범위를 나타낸 그림입니다. 여기에 각 노드의 번호를 그림으로 나타내면 다음과 같습니다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg2.png)

#### 만들기

만약, N이 2의 제곱꼴인 경우에는 Full Binary Tree 입니다. 또, 그 때 높이는 lgN 입니다. 리프 노드가 N개인 Full Binary Tree는 필요한 노드의 개수가 2*N-1개 입니다.

N이 2의 제곱꼴이 아닌 경우에는 높이가 H = ⌈lgN⌉ 이고, 총 세그먼트 트리를 만드는데 필요한 배열의 크기는 2^(H+1) - 1개가 됩니다.

다음과 같은 과정을 거쳐서 Segment Tree를 만들 수 있습니다.

```c
// a: 배열 a
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}
```

`start == end` 인 경우는 `node`가 리프 노드인 경우입니다. 리프 노드는 배열의 그 원소를 가져야 하기 때문에 `tree[node] = a[start]`가 됩니다.

`node` 의 왼쪽 자식은 `node*2`, 오른쪽 자식은 `node*2+1`이 됩니다. 또, `node`가 담당하는 구간이 `[start,end]` 라면 왼쪽 자식은 `[start,(start+end)/2]`, 오른쪽 자식은 `[(start+end)/2+1,end]`를 담당해야 합니다. 따라서, 재귀 함수를 이용해서 왼쪽 자식과 오른쪽 자식 트리를 만들고, 그 합을 저장해야 합니다.

#### 합 찾기

구간 left, right이 주어졌을 때, 합을 찾으려면 루트부터 트리를 순회하면서 각 노드가 담당하는 구간과 left, right 사이의 관계를 살펴봐야 합니다.

예를 들어, 0~9까지 합을 구하는 경우는 루트 노드 하나만으로 합을 알 수 있습니다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg3.png)

2~4까지 합을 구하는 경우는 다음과 같습니다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg4.png)

5~8까지 합을 구하는 경우는 다음과 같습니다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg5.png)

3~9까지 합을 구하는 경우는 다음과 같습니다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg6.png)

`node`가 담당하고 있는 구간이 `[start,end]` 이고, 합을 구해야하는 구간이 `[left,right]` 이라면 다음과 같이 4가지 경우로 나누어질 수 있습니다.

1. `[left,right]`와 `[start,end]`가 겹치지 않는 경우
2. `[left,right]`가 `[start,end]`를 완전히 포함하는 경우
3. `[start,end]`가 `[left,right]`를 완전히 포함하는 경우
4. `[left,right]`와 `[start,end]`가 겹쳐져 있는 경우 (1, 2, 3 제외한 나머지 경우)

1번 경우에는 `if (left > end || right < start)`로 나타낼 수 있습니다. `left > end`는 `[start,end]` 뒤에 `[left,right]`가 있는 경우이고, `right < start`는 `[start,end]` 앞에 `[left,right]`가 있는 경우입니다. 이 경우에는 겹치지 않기 때문에, 더 이상 탐색을 이어나갈 필요가 없습니다. 따라서 `0`을 리턴해 탐색을 종료합니다.

2번 경우는 `if (left <= start && end <= right)`로 나타낼 수 있습니다. 이 경우도 더 이상 탐색을 이어나갈 필요가 없습니다. 구해야하는 합의 범위는 `[left,right]`인데, `[start,end]`는 그 범위에 모두 포함되고, 그 `node`의 자식도 모두 포함되기 때문에 더 이상 호출을 하는 것은 비효율적입니다. 따라서, `tree[node]`를 리턴해 탐색을 종료합니다.

3번과 4번의 경우에는 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색을 시작해야 합니다.

```c
// node가 담당하는 구간이 start~end이고, 구해야하는 합의 범위는 left~right
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}
```

#### 수 변경하기

중간에 어떤 수를 변경한다면, 그 숫자가 포함된 구간을 담당하는 노드를 모두 변경해줘야 합니다.

다음은 3번째 수를 변경할 때, 변경해야 하는 구간을 나타냅니다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg7.png)

다음 그림은 5를 변경할 때입니다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg8.png)

`index`번째 수를 `val`로 변경한다면, 그 수가 얼마만큼 변했는지를 알아야 합니다. 이 수를 `diff`라고 하면, `diff = val - a[index]`로 쉽게 구할 수 있습니다.

수 변경은 2가지 경우가 있습니다.

1. `[start,end]`에 `index`가 포함되는 경우
2. `[start,end]`에 `index`가 포함되지 않는 경우

`node`의 구간에 포함되는 경우에는 `diff`만큼 증가시켜 합을 변경해 줄 수 있습니다. `tree[node] = tree[node] + diff` 포함되지 않는 경우는 그 자식도 `index`가 포함되지 않기 때문에, 탐색을 중단해야 합니다.

```c
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}
```

리프 노드가 아닌 경우에는 자식도 변경해줘야 하기 때문에, `start != end`로 리프 노드인지 검사를 해야 합니다.

세그먼트 트리를 이용해서 [2042번 문제: 구간 합 구하기](https://www.acmicpc.net/problem/2042) 번을 풀 수 있습니다. 최소값, 최대값도 합을 구하는 세그먼트 트리를 응용해서 구현할 수 있습니다. [10868번 문제: 최솟값](https://www.acmicpc.net/problem/10868), [2357번 문제: 최솟값과 최댓값](https://www.acmicpc.net/problem/2357)

다음은 2042번을 푸는 소스입니다.

```c
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}
int main() {
    int n, m, k;
    scanf("%d %d %d",&n,&m,&k);
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    m += k;
    for (int i=0; i<n; i++) {
        scanf("%lld",&a[i]);
    }
    init(a, tree, 1, 0, n-1);
    while (m--) {
        int t1,t2,t3;
        scanf("%d",&t1);
        if (t1 == 1) {
            int t2;
            long long t3;
            scanf("%d %lld",&t2,&t3);
            t2-=1;
            long long diff = t3-a[t2];
            a[t2] = t3;
            update(tree, 1, 0, n-1, t2, diff);
        } else if (t1 == 2) {
            int t2,t3;
            scanf("%d %d",&t2,&t3);
            printf("%lld\n",sum(tree, 1, 0, n-1, t2-1, t3-1));
        }
    }
    return 0;
}
```