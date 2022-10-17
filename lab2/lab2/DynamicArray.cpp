#include "ArrayActions.h"
#include <iostream>

using namespace std;

void InitDynamicArray(DynamicArray* array)
{
	int capacity = 8;

	array->capacity = capacity;
	array->size = 0;
	array->array = new int[array->size + capacity];
}

void PrintArray(DynamicArray* array)
{
	cout << "\n";
	cout << "Array: ";

	for (int i = 0; i < array->size; i++)
	{
		cout << "[" << i << "]" << array->array[i] << " ";
	}
	cout << endl;
	cout << "\n";
}

bool CheckIndexOutRange(DynamicArray* array, int index)
{
	if (index < 0 || index > array->size - 1)
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
	int capacity = 8;
	array->capacity += capacity;

	int* tempArray = new int[array->capacity];

	for (int i = 0; i < array->size; i++)
	{
		tempArray[i] = array->array[i];
	}

	delete[] array->array;
	array->array = tempArray;
}