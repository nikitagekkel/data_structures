#pragma once

/**
Хранит информацию о буфере
*/
struct RingBuffer
{
	/**
	Свободное место в буфере
	*/
	int FreeMemory = 0;

	/**
	Занятое место в буфере
	*/
	int UsedMemory = 0;

	/**
	Буфер.
	*/
	int* Buffer = nullptr;

	/**
	Размер буфера
	*/
	int Size = 0;

	/**
	Индекс в который производится запись
	*/
	int IndexInput = 0;

	/**
	Индекс из которого производится чтение
	*/
	int IndexOutput = 0;

	/**
	Фактор роста буфера
	*/
	const int GrowthFactor = 2;
};

/**
Инициализирует кольцевой буфер
\param sizeBuffer Размер буфера
\return RingBuffer* buffer Указатель на буфер
 */
RingBuffer* InitRingBuffer(int sizeBuffer);

/**
Добавляет элемент в кольцевой буфер
\param buffer Указатель на буфер
\param element Значение которое нужно добавить
*/
void PushRingBuffer(RingBuffer* buffer, int element);

/**
Удаляет элемент из кольцевого буфера
\param buffer Указатель на буфер
\return int Значение которое было удалено
*/
int PopRingBuffer(RingBuffer* buffer);

/**
Возвращает информацию о свободном месте в кольцевом буфере
\param buffer Указатель на буфер
\return int Свободное место в буфере
 */
int FreeMemoryInfo(RingBuffer* buffer);

/**
Возвращает информацию о занятом месте в кольцевом буфере
\param buffer Указатель на буфер
\return int Занятое место в буфере
 */
int UsedMemoryInfo(RingBuffer* buffer);

/**
Изменяет размер кольцевого буфера
\param buffer Указатель на буфер
 */
void ResizeRingBuffer(RingBuffer* buffer);

/**
Удаляет кольцевой буффер
\return RingBuffer* nullptr нулевой указатель
*/
RingBuffer* DeleteRingBuffer(RingBuffer* buffer);