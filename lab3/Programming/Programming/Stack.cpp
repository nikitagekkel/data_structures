#include "Stack.h"
#include <cstddef>

void CheckResize(Stack* stack)
{
	if (stack->Top >= stack->Capacity - 1)
	{
		stack->Capacity = stack->Capacity * stack->GrowthFactor;
		ResizeStack(stack);
		return;
	}

	if (stack->Top <= (stack->Capacity / stack->GrowthFactor) - 1
		&& stack->Capacity > 4)
	{
		stack->Capacity = stack->Capacity / stack->GrowthFactor;
		ResizeStack(stack);
		return;
	}
}

#pragma warning(push)
#pragma warning(disable:6386)
void ResizeStack(Stack* stack)
{
	int* tempArray = new int[stack->Capacity];

	for (int i = 0; i <= stack->Top; i++)
	{
		tempArray[i] = stack->Buffer[i];
	}

	delete[] stack->Buffer;

	stack->Buffer = tempArray;
}
#pragma warning(pop)

Stack* InitStack(int size)
{
	Stack* stack = new Stack();

	stack->Buffer = new int[size];
	stack->Top = -1;
	stack->Capacity = size;
	return stack;
}

void PushStack(Stack* stack, int element)
{
	stack->Top++;

	CheckResize(stack);

	stack->Buffer[stack->Top] = element;
}

int PopStack(Stack* stack)
{
	if (!IsEmptyStack(stack))
	{
		int value = stack->Buffer[stack->Top];
		stack->Top--;

		CheckResize(stack);

		return value;
	}
	else
	{
		return NULL;
	}
}

bool IsEmptyStack(Stack* stack)
{
	return stack->Top == -1;
}

Stack* DeleteStack(Stack* stack)
{
	delete[] stack->Buffer;
	delete stack;
	stack = nullptr;
	return stack;
}