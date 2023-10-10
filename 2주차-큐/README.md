# 2주차 - 연결 자료 구조, 큐

------------------------

#### 연결 리스트, 큐는 동적 할당, 포인터 개념이 사용되어서 어렵지만.. 파이팅입니다

-------------------------

### ASSIGNMENT 1

[백준 18258번 문제](https://www.acmicpc.net/problem/18258). '여기서부터 구현' 아래부터 풀면 됩니당.

```c
//-----------------------------------------------------------------------------------------------------------//


// 23-2 한터 자료구조 스터디
// 연결 자료 구조를 활용한 큐 구현 (백준 18258)


//-----------------------------------------------------------------------------------------------------------//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE;
// node 구조체

typedef struct queue
{
    int size;
    NODE* front;
    NODE* rear;
}queue;
// queue 구조체

void push(int value);
int pop();
int size();
int empty();
int front();
int back();

queue q; // 자료구조 큐

int main()
{
    int N; // 명령의 수
    char order[6]; // 명령
    int value;

    scanf("%d", &N);

    while (N--)
    {
        scanf("%s", order);
        switch (order[1])
        {
        case 'u': // pUsh
            scanf("%d", &value);
            push(value);
            break;
        case 'o': // pOp
            printf("%d\n", pop());
            break;
        case 'i': // sIze
            printf("%d\n", size());
            break;
        case 'm': // eMpty
            printf("%d\n", empty());
            break;
        case 'r': // fRont
            printf("%d\n", front());
            break;
        case 'a': // bAck
            printf("%d\n", back());
            break;
        }
    }
}

//---------------------------------------- 여기서부터 구현 --------------------------------------------//

void push(int value)
{
    /* 연결 자료 구조 queue - push
       malloc을 사용해 node의 메모리를 할당하고, 큐에 넣어주세요.*/
}

int pop()
{
    /* 연결 자료 구조 queue - pop
       큐 첫 번째 노드 제거 및 데이터 리턴, 없다면 -1 리턴
       free를 사용해 동적 할당을 해제해 주세요.*/
}

int size()
{
    /* 연결 자료 구조 queue - size
       큐 노드 개수 리턴 */
}

int empty()
{
    /* 연결 자료 구조 queue - empty
       큐가 비어있으면 1, 아니면 0 리턴 */
}

int front()
{
    /* 연결 자료 구조 queue - front
       첫 번째 노드의 데이터 리턴, 없다면 -1 리턴 */
}

int back()
{
    /* 연결 자료 구조 queue - back
       마지막 노드의 데이터 리턴, 없다면 -1 리턴 */
}
```

-------------------------

### ASSIGNMENT 2

[백준 2164번 문제](https://www.acmicpc.net/problem/2164). 단순한 큐 응용 문제입니다.

-------------------------

### ASSIGNMENT 3

[백준 11866번 문제](https://www.acmicpc.net/problem/11866). assignment 2와 비슷한 큐 응용 문제입니다. 다만 나열된 자료의 출력 방식을 고려해 봐야 합니다.

-------------------------

### ASSIGNMENT 4

[백준 12789번 문제](https://www.acmicpc.net/problem/12789). 이전에 순차 리스트를 사용해 스택을을 구현했다면, 연결 리스트로 구현하는 스택도 다뤄봅시다. (정답은 10. 20.에 올라와요오오오)

