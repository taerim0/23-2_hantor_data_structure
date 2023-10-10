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
    /* 연결 자료 구조 queue - push */

    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = value;
    newNode->next = NULL;

    if (!q.size)
    {
        q.front = newNode;
        q.rear = newNode;
    }
    else
    {
        q.rear->next = newNode;
        q.rear = newNode;
    }

    q.size++;

    return;
}

int pop()
{
    /* 연결 자료 구조 queue - pop
       큐 첫 번째 노드 제거 및 데이터 리턴, 없다면 -1 리턴
       free를 사용해 동적 할당을 해제해 주세요.*/

    if (!q.size)
        return -1;
    
    NODE* temp = q.front;
    int tempData = temp->data;
    q.front = q.front->next;

    free(temp);

    q.size--;

    return tempData;
}

int size()
{
    /* 연결 자료 구조 queue - size
       큐 노드 개수 리턴 */

    return q.size;
}

int empty()
{
    /* 연결 자료 구조 queue - empty
       큐가 비어있으면 1, 아니면 0 리턴 */

    if (!q.size)
        return 1;
    return 0;
}

int front()
{
    /* 연결 자료 구조 queue - front
       첫 번째 노드의 데이터 리턴, 없다면 -1 리턴 */

    if (!q.size)
        return -1;
    return q.front->data;
}

int back()
{
    /* 연결 자료 구조 queue - back
       마지막 노드의 데이터 리턴, 없다면 -1 리턴 */

    if (!q.size)
        return -1;
    return q.rear->data;
}
