#pragma once

//TODO: комментарии0
struct DynamicArray
{
	int Length = 0;
	const int ConstCapacity = 8;
	int Capacity = ConstCapacity;
	int* Array = new int[Length + Capacity];
};

/**
Проверяет, выходит ли принимаемый индекс
за границы динамического массива
\param array Динамический массив
\param index Принимаемый индекс
\return Булевое значение да или нет
*/
bool CheckIndexOutRange(DynamicArray* array, int index);

/**
Увеличивает или уменьшает размер динамического массива,
при приближении его размера к буферу
\param array Динамический массив
*/
void CheckLengthDynamicArray(DynamicArray* array);