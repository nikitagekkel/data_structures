#include "ArrayActions.h"
#include <iostream>

using namespace std;

//TODO: ������ � ���������
//int capacity = 8;

/// <summary>
/// ��������� ������������� ������������� �������
/// </summary>
/// <param name="array">������������ ������</param>
void InitializeDynamicArray(DynamicArray* array)
{
	array->Capacity = array->capacity;
	array->Length = 0;
	array->Array = new int[array->Length + array->capacity];
}

/// <summary>
/// ��������� ����� ������������� ������� � �������
/// </summary>
/// <param name="array">������������ ������</param>
void PrintArray(DynamicArray* array)
{
	cout << "\nArray: ";

	for (int i = 0; i < array->Length; i++)
	{
		cout << "[" << i << "]" << array->Array[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// ��������� ����� ������ � ���������� ������� � �������
/// </summary>
void PrintIndexOutOfRange()
{
	cout << "\nThe index is a negative number,";
	cout << " or it goes beyond the borders of the array"<< endl;
	cout << "\n";
}

/// <summary>
/// ��������� �������� �� ���������� �������
/// </summary>
/// <param name="array">������������ ������</param>
/// <param name="index">������</param>
/// <returns></returns>
bool CheckIndexOutRange(DynamicArray* array, int index)
{
	return index < 0 || index > array->Length - 1;
}

/// <summary>
/// ��������� ���������� ������ ������������� �������,
/// ��� ���������� ��� �������
/// </summary>
/// <param name="array">������������ ������</param>
void ResizeDynamicArray(DynamicArray* array)
{
	if (array->Length >= array->Capacity)
	{
		//TODO: growth factor
		//TODO: ���������� ������� ������������� �������
		array->Capacity += array->capacity;

		int* tempArray = new int[array->Capacity + 4];

		for (int i = 0; i < array->Length; i++)
		{
			tempArray[i] = array->Array[i];
		}

		delete[] array->Array;
		array->Array = tempArray;
	}
}

void PrintIndexOfElement(int index, int element)
{
	if (index >= 0)
	{
		cout << "\nIndex of " << element << " is: " << index << endl;
	}
	else
	{
		cout << "\nElement not found" << endl;
	}
}