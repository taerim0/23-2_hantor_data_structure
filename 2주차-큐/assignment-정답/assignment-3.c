//-----------------------------------------------------------------------------------------------------------//


// 23-2 한터 자료구조 스터디
// 연결 자료 구조 큐의 활용 (백준 11866) ver. loop 변수 사용


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

queue q; // 자료구조 큐

int main()
{
    int N; // 사람의 수
    int K;
    int loop = 0; // K번째 사람을 제거하기 위한 loop 변수
    
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++) // 1부터 N까지의 삽입
    {
        push(i);
    }

    printf("<");

    while (q.size) // 사람이 모두 제거될 때까지 반복
    {
        loop++;

        if (loop % K == 0)
        {
            loop = 0;
            printf("%d", pop());
            if (q.size)
            {
                printf(", ");
            }
            else
            {
                printf(">");
            }
        }
        else
            push(pop());
    }
}

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
