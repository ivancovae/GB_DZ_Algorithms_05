#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void solution00();
void solution01();
void solution02();

void menu();

// Задание выполнил Иванцов Александр Евгеньевич
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	int select = 0;

	do
	{
		menu();
		scanf("%i", &select);
		switch (select)
		{
		case 1:
			solution00();
			break;
		case 2:
			solution01();
			break;
		case 3:
			solution02();
			break;
		case 0:
			printf("Программа закончила свое выполнение.\n");
			break;
		default:
			printf("Некорректный символ, введите значения из списка меню.\n");
		}
	} while (select != 0);
	system("pause");
	return 0;
}

void menu()
{
	printf("Меню выбора решения задания:\n\n");

	printf("1. Решение задачи 1\n");
	printf("2. Решение задачи 2\n");
	printf("3. Решение задачи 3\n");
	printf("0. Завершение выполнения программы\n");
}

void descriptionTask(char *task)
{
	printf("\n##########################################\n");
	printf("\nУсловие задачи:\n");
	printf(task);
}

void endTask()
{
	printf("\n##########################################\n\n");
}

#define T long

// тип указателя на ноду
typedef struct tagNode * pNode;

// тип ноды
typedef struct tagNode 
{
	T value;
	pNode next;
} Node;

// тип структуры стека
typedef struct tagStack 
{
	pNode head;
	int size;
	int maxSize;
} Stack;

// рабочий стек
Stack stack;

// добавить элемент в стек
void push(T value)
{
	if (stack.size == stack.maxSize)
	{
		printf("Стек заполнен, необходимо увеличить размер стека.\n");
		return;
	}
	pNode tmp = (pNode)malloc(sizeof(Node));
	// Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.
	//	Если память не выделяется, то выводится соответствующее сообщение. 
	//	Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных). Не удалось, полагаю это из-за ограничения в 2ГБ на приложение для Windows 10.
	if (tmp == NULL) // если выделение памяти не выполнилось
	{
		printf("Выделение памяти для нового элемента не удалось.\n");
		return;
	}
	tmp->value = value;
	tmp->next = stack.head;
	stack.head = tmp;
	stack.size++;
}

// вытаскивание последнего элемента из стека с возвратом значения
T pop()
{
	if (stack.size == 0)
	{
		printf("Стек пуст, необходимо добавить элементы.\n");
		return;
	}
	pNode next = NULL;
	T value = stack.head->value;
	next = stack.head;
	stack.head = stack.head->next;
	free(next);
	stack.size--;
	return value;
}

void printStack()
{
	pNode current = stack.head;
	while (current != NULL)
	{
		printf("%i", current->value);
		current = current->next;
	}
}

void initStack()
{
	stack.maxSize = 100;
	stack.size = 0;
	stack.head = NULL;
}

void convertToBinRec(long n)
{
	if (n <= 0)
		return;
	push(n % 2);
	convertToBinRec(n / 2);
}

void printBin()
{
	while (stack.size > 0)
	{
		printf("%i", pop());
	}
}

// Задание 1: Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
void solution00()
{
	descriptionTask("Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.\n");
	// Ввод данных
	initStack();

	int number;
	printf("Введите число для перевода в двоичную систему: ");
	scanf("%d", &number);

	// Решение
	printf("Результат: \n");
	convertToBinRec(number);
	printBin();

	endTask();
}

// Задание 2: Решить задачу о нахождении длины максимальной последовательности с помощью матрицы
void solution01()
{
	descriptionTask("Решить задачу о нахождении длины максимальной последовательности с помощью матрицы\n");
	// Ввод данных
	
	// Решение
	printf("Результат: \n");
	
	endTask();
}

// Задание 3: ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу.Здесь алгоритм решения такой же как и в задаче о 8 ферзях.Разница только в проверке
//				положения коня.
void solution02()
{
	descriptionTask("***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу.Здесь алгоритм решения такой же как и в задаче о 8 ферзях. Разница только в проверке положения коня.\n");
	// Ввод данных
	
	// Решение
	printf("Результат: \n");	

	endTask();
}