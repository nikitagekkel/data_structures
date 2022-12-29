#include <stdlib.h>
#include "Stack.h"

using namespace std;

void Push(Stack* stack, int data)
{
	Node* node = new Node();
	node->Data = data;

	if (stack->Head == nullptr)
	{
		stack->Head = node;
	}
	else if (stack->Top == nullptr)
	{
		stack->Top = node;
		stack->Top->Next = stack->Head;
	}
	else
	{
		Node* top = stack->Top;
		stack->Top = node;
		stack->Top->Next = top;
	}
}

bool Pop(Stack* stack)
{
	if (stack->Head == nullptr)
	{
		return false;
	}
	
	if (stack->Top == stack->Head)
	{
		delete stack->Head;
		stack->Head = nullptr;
	}
}

bool DeleteStack(Stack* stack)
{
	if (stack->Head == nullptr)
	{
		return false;
	}
	else
	{
		while (stack->Top->Next != nullptr)
		{
			Pop(stack);
		}
	}

	return true;
}