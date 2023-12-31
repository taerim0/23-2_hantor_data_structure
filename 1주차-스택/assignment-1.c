//-----------------------------------------------------------------------------------------------------------//


// 23-2 한터 자료구조 스터디
// 순차 자료 구조 (배열)을 활용한 스택 구현 (백준 28278)


//-----------------------------------------------------------------------------------------------------------//


#include <stdio.h>

int stack[1000000]; // index 0부터 999999까지 할당된 stack 배열
int pointer; // 0으로 초기화된 포인터 변수

void push(int value);
int pop();
int size();
int isEmpty();
int back();

int main()
{
	int N; // 명령의 수
	int order; // 명령
	int value; // 값

	scanf("%d", &N);

	while (N--)
	{
		scanf("%d", &order); // 명령 입력

		switch (order)
		{
		case 1:
			scanf("%d", &value);
			push(value);
			break;
		case 2:
			printf("%d\n", pop());
			break;
		case 3:
			printf("%d\n", size());
			break;
		case 4:
			printf("%d\n", isEmpty());
			break;
		case 5:
			printf("%d\n", back());
			break;
		default:
			break;
		}
	}
}


//---------------------------------------- 여기서부터 구현 --------------------------------------------//


void push(int value)
{
	/* 순차 자료 구조 stack - push */
}

int pop()
{
	/* 순차 자료 구조 stack - pop 
	   스택 최상단 정수 제거 및 리턴, 없다면 -1 리턴 */
}

int size()
{
	/* 순차 자료 구조 stack - size
	   스택 정수 개수 리턴 */
}

int isEmpty()
{
	/* 순차 자료 구조 stack - isEmpty
	   스택이 비어있으면 1, 아니면 0 리턴 */
}

int back()
{
	/* 순차 자료 구조 stack - back
	   스택 최상단 정수 및 리턴, 없다면 -1 리턴 */
}
