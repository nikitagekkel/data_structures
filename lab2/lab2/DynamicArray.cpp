#include "ArrayActions.h"
#include <iostream>

using namespace std;

int capacity = 8;

void InitializeDynamicArray(DynamicArray* array)
{
	array->capacity = capacity;
	array->length = 0;
	array->array = new int[array->length + capacity];
}

void PrintArray(DynamicArray* array)
{
	cout << "\n";
	cout << "Array: ";

	for (int i = 0; i < array->length; i++)
	{
		cout << "[" << i << "]" << array->array[i] << " ";
	}
	cout << endl;
	cout << "\n";
}

bool CheckIndexOutRange(DynamicArray* array, int index)
{
	if (index < 0 || index > array->length - 1)
	{
		cout << "The index is a negative number, or it goes beyond the borders of the array"
			<< endl;
		return true;
	}
	else
	{
		return false;
	}
}

void ResizeDynamicArray(DynamicArray* array)
{
	if (array->length >= array->capacity)
	{
		array->capacity += capacity;

		int* tempArray = new int[array->capacity + 4];

		for (int i = 0; i < array->length; i++)
		{
			tempArray[i] = array->array[i];
		}

		delete[] array->array;
		array->array = tempArray;
	}
}