#pragma once

/**
Хранит данные о стеке
 */
struct Stack
{
	/**
	Указатель на массив данных
	*/
	int* Buffer = nullptr;

	/**
	Индекс последнего элемента стека
	*/
	int Top = -1;

	/**
	Размер стека
	*/
	int Capacity = 0;
	
	/**
	Фактор роста стека
	*/
	const int GrowthFactor = 2;
};

/**
Проверяет необходимость изменения размера стека
\param stack указатель на стек
*/
void CheckResize(Stack* stack);

/**
Изменяет размер стека
\param stack указатель на стек
*/
void ResizeStack(Stack* stack);

/**
Инициализирует стек
\param size размер буфера стека
*/
Stack* InitStack(int size);

/**
Добавляет элемент в конец стека
\param stack указатель на стек
\param data данные, которые нужно добавить в стек
 */
void PushStack(Stack* stack, int element);

/**
Удаляет элемент из начала стека
\param stack указатель на стек
\return int value значение удаленного элемента
*/
int PopStack(Stack* stack);

/**
Проверка, пустой ли стек
\param Stack* stack указатель на стек
*/
bool IsEmptyStack(Stack* stack);

/**
Удаляет стек
\param stack указатель на стек
*/
Stack* DeleteStack(Stack* stack);