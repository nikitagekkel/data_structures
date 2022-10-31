#include "ArrayActions.h"
#include <iostream>

using namespace std;

//TODO: внести в структуру
//int capacity = 8;

bool CheckIndexOutRange(DynamicArray* array, int index)
{
	return index < 0 || index > array->Length - 1;
}

void IncreaseDynamicArray(DynamicArray* array)
{
	if (array->Length >= array->Capacity)
	{
		//TODO: growth factor
		//TODO: уменьшение размера динамического массива
		int* tempArray = new int[array->Length];
		for (int i = 0; i < array->Length; i++)
		{
			tempArray[i] = array->Array[i];
		}
		array->Capacity += array->ConstCapacity;
		delete[] array->Array;
		array->Array = new int[array->Capacity];
		for (int i = 0; i < array->Capacity; i++)
		{
			array->Array[i] = tempArray[i];
		}
		delete[] tempArray;
	}
}

void DecreaseDynamicArray(DynamicArray* array)
{
	if (array->Capacity - array->Length
		> array->ConstCapacity)
	{
		int* tempArray = new int[array->Length];
		for (int i = 0; i < array->Length; i++)
		{
			tempArray[i] = array->Array[i];
		}
		array->Capacity -= array->ConstCapacity;
		delete[] array->Array;
		array->Array = new int[array->Capacity];
		for (int i = 0; i < array->Capacity; i++)
		{
			array->Array[i] = tempArray[i];
		}
		delete[] tempArray;
	}
}