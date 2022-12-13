#pragma once

/**
Структура Динамический массив
*/
struct DynamicArray
{
	//TODO: RSDN
	/**
	Гроу-фактор динамического массива
	*/
	const int GrowthFactor = 2;
	
	/**
	Первично заданный буфер динамического массива
	*/
	const int ConstCapacity = 8;

	/**
	Длина динамического массива
	*/
	int Length = 0;

	/**
	Буфер динамического массива 
	*/
	int Capacity = ConstCapacity;

	/**
	Динамический массив
	*/
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