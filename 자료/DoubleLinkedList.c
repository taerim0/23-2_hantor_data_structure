// 한터 자료구조 스터디 : 이중 연결 리스트 insert, delete

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}NODE;

typedef struct linkedlist {
	int size;
	NODE* front;
	NODE* back;
}LinkedList;

LinkedList DoubleLinkedList;

void print()
{
	if (DoubleLinkedList.size == 0)
	{
		printf("비어있음\n");
		return;
	}

	NODE* temp = DoubleLinkedList.front;

	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

	return;
}

void insert(int targetidx, int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;

	// 이중 연결 리스트가 비어있을 때
	if (DoubleLinkedList.size == 0)
	{
		newNode->next = NULL, newNode->prev = NULL;

		DoubleLinkedList.front = newNode;
		DoubleLinkedList.back = newNode;
		
		DoubleLinkedList.size++;

		return;
	}
	
	// 이중 연결 리스트 맨 앞에 노드를 생성할 때
	if (targetidx == 0)
	{
		newNode->next = DoubleLinkedList.front;
		DoubleLinkedList.front->prev = newNode;
		newNode->prev = NULL;

		DoubleLinkedList.front = newNode;

		DoubleLinkedList.size++;

		return;
	}

	// 이중 연결 리스트 맨 뒤에 노드를 생성할 때
	if (targetidx == DoubleLinkedList.size)
	{
		newNode->prev = DoubleLinkedList.back;
		DoubleLinkedList.back->next = newNode;
		newNode->next = NULL;

		DoubleLinkedList.back = newNode;

		DoubleLinkedList.size++;

		return;
	}

	NODE* prevNode = NULL;
	NODE* nextNode = NULL;

	if (targetidx >= DoubleLinkedList.size / 2)
	{ // 타겟의 인덱스가 이중 연결 리스트를 절반으로 나눴을 때, 오른쪽에 위치한다면

		int nowidx = DoubleLinkedList.size;
		prevNode = DoubleLinkedList.back;

		while (nowidx != targetidx)
		{
			nowidx--;
			prevNode = prevNode->prev;
			nextNode = prevNode->next;
		}

		newNode->next = nextNode;
		newNode->prev = prevNode;
		prevNode->next = newNode;
		nextNode->prev = newNode;

		DoubleLinkedList.size++;

		return;
	}
	else
	{ // 타겟의 인덱스가 이중 연결 리스트를 절반으로 나눴을 때, 왼쪽에 위치한다면

		int nowidx = 0;
		nextNode = DoubleLinkedList.front;

		while (nowidx != targetidx)
		{
			nowidx++;
			nextNode = nextNode->next;
			prevNode = nextNode->prev;
		}

		newNode->next = nextNode;
		newNode->prev = prevNode;
		prevNode->next = newNode;
		nextNode->prev = newNode;

		DoubleLinkedList.size++;

		return;
	}
}

void delete(int targetidx)
{
	NODE* targetNode = NULL;

	// 이중 연결 리스트의 사이즈가 1일 때
	if (DoubleLinkedList.size == 1)
	{
		targetNode = DoubleLinkedList.front;

		DoubleLinkedList.front = NULL;
		DoubleLinkedList.back = NULL;

		free(targetNode);

		DoubleLinkedList.size--;

		return;
	}

	// 이중 연결 리스트의 front일 때
	if (targetidx == 0)
	{
		targetNode = DoubleLinkedList.front;
		targetNode->next->prev = NULL;

		DoubleLinkedList.front = targetNode->next;

		free(targetNode);

		DoubleLinkedList.size--;

		return;
	}

	// 이중 연결 리스트의 back일 때
	if (targetidx == DoubleLinkedList.size - 1)
	{
		targetNode = DoubleLinkedList.back;
		targetNode->prev->next = NULL;

		DoubleLinkedList.back = targetNode->prev;

		free(targetNode);

		DoubleLinkedList.size--;

		return;
	}

	if (targetidx >= DoubleLinkedList.size / 2)
	{ // 타겟의 인덱스가 이중 연결 리스트를 절반으로 나눴을 때, 오른쪽에 위치한다면

		int nowidx = DoubleLinkedList.size - 1;
		targetNode = DoubleLinkedList.back;

		while (nowidx != targetidx)
		{
			nowidx--;
			targetNode = targetNode->prev;
		}

		targetNode->prev->next = targetNode->next;
		targetNode->next->prev = targetNode->prev;

		free(targetNode);

		DoubleLinkedList.size--;

		return;
	}
	else
	{ // 타겟의 인덱스가 이중 연결 리스트를 절반으로 나눴을 때, 왼쪽에 위치한다면

		int nowidx = 0;
		targetNode = DoubleLinkedList.front;

		while (nowidx != targetidx)
		{
			nowidx++;
			targetNode = targetNode->next;
		}

		targetNode->prev->next = targetNode->next;
		targetNode->next->prev = targetNode->prev;

		free(targetNode);

		DoubleLinkedList.size--;

		return;
	}
}

int order;
int pos, d;

int main()
{
	while (1)
	{
		printf("명령 입력 (0: 출력, 1: 삽입, 2: 제거, 3: 종료) : ");
		scanf("%d", &order);

		switch (order)
		{
		case 0:
			print();
			break;
		case 1:
			printf("삽입 할 위치, 데이터 값 입력 (공백으로 구분, 위치 범위 0 ~ %d) : ", DoubleLinkedList.size);
			scanf("%d %d", &pos, &d);
			if (pos >= 0 && pos <= DoubleLinkedList.size)
			{
				insert(pos, d);
				printf("삽입 완료!\n");
			}
			else
			{
				printf("잘못된 위치\n");
			}
			break;
		case 2:
			if (DoubleLinkedList.size == 0)
			{
				printf("제거 불가\n");
				break;
			}
			printf("제거 할 위치 입력 (위치 범위 0 ~ %d) : ", DoubleLinkedList.size - 1);
			scanf("%d", &pos);
			if (pos >= 0 && pos < DoubleLinkedList.size)
			{
				delete(pos);
				printf("제거 완료!\n");
			}
			else
			{
				printf("잘못된 위치\n");
			}
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}
}
