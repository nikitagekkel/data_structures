#pragma once

/**
������ ������ � �����
 */
struct Stack
{
	/**
	��������� �� ������ ������
	*/
	int* Buffer = nullptr;

	/**
	������ ���������� �������� �����
	*/
	int Top = -1;

	/**
	������ �����
	*/
	int Capacity = 0;
	
	/**
	������ ����� �����
	*/
	const int GrowthFactor = 2;
};

/**
��������� ������������� ��������� ������� �����
\param stack ��������� �� ����
*/
void CheckResize(Stack* stack);

/**
�������� ������ �����
\param stack ��������� �� ����
*/
void ResizeStack(Stack* stack);

/**
�������������� ����
\param size ������ ������ �����
*/
Stack* InitStack(int size);

/**
��������� ������� � ����� �����
\param stack ��������� �� ����
\param data ������, ������� ����� �������� � ����
 */
void PushStack(Stack* stack, int element);

/**
������� ������� �� ������ �����
\param stack ��������� �� ����
\return int value �������� ���������� ��������
*/
int PopStack(Stack* stack);

/**
��������, ������ �� ����
\param Stack* stack ��������� �� ����
*/
bool IsEmptyStack(Stack* stack);

/**
������� ����
\param stack ��������� �� ����
*/
Stack* DeleteStack(Stack* stack);