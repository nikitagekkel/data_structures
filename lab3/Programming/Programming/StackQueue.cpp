#include "StackQueue.h"

StackQueue* InitStackQueue(int size)
{
	StackQueue* queue = new StackQueue();

	queue->InputStack = InitStack(size);
	queue->OutputStack = InitStack(size);

	return queue;
}

void EnqueueStack(StackQueue* queue, int element)
{
	PushStack(queue->InputStack, element);
}

int DequeueStack(StackQueue* queue)
{
	if (IsEmptyStack(queue->OutputStack))
	{
		while (!IsEmptyStack(queue->InputStack))
		{
			int data = PopStack(queue->InputStack);
			PushStack(queue->OutputStack, data);
		}
	}

	return PopStack(queue->OutputStack);
}

int LengthStackQueue(StackQueue* queue)
{
	return (queue->InputStack->Top + 1) + (queue->OutputStack->Top + 1);
}

StackQueue* DeleteStackQueue(StackQueue* queue)
{
	DeleteStack(queue->InputStack);
	DeleteStack(queue->OutputStack);
	delete queue->InputStack;
	delete queue->OutputStack;
	return nullptr;
}