#include <iostream>
#include "Stack.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"
#include "StackQueue.h"

using namespace std;

/**
¬ывод в консоль пунктов меню
*/
void PrintMenu()
{
	system("cls");
	cout << "0. Exit" << endl;
	cout << "\nStack" << endl;
	cout << "1. Initialize stack" << endl;
	cout << "2. Show the stack" << endl;
	cout << "3. Add element to the stack" << endl;
	cout << "4. Delete element from the stack" << endl;
	cout << "5. Delete stack" << endl;

	cout << "\nRing buffer" << endl;
	cout << "6. Initialize buffer" << endl;
	cout << "7. Show the buffer" << endl;
	cout << "8. Add element to the buffer" << endl;
	cout << "9. Get element from the buffer" << endl;
	cout << "10. Get free memory info" << endl;
	cout << "11. Get used memory info" << endl;
	cout << "12. Delete buffer" << endl;

	cout << "\nRing buffer queue" << endl;
	cout << "13. Init queue" << endl;
	cout << "14. Show the queue" << endl;
	cout << "15. Add element in queue" << endl;
	cout << "16. Get element from queue" << endl;
	cout << "17. Delete queue" << endl;

	cout << "\nStack queue" << endl;
	cout << "18. Init queue" << endl;
	cout << "19. Show the queue" << endl;
	cout << "20. Add element in queue" << endl;
	cout << "21. Get element from queue" << endl;
	cout << "22. Delete queue" << endl;
}

/**
¬вод значени€ в переменную с валидацией
*/
int TryInput()
{
	int element;
	cin >> element;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "You entered the incorrect number";
		cout << " please, enter number again: ";
		cin >> element;
	}
	return element;
}

/**
ѕроверка, инициализирована ли структура данных
\param void* pointer указатель на структуру данных
\param string dataStructure название структуры данных
\return true если инициализирован
\return false если не инициализирован
*/
bool IsInitialized(void* pointer, string dataStructure)
{
	if (pointer == nullptr)
	{
		cout << dataStructure + " not initialized yet" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

/**
¬ывод стека в консоль
\param Stack* stack выводимый стек
*/
void PrintStack(Stack* stack)
{
	cout << "Stack: [ ";
	for (int i = stack->Top; i >= 0; i--)
	{
		cout << stack->Buffer[i] << " ";
	}
	cout << "]";
}

/**
¬ывод кольцевого буфера в консоль
\param Stack* buffer выводимый буфер
*/
void PrintRingBuffer(RingBuffer* buffer)
{
	int index = buffer->IndexOutput;

	for (int i = 0; i < buffer->UsedMemory; i++)
	{
		cout << buffer->Buffer[index++] << " -> ";

		if (index > buffer->Size - 1)
		{
			index = 0;
		}
	}
	if (buffer->FreeMemory == buffer->Size)
	{
		cout << "Buffer is empty" << endl;
	}
	else
	{
		cout << "\nBuffer size: " << buffer->Size << endl;
	}
}

int main()
{
	Stack* stack = nullptr;
	RingBuffer* buffer = nullptr;
	QueueRingBuffer* ringBufferQueue = nullptr;
	StackQueue* stackQueue = nullptr;
	while (true)
	{
		PrintMenu();
		cout << "\nEnter nubmer of action: ";
		int variant = TryInput();
		system("cls");
		switch (variant)
		{
			case 0:
			{
				cout << "Program finished" << "\n";
				return -1;
				break;
			}

			case 1:
			{
				if (stack != nullptr)
				{
					cout << "Stack is alredy initilized" << endl;
					break;
				}

				cout << "Enter size of the stack: ";
				int size = TryInput();
				if (size < 0)
				{
					cout << "\nSize can't be negative" << endl;
					break;
				}

				stack = InitStack(size);
				cout << "\nStack was successfully initialized" << endl;
				break;
			}

			case 2:
			{
				if (!IsInitialized(stack, "Stack"))
				{
					break;
				}

				PrintStack(stack);
				cout << endl;
				break;
			}

			case 3:
			{
				if (!IsInitialized(stack, "Stack"))
				{
					break;
				}

				cout << "Enter the element to add to the stack: ";
				int element = TryInput();
				PushStack(stack, element);
				cout << "\nElement was successfully added" << endl;
				break;
			}

			case 4:
			{
				if (!IsInitialized(stack, "Stack"))
				{
					break;
				}

				int element = PopStack(stack);
				if (element != NULL)
				{
					cout << "Element " << element;
					cout << " was succesfully deleted" << endl;
				}
				else
				{
					cout << "Stack is empty" << endl;
				}
				break;
			}

			case 5:
			{
				if (!IsInitialized(stack, "Stack"))
				{
					break;
				}

				stack = DeleteStack(stack);
				cout << "Stack was successfully deleted" << endl;
				break;
			}

			case 6:
			{
				if (buffer != nullptr)
				{
					cout << "Buffer is alredy initilized" << endl;
					break;
				}

				cout << "Enter size of the buffer: ";
				int size = TryInput();
				if (size < 0)
				{
					cout << "\nSize can't be negative" << endl;
					break;
				}

				buffer = InitRingBuffer(size);
				cout << "\nBuffer was successfully initialized" << endl;
				break;
			}

			case 7:
			{
				if (!IsInitialized(buffer, "Buffer"))
				{
					break;
				}

				PrintRingBuffer(buffer);
				break;
			}

			case 8:
			{
				if (!IsInitialized(buffer, "Buffer"))
				{
					break;
				}

				cout << "Enter the element to add to the buffer: ";
				int element = TryInput();
				PushRingBuffer(buffer, element);
				cout << "\nElement was successfully added" << endl;
				break;
			}

			case 9:
			{
				if (!IsInitialized(buffer, "Buffer"))
				{
					break;
				}

				int element = PopRingBuffer(buffer);
				if (element == NULL)
				{
					cout << "Buffer is empty" << endl;
					break;
				}
				else
				{
					cout << "Element: " << element << endl;
				}
				break;
			}

			case 10:
			{
				if (!IsInitialized(buffer, "Buffer"))
				{
					break;
				}

				cout << "Free memory: " << FreeMemoryInfo(buffer) << endl;
				break;
			}

			case 11:
			{
				if (!IsInitialized(buffer, "Buffer"))
				{
					break;
				}

				cout << "Used memory: " << UsedMemoryInfo(buffer) << endl;
				break;
			}

			case 12:
			{
				if (!IsInitialized(buffer, "Buffer"))
				{
					break;
				}

				buffer = DeleteRingBuffer(buffer);
				cout << "Buffer was successfully deleted" << endl;
				break;
			}

			case 13:
			{
				if (ringBufferQueue != nullptr)
				{
					cout << "Queue is alredy initilized" << endl;
					break;
				}

				cout << "Enter size of the queue: ";
				int size = TryInput();
				if (size < 0)
				{
					cout << "\nSize can't be negative" << endl;
					break;
				}

				ringBufferQueue = InitQueueRingBuffer(size);
				cout << "\nQueue was successfully initialized" << endl;
				break;
			}

			case 14:
			{
				if (!IsInitialized(ringBufferQueue, "Ring buffer queue"))
				{
					break;
				}

				#pragma warning(push)
				#pragma warning(disable:6011)
				PrintRingBuffer(ringBufferQueue->Buffer);
				#pragma warning(pop)
				break;
			}

			case 15:
			{
				if (!IsInitialized(ringBufferQueue, "Ring buffer queue"))
				{
					break;
				}

				cout << "Enter the element to add to the queue: ";
				int element = TryInput();
				EnqueueRingBuffer(ringBufferQueue, element);
				cout << "\nElement was successfully added" << endl;
				break;
			}

			case 16:
			{
				if (!IsInitialized(ringBufferQueue, "Ring buffer queue"))
				{
					break;
				}

				int element = DequeueRingBuffer(ringBufferQueue);
				if (element == NULL)
				{
					cout << "Queue is empty" << endl;
					break;
				}
				else
				{
					cout << "Element: " << element << endl;
				}
				break;
			}

			case 17:
			{
				if (!IsInitialized(ringBufferQueue, "Ring buffer queue"))
				{
					break;
				}

				ringBufferQueue = DeleteQueueRingBuffer(ringBufferQueue);
				cout << "Queue was successfully deleted" << endl;
				break;
			}

			case 18:
			{
				if (stackQueue != nullptr)
				{
					cout << "Queue is alredy initilized" << endl;
					break;
				}

				cout << "Enter size of the queue: ";
				int size = TryInput();
				if (size < 0)
				{
					cout << "\nSize can't be negative" << endl;
					break;
				}

				stackQueue = InitStackQueue(size);
				cout << "\nQueue was successfully initialized" << endl;
				break;
			}

			case 19:
			{
				if (!IsInitialized(stackQueue, "Stack queue"))
				{
					break;
				}
				#pragma warning(push)
				#pragma warning(disable:6011)
				PrintStack(stackQueue->InputStack);
				#pragma warning(pop)
				cout << "\n";
				PrintStack(stackQueue->OutputStack);
				break;
			}

			case 20:
			{
				if (!IsInitialized(stackQueue, "Stack queue"))
				{
					break;
				}

				cout << "Enter the element to add to the queue: ";
				int element = TryInput();
				EnqueueStack(stackQueue, element);
				cout << "\nElement was successfully added" << endl;
				break;
			}

			case 21:
			{
				if (!IsInitialized(stackQueue, "Stack queue"))
				{
					break;
				}

				if (LengthStackQueue(stackQueue) > 0)
				{
					cout << "Element: " << DequeueStack(stackQueue) << endl;
				}
				else
				{
					cout << "The queue is empty" << endl;
				}
				break;
			}

			case 22:
			{
				if (!IsInitialized(stackQueue, "Stack queue"))
				{
					break;
				}

				stackQueue = DeleteStackQueue(stackQueue);
				break;
			}
			default:
			{
				cout << "You entered the incorrect number" << endl;
			}
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n";
		system("pause");
	}
}