#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>

#define T int
#define STACK_OVERFLOW  -100
// Опишем структуру узла списка
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
struct Stack Stack3;

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
	// Временный указатель
	Node* next = NULL;
	// Значение «наверху» списка
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	// Запись, на которую указывала «голова», удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в «голове»
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
	// Временный указатель
	Node* next = NULL;
	// Значение «наверху» списка
	T value;
	value = Stack2.head->value;
	next = Stack2.head;
	Stack2.head = Stack2.head->next;
	// Запись, на которую указывала «голова», удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в «голове»
	Stack2.size--;
	return value;
}

void push3(T value)
{
	if (Stack3.size >= Stack3.maxSize) {
		printf("Error Stack3 size");
		return;
	}
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack3.head;
	Stack3.head = tmp;
	Stack3.size++;
	if (Stack3.size >= Stack3.maxSize)
	{
		exit(STACK_OVERFLOW);
	}
}

T pop3() {
	if (Stack3.size == 0)
	{
		printf("Stack3 is empty");
		return;
	}
	// Временный указатель
	Node* next = NULL;
	// Значение «наверху» списка
	T value;
	value = Stack3.head->value;
	next = Stack3.head;
	Stack3.head = Stack3.head->next;
	// Запись, на которую указывала «голова», удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в «голове»
	Stack3.size--;
	return value;
}

void CopyStackToStack()
{
	Node *current = Stack.head;
	while (current != NULL)
	{
		push2(current->value);
		current = current->next;
	}

	current = Stack2.head;
	while (current != NULL)
	{
		push3(current->value);
		current = current->next;
	}
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

void PrintStack3()
{
	Node *current = Stack3.head;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Rus");
	//setlocale(LC_ALL, "en_US.UTF-8");
	Stack.maxSize = 100;
	Stack.head = NULL;
	Stack2.maxSize = 100;
	Stack2.head = NULL;
	Stack3.maxSize = 100;
	Stack3.head = NULL;

	//1.	Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
	unsigned int a1;
	printf("Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.");
	printf("\n Введите целое число: ");
	scanf("%d", &a1);
	int x = a1;
	while (x > 0)
	{
		push(x % 2);
		x = x / 2;
	}

	PrintStack();

	printf("\n");

	//2.Добавить в программу «Реализация стека на основе односвязного списка» проверку на выделение памяти.Если память не выделяется, то должно выводиться соответствующее сообщение.
	//Постарайтесь создать ситуацию, когда память не будет выделяться(добавлением большого количества данных).

	//Для проверки расскомментировать код ниже Закомментировал чтобы программа не вылетала по ошибке 

		//while (1)
		//{
		//	push(x % 2);
		//	x = x / 2;
		//}

	//	4.	*Создать функцию, копирующую односвязный список(то есть создающую в памяти копию односвязного списка без удаления первого списка).
	printf("Скопированный список:");

	CopyStackToStack();
	PrintStack3();

	printf("\n");
	system("pause");
	return 0;
}
