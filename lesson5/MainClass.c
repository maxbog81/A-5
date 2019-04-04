#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>

#define T int
#define STACK_OVERFLOW  -100
// ������ ��������� ���� ������
struct TNode
{
	T value;
	struct TNode *next;
};
typedef struct TNode Node;

struct Stack
{
	Node *head;
	int size;
	int maxSize;
};
struct Stack Stack;

struct Stack Stack2;

void push(T value)
{
	if (Stack.size >= Stack.maxSize) {
		printf("Error stack size");
		return;
	}
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack.head;
	Stack.head = tmp;
	Stack.size++;
	if (Stack.size >= Stack.maxSize)
	{
		exit(STACK_OVERFLOW);
	}		
}

T pop() {
	if (Stack.size == 0)
	{
		printf("Stack is empty");
		return;
	}
	// ��������� ���������
	Node* next = NULL;
	// �������� �������� ������
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	// ������, �� ������� ��������� �������, �������, ���������� ������
	free(next);
	// ���������� ��������, ������� ���� � �������
	Stack.size--;
	return value;
}

void PrintStack()
{
	Node *current = Stack.head;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
}

void push2(T value)
{
	if (Stack2.size >= Stack2.maxSize) {
		printf("Error Stack2 size");
		return;
	}
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack2.head;
	Stack2.head = tmp;
	Stack2.size++;
	if (Stack2.size >= Stack2.maxSize)
	{
		exit(STACK_OVERFLOW);
	}
}

T pop2() {
	if (Stack2.size == 0)
	{
		printf("Stack2 is empty");
		return;
	}
	// ��������� ���������
	Node* next = NULL;
	// �������� �������� ������
	T value;
	value = Stack2.head->value;
	next = Stack2.head;
	Stack2.head = Stack2.head->next;
	// ������, �� ������� ��������� �������, �������, ���������� ������
	free(next);
	// ���������� ��������, ������� ���� � �������
	Stack2.size--;
	return value;
}

void PrintStack2()
{
	Node *current = Stack2.head;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
}

void CopyStackToStack2()
{
	Node *current = Stack.head;
	while (current != NULL)
	{
		push2(current->value);
		current = current->next;
	}
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Rus");
	Stack.maxSize = 100;
	Stack.head = NULL;
	Stack2.maxSize = 100;
	Stack2.head = NULL;

//1.	����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����.
	unsigned int a1;
	printf("����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����.");
	printf("\n ������� ����� �����: ");
	scanf("%d", &a1);
	int x = a1;
	while (x > 0)
	{
		push(x%2);
		x = x / 2;
	}

	PrintStack();

	printf("\n");

//2.�������� � ��������� ����������� ����� �� ������ ������������ ������ �������� �� ��������� ������.���� ������ �� ����������, �� ������ ���������� ��������������� ���������.
//������������ ������� ��������, ����� ������ �� ����� ����������(����������� �������� ���������� ������).

//��� �������� ������������������ ��� ���� ��������������� ����� ��������� �� �������� �� ������ 

	//while (1)
	//{
	//	push(x % 2);
	//	x = x / 2;
	//}
	
//	4.	*������� �������, ���������� ����������� ������(�� ���� ��������� � ������ ����� ������������ ������ ��� �������� ������� ������).

	CopyStackToStack2();

	PrintStack2();

	printf("\n");
	system("pause");
	return 0;
}
