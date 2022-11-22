#pragma once
#include "DynamicArray.h"
//TODO: комментарии

/**
Функция, добавляюющая элемент в динамический массив
\param array Динамический массив
\param element Добавляемый элемент
*/
void AddElementToArray(DynamicArray* array, int element);

/**
Функция, удаляющая элемент из динамического массив
\param array Динамический массив
\param element Удаляемый элемент
*/
void RemoveElementAtIndex(DynamicArray* array, int index);

/**
Функция, добавляющая элемент в динамический массив
по индексу
\param array Динамический массив
\param element Добавляемый элемент
*/
void InsertElement(DynamicArray* array, int element, int index);

/**
Функция, сортирующая динамический массив по возрастанию
\param array Динамический массив
*/
void ArraySort(DynamicArray* array);

/**
Функция, реализующая линейный поиск в динамическом массиве
\param array Динамический массив
\param element Элемент, индекс которого нужно найти
\return Найденный индекс
*/
int LinearSearch(DynamicArray* array, int element);

/**
Функция, реализующая бинарный поиск в динамическом массиве
\param array Динамический массив
\param element Элемент, индекс которого нужно найти
\return Найденный индекс
*/
int BinarySearch(DynamicArray* array, int element);

/**
Функция, реализующая реинициализацию динамического массива
\param array Динамический массив
*/
void ReInitializeDynamicArray(DynamicArray* array);