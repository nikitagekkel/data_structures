#pragma once

#include "RingBuffer.h"

/**
������� �� ������ ���������� ������
*/
struct QueueRingBuffer
{
    /**
    ��������� �� ��������� �����
    */
    RingBuffer* Buffer;
};

/**
������������� ������� �� ������ ���������� ������
\param sizeBuffer ������ ������
\return QueueRingBuffer* ��������� �� �������
*/
QueueRingBuffer* InitQueueRingBuffer(int sizeBuffer);

/**
���������� �������� � �������
\param queue ��������� �� �������
\param data ����������� �������
*/
void EnqueueRingBuffer(QueueRingBuffer* queue, int data);

/**
�������� �������� �� �������
\param queue ��������� �� �������
\return int ��������� �������
*/
int DequeueRingBuffer(QueueRingBuffer* queue);

/**
�������� �������
\param queue ��������� �� �������
*/
void DeleteQueueRingBuffer(QueueRingBuffer* queue);

/**
��������� ����� �������
\param queue ��������� �� �������
\return int ����� �������
*/
int LenghtQueueRingBuffer(QueueRingBuffer* queue);