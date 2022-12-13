#include "ArrayActions.h"
#include <iostream>

using namespace std;

bool CheckIndexOutRange(DynamicArray* array, int index)
{
	return index < 0 || index > array->Length - 1;
}

void CheckLengthDynamicArray(DynamicArray* array)
{
	if (array->Length >= array->Capacity ||
		array->Length == array->Capacity / array->GrowthFactor)
	{
		int* tempArray = new int[array->Length];
		for (int i = 0; i < array->Length; i++)
		{
			tempArray[i] = array->Array[i];
		}

		if (array->Length == array->Capacity)
		{
			array->Capacity = array->Capacity * array->GrowthFactor;
		}
		else if (array->Length == array->Capacity / array->GrowthFactor
			&& array->Capacity > array->ConstCapacity)
		{
			array->Capacity = array->Capacity / array->GrowthFactor;
		}

		delete[] array->Array;
		array->Array = new int[array->Capacity];
		for (int i = 0; i < array->Capacity; i++)
		{
			array->Array[i] = tempArray[i];
		}
		delete[] tempArray;
	}
}