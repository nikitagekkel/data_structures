#pragma once

#include "RingBuffer.h"

/**
Очередь на основе кольцевого буфера
*/
struct QueueRingBuffer
{
    /**
    Указатель на кольцевой буфер
    */
    RingBuffer* Buffer;
};

/**
Инициализация очереди на основе кольцевого буфера
\param sizeBuffer Размер буфера
\return QueueRingBuffer* Указатель на очередь
*/
QueueRingBuffer* InitQueueRingBuffer(int sizeBuffer);

/**
Добавление элемента в очередь
\param queue Указатель на очередь
\param data Добавляемый элемент
*/
void EnqueueRingBuffer(QueueRingBuffer* queue, int data);

/**
Удаление элемента из очереди
\param queue Указатель на очередь
\return int Удаленный элемент
*/
int DequeueRingBuffer(QueueRingBuffer* queue);

/**
Удаление очереди
\param queue Указатель на очередь
*/
void DeleteQueueRingBuffer(QueueRingBuffer* queue);

/**
Получение длины очереди
\param queue Указатель на очередь
\return int Длина очереди
*/
int LenghtQueueRingBuffer(QueueRingBuffer* queue);