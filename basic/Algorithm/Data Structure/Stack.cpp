#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct Stack
{
    node *top;
} Stack;

void initstack(Stack *stack)
{
    stack->top = NULL;
}

void Push(Stack *stack, int num)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = num;
    n->next = stack->top;
    stack->top = n;
}

int IsEmpty(Stack *stack)
{
    return stack->top == NULL;
}

int Pop(Stack *stack)
{
    node *n;
    if (IsEmpty(stack))
        return -1;
    int number;
    n = stack->top;
    number = n->data;
    stack->top = n->next;
    free(n);
    return number;
}

void printstack(Stack *stack)
{
    node *n;
    n = stack->top;
    printf("%d\n", n->data);
}





class stackarray
{
private:
    int *Stack;
    int Size;
    int Top;

public:
    void InitStack(int aSize)
    {
        Size = aSize;
        Stack = (int *)malloc(Size * sizeof(int));
        Top = -1;
    } //스택 크기 결정 함수

    void FreeStack()
    {
        free(Stack);
    } //스택 파괴

    bool Push(int data)
    {
        if (Top < Size - 1)
        {
            Top++;
            Stack[Top] = data;
            return true;
        }
        else
        {
            return false;
        }
    } //데이터 저장

    int Pop()
    {
        if (Top >= 0)
        {
            return Stack[Top--];
        }
        else
        {
            return -1;
        }
    } //데이터 반환
};

void main()
{
    stackarray st;   //객체 생성
    st.InitStack(5); //스택의 크기를 5로 지정
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(5); //1~5까지 데이터 저장
    cout << st.Pop() << "\n";
    cout << st.Pop() << "\n";
    cout << st.Pop() << "\n";
    cout << st.Pop() << "\n";
    cout << st.Pop() << "\n"; //저장됬던 데이터가 5~1 역순으로 반환
    cout << st.Pop() << "\n"; //스택이 비었는대도 반환 요청할경우 언더플로우(-1 출력)
    st.FreeStack();           //스택 파괴
}
