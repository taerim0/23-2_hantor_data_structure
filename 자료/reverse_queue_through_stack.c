#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 999

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

void stack_push(int value);
int stack_pop();
void queue_print(queue queue);
void queue_push(int value);
int queue_pop();
void queue_reverse(NODE* start, NODE* end);

queue q; // 자료구조 큐

int stack[999]; // 순차 리스트 스택
int stack_index;

int main()
{
    int size;
    int val;
    int isEnd = 0;
    char ordering[10];

    printf("큐의 사이즈 입력 (최대 사이즈 = %d): ", MAXSIZE); // 배열로 구현한 stack 때문에 최대 사이즈 필요
    scanf("%d", &size);

    if (size > MAXSIZE)
    {
        printf("error(403): 최대 사이즈 초과!");
        return 0;
    }

    printf("큐의 원소 입력 (공백으로 구분, %d개 입력)\n: ", size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &val);
        queue_push(val);
    }

    while (1)
    {
        if (isEnd)
            break;

        printf("명령 입력 (push, pop, reverse / break로 명령 종료): ");
        scanf("%s", ordering);

        switch (ordering[1])
        {
        case 'u':
            printf("push할 값 입력(int): ");
            scanf("%d", &val);
            queue_push(val);
            queue_print(q);
            printf("\n");
            break;
        case 'o':
            printf("poped value = %d", queue_pop());
            queue_print(q);
            printf("\n");
            break;
        case 'e':
            printf("reversing\n");
            queue_reverse(q.front, q.rear);
            queue_print(q);
            printf("\n");
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
    /* 연결 자료 구조 queue - push */

    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = value;
    newNode->next = NULL;

    if (!q.size) // 큐가 비어있을 때
    {
        q.front = newNode;
        q.rear = newNode;
    }
    else // 큐가 비어있지 않을 때
    {
        q.rear->next = newNode;
        q.rear = newNode;
    }

    q.size++;

    return;
}

int queue_pop()
{
    /* 연결 자료 구조 queue - pop*/

    if (!q.size) // 큐가 비어있을 때
        return -1;

    NODE* temp = q.front;
    int tempData = temp->data;
    q.front = q.front->next;

    free(temp);

    q.size--;

    return tempData;
}

void queue_print(queue queue)
{
    NODE* temp = queue.front;

    printf("\n현재 큐의 원소 :");

    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }

    return;
}

void stack_push(int value)
{
    stack[stack_index] = value;
    stack_index++;

    return;
}

int stack_pop()
{
    stack_index--;

    return stack[stack_index];
}

//---------------------------------- About Reverse Function -----------------------------------//

void queue_reverse(NODE* start, NODE* end)
{
    NODE* temp = start;

    while (temp != end->next)
    {
        stack_push(temp->data);
        temp = temp->next;
    }

    temp = start;

    while (temp != end->next)
    {
        temp->data = stack_pop();
        temp = temp->next;
    }

    return;
}
