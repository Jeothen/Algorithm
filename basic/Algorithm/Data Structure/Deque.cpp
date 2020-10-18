#include <iostream>
#include <cstdio>

using namespace std;

class NODE
{
    friend class DEQUE;

private:
    int data;
    NODE *left;
    NODE *right;
};

class DEQUE
{
private:
    int sz;
    NODE *head;
    NODE *tail;

public:
    DEQUE()
    {
        //cout << "\n\n생성자 호출\n\n" << endl;
        sz = 0;
        NODE *dummyHead = new NODE;
        NODE *dummyTail = new NODE;

        dummyHead->left = dummyHead->right = NULL;
        dummyTail->left = dummyTail->right = NULL;

        head = dummyHead;
        tail = dummyTail;
    }

    ~DEQUE()
    {
        init();
        delete head;
        delete tail;

        //cout << "\n\n소멸자 호출\n\n " << endl;
    }

    void init()
    {
        // 더미노드 사이 모든 값 삭제
        NODE *pos = head;
        while (pos->right != NULL)
        {
            NODE *delNode = pos;
            pos = pos->right;

            delete delNode;
        }
        delete tail; // 마지막 tail이 삭제되지 않았다.

        // 더미노드 새로 생성(생성자와 동일)
        NODE *dummyHead = new NODE;
        NODE *dummyTail = new NODE;

        dummyHead->left = dummyHead->right = NULL;
        dummyTail->left = dummyTail->right = NULL;

        head = dummyHead;
        tail = dummyTail;
        sz = 0;
    }
    void push_front(int val)
    {
        if (head->right == NULL)
        {
            NODE *newNode = new NODE;
            newNode->data = val;

            newNode->left = head;
            head->right = newNode;

            newNode->right = tail;
            tail->left = newNode;
        }

        else
        {
            NODE *newNode = new NODE;
            newNode->data = val;

            newNode->right = head->right;
            head->right->left = newNode;

            newNode->left = head;
            head->right = newNode;
        }

        sz++;
    }

    void push_back(int val)
    {
        if (head->right == NULL)
        {
            NODE *newNode = new NODE;
            newNode->data = val;

            newNode->left = head;
            head->right = newNode;

            newNode->right = tail;
            tail->left = newNode;
        }

        else
        {
            NODE *newNode = new NODE;
            newNode->data = val;

            newNode->left = tail->left;
            tail->left->right = newNode;

            newNode->right = tail;
            tail->left = newNode;
        }

        sz++;
    }

    void pop_front()
    {
        if (!sz)
            cout << "deque가 비어있습니다." << endl;
        else
        {
            NODE *pos = head->right;
            head->right->right->left = head;
            head->right = head->right->right;

            delete pos;

            sz--;
        }
    }
    void pop_back()
    {
        if (!sz)
            cout << "deque가 비어있습니다." << endl;
        else
        {
            NODE *pos = tail->left;
            tail->left->left->right = tail;
            tail->left = tail->left->left;

            delete pos;

            sz--;
        }
    }
    int front()
    {
        if (!sz)
            cout << "deque가 비어있습니다." << endl;
        else
            return head->right->data;
    }
    int back()
    {
        if (!sz)
            cout << "deque가 비어있습니다." << endl;
        else
            return tail->left->data;
    }
    void all()
    {
        NODE *pos = head;
        while (pos != NULL)
        {
            // 더미노드는 출력하지 않는다.
            if (!(pos == head || pos == tail))
                cout << pos->data << " ";

            pos = pos->right;
        }
        cout << endl;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        return !sz;
    }
};
void menu()
{
    cout << "┏━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ 1 :: init　　　┃" << endl;
    cout << "┃ 2 :: push_front┃" << endl;
    cout << "┃ 3 :: push_back ┃" << endl;
    cout << "┃ 4 :: pop_front ┃" << endl;
    cout << "┃ 5 :: pop_back　┃" << endl;
    cout << "┃ 6 :: front　　 ┃" << endl;
    cout << "┃ 7 :: back　　　┃" << endl;
    cout << "┃ 8 :: all 　　　┃" << endl;
    cout << "┃ 9 :: size　　　┃" << endl;
    cout << "┃ 10 :: empty　　┃" << endl;
    cout << "┃ 11 :: exit　　 ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━┛" << endl;
}
int main()
{
    DEQUE dq;
    cout << "Datastructure :: Deque" << endl;
    while (1)
    {
        menu();

        int num;
        cin >> num;

        if (num == 1)
            dq.init();

        else if (num == 2)
        {
            int val;
            cout << "값 :: ";
            cin >> val;
            dq.push_front(val);
        }

        else if (num == 3)
        {
            int val;
            cout << "값 :: ";
            cin >> val;
            dq.push_back(val);
        }

        else if (num == 4)
            dq.pop_front();

        else if (num == 5)
            dq.pop_back();

        else if (num == 6)
            cout << dq.front() << endl;

        else if (num == 7)
            cout << dq.back() << endl;

        else if (num == 8)
            dq.all();

        else if (num == 9)
            cout << dq.size() << endl;

        else if (num == 10)
            cout << (dq.empty() ? "empty" : "non empty") << endl;

        else if (num == 11)
            break;
        cout << endl;
    }
    return 0;
}
