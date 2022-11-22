#include "ArrayActions.h"
#include <iostream>

using namespace std;

bool CheckIndexOutRange(DynamicArray* array, int index)
{
	return index < 0 || index > array->Length - 1;
}

void CheckLengthDynamicArray(DynamicArray* array)
{
	//TODO: дублировани
	if (array->Length >= array->Capacity)
	{
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
	else if (array->Capacity - array->Length
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