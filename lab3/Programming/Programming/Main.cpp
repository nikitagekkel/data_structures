#include <iostream>
#include "Stack.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"

using namespace std;

/**
¬ывод в консоль пунктов меню
*/
void PrintMenu()
{
	system("cls");
	cout << "0. Exit" << endl;
	cout << "Stack" << endl;
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
	cout << "14. Add element in queue" << endl;
	cout << "15. Get element from queue" << endl;
	cout << "16. Delete queue" << endl;

	cout << "\nStack queue" << endl;
	cout << "17. Delete buffer" << endl;
	cout << "18. Delete buffer" << endl;
	cout << "19. Delete buffer" << endl;
	cout << "20. Delete buffer" << endl;
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

/**
¬ывод очереди на основе кольцевого буфера в консоль
\param QueueRingBuffer* queue выводима€ очередь
*/
void PrintRingBufferQueue(QueueRingBuffer* queue)
{
	int index = queue->Buffer->IndexOutput;

	for (int i = 0; i < queue->Buffer->UsedMemory; i++)
	{
		cout << queue->Buffer->Buffer[index++] << " -> ";

		if (index > queue->Buffer->Size - 1)
		{
			index = 0;
		}
	}
	if (queue->Buffer->FreeMemory == queue->Buffer->Size)
	{
		cout << "Buffer is empty" << endl;
	}
	cout << endl;
}

int main()
{
	Stack* stack = nullptr;
	RingBuffer* buffer = nullptr;
	QueueRingBuffer* ringBufferQueue = nullptr;
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
			if (IsInitialized(stack, "Stack") == false)
			{
				break;
			}

			PrintStack(stack);
			cout << endl;
			break;
		}

		case 3:
		{
			if (IsInitialized(stack, "Stack") == false)
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
			if (IsInitialized(stack, "Stack") == false)
			{
				break;
			}

			bool isDeleted = PopStack(stack);
			if (isDeleted == true)
			{
				cout << "Element was succesfully deleted" << endl;
			}
			else
			{
				cout << "Stack is empty" << endl;
			}
			break;
		}

		case 5:
		{
			if (IsInitialized(stack, "Stack") == false)
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
			if (IsInitialized(buffer, "Buffer") == false)
			{
				break;
			}

			PrintRingBuffer(buffer);
			break;
		}

		case 8:
		{
			if (IsInitialized(buffer, "Buffer") == false)
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
			if (IsInitialized(buffer, "Buffer") == false)
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
			if (IsInitialized(buffer, "Buffer") == false)
			{
				break;
			}

			cout << "Free memory: " << FreeMemoryInfo(buffer) << endl;
			break;
		}

		case 11:
		{
			if (IsInitialized(buffer, "Buffer") == false)
			{
				break;
			}

			cout << "Used memory: " << UsedMemoryInfo(buffer) << endl;
			break;
		}

		case 12:
		{
			if (IsInitialized(buffer, "Buffer") == false)
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