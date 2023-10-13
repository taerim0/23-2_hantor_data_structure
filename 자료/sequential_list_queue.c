// 23-2 한터 자료구조 스터디 : 순차리스트로 구현한 큐

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 999

void queue_print();
void queue_push(int value);
int queue_pop();
int queue_size();

int queue[MAXSIZE];
int front, rear;

int main()
{
    int val;
    int isEnd = 0;
    char ordering[10];

    while (1)
    {
        if (isEnd)
            break;

        printf("명령 입력 (push, pop, size / break로 명령 종료): ");
        scanf("%s", ordering);

        switch (ordering[1])
        {
        case 'u':
            if (rear > 999)
            {
                printf("큐가 최대 사이즈를 초과했습니다.");
                isEnd++;
                break;
            }
            printf("push할 값 입력(int): ");
            scanf("%d", &val);
            queue_push(val);
            queue_print();
            printf("\n");
            break;
        case 'o':
            printf("poped value = %d", queue_pop());
            queue_print();
            printf("\n");
            break;
        case 'i':
            printf("size of queue: %d\n", queue_size());
            break;
        case 'r':
            isEnd++;
            break;
        default:
            break;
        }
    }
}

void queue_push(int value)
{
    /* 순차 자료 구조 queue - push */

    queue[rear] = value;
    rear++;

    return;
}

int queue_pop()
{
    /* 순차 자료 구조 queue - pop*/

    if (front == rear) // 큐가 비어있을 때
        return -1;

    front++;

    return queue[front - 1];
}

void queue_print()
{
    printf("\n현재 큐의 원소 :");
    for (int i = front; i < rear; i++)
    {
        printf(" %d", queue[i]);
    }

    return;
}

int queue_size()
{
    return rear - front;
}
