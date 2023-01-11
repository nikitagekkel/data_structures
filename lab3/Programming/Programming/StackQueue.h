#pragma once
#include "Stack.h"

/**
Очередь на основе стеков
*/
struct StackQueue
{
    /**
    Входной стек
    */
    Stack* InputStack = nullptr;

    /**
    Выходной стек
    */
    Stack* OutputStack = nullptr;
};

/**
Инициализация очереди на основе стека
\param size Размер стека
\return StackQueue* Указатель на очередь
*/
StackQueue* InitStackQueue(int size);

/**
Добавление элемента в очередь
\param queue Указатель на очередь
\param element Добавляемый элемент
*/
void EnqueueStack(StackQueue* queue, int element);

/**
Извлечение элемента из очереди
\param queue Указатель на очередь
\return int Извлеченный элемент
*/
int DequeueStack(StackQueue* queue);

/**
Получение количества элементов в очереди
\param queue Указатель на очередь
\return int Количество элементов
*/
int LengthStackQueue(StackQueue* queue);

/**
Удаление очереди
\param queue Указатель на очередь
*/
StackQueue* DeleteStackQueue(StackQueue* queue);