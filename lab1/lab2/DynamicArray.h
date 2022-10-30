#pragma once

//TODO: xml -> doxygen
/// <summary>
/// Структура динамического массива
/// </summary>
struct DynamicArray
{
	//TODO: rsdn 
	int Length = 0;
	const int ConstCapacity = 8;
	int Capacity = ConstCapacity;
	int* Array = new int[Length + Capacity];
};

bool CheckIndexOutRange(DynamicArray* array, int index);
void IncreaseDynamicArray(DynamicArray* array);
void DecreaseDynamicArray(DynamicArray* array);