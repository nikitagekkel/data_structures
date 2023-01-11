#pragma once
#include "Stack.h"

/**
������� �� ������ ������
*/
struct StackQueue
{
    /**
    ������� ����
    */
    Stack* InputStack = nullptr;

    /**
    �������� ����
    */
    Stack* OutputStack = nullptr;
};

/**
������������� ������� �� ������ �����
\param size ������ �����
\return StackQueue* ��������� �� �������
*/
StackQueue* InitStackQueue(int size);

/**
���������� �������� � �������
\param queue ��������� �� �������
\param element ����������� �������
*/
void EnqueueStack(StackQueue* queue, int element);

/**
���������� �������� �� �������
\param queue ��������� �� �������
\return int ����������� �������
*/
int DequeueStack(StackQueue* queue);

/**
��������� ���������� ��������� � �������
\param queue ��������� �� �������
\return int ���������� ���������
*/
int LengthStackQueue(StackQueue* queue);

/**
�������� �������
\param queue ��������� �� �������
*/
StackQueue* DeleteStackQueue(StackQueue* queue);