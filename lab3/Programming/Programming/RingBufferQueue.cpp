#include "RingBufferQueue.h"
#include <cstddef>

QueueRingBuffer* InitQueueRingBuffer(int sizeBuffer)
{
	QueueRingBuffer* queue = new QueueRingBuffer();

	queue->Buffer = InitRingBuffer(sizeBuffer);

	return queue;
}

void EnqueueRingBuffer(QueueRingBuffer* queue, int element)
{
	if (queue->Buffer->FreeMemory == 0)
	{
		ResizeRingBuffer(queue->Buffer);
	}

	PushRingBuffer(queue->Buffer, element);
}

int DequeueRingBuffer(QueueRingBuffer* queue)
{
	if (queue->Buffer->UsedMemory > 0)
	{
		return PopRingBuffer(queue->Buffer);
	}
	else
	{
		return NULL;
	}
}

int LenghtQueueRingBuffer(QueueRingBuffer* queue)
{
	return queue->Buffer->UsedMemory;
}

QueueRingBuffer* DeleteQueueRingBuffer(QueueRingBuffer* queue)
{
	delete[] queue->Buffer->Buffer;
	delete queue->Buffer;
	return nullptr;
}