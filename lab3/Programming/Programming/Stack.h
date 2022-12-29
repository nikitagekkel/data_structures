#pragma once

struct Node
{
	int Data = 0;
	Node* Next = nullptr;
};

struct Stack
{
	Node* Head = nullptr;
	Node* Top = nullptr;
};

void Push(Stack* stack, int data);
bool Pop(Stack* stack);
bool DeleteStack(Stack* stack);