# 3주차 - 이중 연결 리스트, 덱

------------------------

#### 1주차와 2주차를 배웠다면 어렵지 않게 풀 수 있을 겁니다!

-------------------------

### ASSIGNMENT 1

[백준 28279번 문제](https://www.acmicpc.net/problem/28279). '여기서부터 구현' 아래부터 풀면 됩니당.

```c
//-----------------------------------------------------------------------------------------------------------//


// 23-2 한터 자료구조 스터디
// 연결 자료 구조를 활용한 덱 구현 (백준 28279)


//-----------------------------------------------------------------------------------------------------------//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}NODE;
// node 구조체

typedef struct deque
{
    int size;
    NODE* front;
    NODE* back;
}deque;
// deque 구조체

void push_back(int value);
void push_front(int value);
int pop_front();
int pop_back();
int size();
int empty();
int front();
int back();

deque d; // 자료구조 덱

int main()
{
    int N; // 명령의 수
    int order; // 명령
    int value;

    scanf("%d", &N);

    while (N--)
    {
        scanf("%d", order);
        switch (order)
        {
        case 1:
            scanf("%d", &value);
            push_front(value);
            break;
        case 2:
            scanf("%d", &value);
            push_back(value);
            break;
        case 3: 
            printf("%d\n", pop_front());
            break;
        case 4: 
            printf("%d\n", pop_back());
            break;
        case 5: 
            printf("%d\n", size());
            break;
        case 6: 
            printf("%d\n", empty());
            break;
        case 7:
            printf("%d\n", front());
            break;
        case 8:
            printf("%d\n", back());
            break;
        }
    }
}

//---------------------------------------- 여기서부터 구현 --------------------------------------------//

void push_front(int value)
{
    /* 연결 자료 구조 deque - push_front
       malloc을 사용해 node의 메모리를 할당하고, 덱의 front에 넣어주세요.*/
}

void push_back(int value)
{
    /* 연결 자료 구조 deque - push_back
       malloc을 사용해 node의 메모리를 할당하고, 덱의 back에 넣어주세요.*/
}

int pop_front()
{
    /* 연결 자료 구조 deque - pop_front
       덱의 첫 번째 노드 제거 및 데이터 리턴, 없다면 -1 리턴
       free를 사용해 동적 할당을 해제해 주세요.*/
}

int pop_back()
{
    /* 연결 자료 구조 deque - pop_back
       덱의 첫 번째 노드 제거 및 데이터 리턴, 없다면 -1 리턴
       free를 사용해 동적 할당을 해제해 주세요.*/
}

int size()
{
    /* 연결 자료 구조 deque - size
       큐 노드 개수 리턴 */
}

int empty()
{
    /* 연결 자료 구조 deque - empty
       큐가 비어있으면 1, 아니면 0 리턴 */
}

int front()
{
    /* 연결 자료 구조 deque - front
       첫 번째 노드의 데이터 리턴, 없다면 -1 리턴 */
}

int back()
{
    /* 연결 자료 구조 deque - back
       마지막 노드의 데이터 리턴, 없다면 -1 리턴 */
}
```

-------------------------

### ASSIGNMENT 2

[백준 2346번 문제](https://www.acmicpc.net/problem/2346). 생각이 필요한 덱 응용 문제입니다.

-------------------------

### ASSIGNMENT 3

[백준 1021번 문제](https://www.acmicpc.net/problem/1021). 큐 같나요? 덱 응용 문제입니다!!

-------------------------

### ASSIGNMENT 4

[백준 20923번 문제](https://www.acmicpc.net/problem/20923). 처음 등장한 실버 1 문제입니다. 덱을 응용하고, 시뮬레이션이 필요합니다

