//-----------------------------------------------------------------------------------------------------------//


// 23-2 한터 자료구조 스터디
// 순차 자료 구조 스택의 응용 (백준 10773번)


//-----------------------------------------------------------------------------------------------------------//


#include <stdio.h>

int stack[100000]; // index 0부터 99999까지 할당된 stack 배열
int pointer; // 0으로 초기화된 포인터 변수

void push(int value);
int pop();
int CalculSum();

int main()
{
	int K; // 명령의 수
	int order; // 명령

	scanf("%d", &K);

	while (K--)
	{
		scanf("%d", &order);

		if (!order)      // 명령이 0이라면 pop
			pop();
		else             // 0이 아니라면 그 값을 push
			push(order);
	}

	printf("%d", CalculSum());
}

void push(int value)
{
	/* 순차 자료 구조 stack - push */

	stack[pointer] = value;
	pointer++;

	return;
}

int pop()
{
	/* 순차 자료 구조 stack - pop 
	   스택 최상단 정수 제거 및 리턴, 없다면 -1 리턴 */

	if (!pointer)
		return -1;
	else
		return stack[--pointer];
}

int CalculSum()
{
	int sum = 0;

	for (int i = 0; i < pointer; i++) // 스택의 끝까지 더해 리턴
		sum += stack[i];

	return sum;
}
