//-----------------------------------------------------------------------------------------------------------//


// 23-2 한터 자료구조 스터디
// 문자열에서의 스택 활용 (백준 4949번)


//-----------------------------------------------------------------------------------------------------------//


#include <stdio.h>
#include <string.h>


char stack[100]; // index 0부터 99까지 할당된 stack 배열
int pointer; // 0으로 초기화된 포인터 변수
int isOver; // 균형이 깨졌을 시 종료하기 위한 변수 (0 일시 false, 1 일시 true)


void push(char value);
void pop(char value);

int main()
{
	while (1)
	{
		char str[100];

		pointer = 0;
		isOver = 0;

		scanf("%[^\n]s", str);
		getchar();

		if (str[0] == '.') // 입력 종료 조건 -> 무한 반복 탈출
			break;

		for (int i = 0; i < strlen(str); i++) // 문자열 index를 0부터 끝까지 검사
		{
			if (str[i] == '(' || str[i] == '[')
				push(str[i]);
			else if (str[i] == ')' || str[i] == ']')
				pop(str[i]);

			if (isOver) // 균형이 깨졌다면 루프 탈출
			{
				printf("no\n");
				break;
			}

			if (i == strlen(str) - 1) // 중간에 균형이 깨지지 않고 문자열의 끝까지 도달했다면
				if (pointer)
					printf("no\n");   // 스택이 비어있지 않다면 no 출력
				else
					printf("yes\n");  // 스택이 비어있다면 yes 출력
		}
	}
}

void push(char value)
{
	/* 순차 자료 구조 stack - push */

	stack[pointer] = value;
	pointer++;

	return;
}

void pop(char value)
{
	/* 순차 자료 구조 stack - pop */

	if (!pointer) // 스택이 비어있다면 균형이 깨짐
	{
		isOver++;
		return;
	}

	if (value == ')') // 소괄호와 만나지 않으면 균형이 깨짐
		if (stack[--pointer] != '(')
			isOver++;

	if (value == ']') // 대괄호와 만나지 않으면 균형이 깨짐
		if (stack[--pointer] != '[')
			isOver++;

	return;
}
