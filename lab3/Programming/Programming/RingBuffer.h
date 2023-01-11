#pragma once

/**
������ ���������� � ������
*/
struct RingBuffer
{
	/**
	��������� ����� � ������
	*/
	int FreeMemory = 0;

	/**
	������� ����� � ������
	*/
	int UsedMemory = 0;

	/**
	�����.
	*/
	int* Buffer = nullptr;

	/**
	������ ������
	*/
	int Size = 0;

	/**
	������ � ������� ������������ ������
	*/
	int IndexInput = 0;

	/**
	������ �� �������� ������������ ������
	*/
	int IndexOutput = 0;

	/**
	������ ����� ������
	*/
	const int GrowthFactor = 2;
};

/**
�������������� ��������� �����
\param sizeBuffer ������ ������
\return RingBuffer* buffer ��������� �� �����
 */
RingBuffer* InitRingBuffer(int sizeBuffer);

/**
��������� ������� � ��������� �����
\param buffer ��������� �� �����
\param element �������� ������� ����� ��������
*/
void PushRingBuffer(RingBuffer* buffer, int element);

/**
������� ������� �� ���������� ������
\param buffer ��������� �� �����
\return int �������� ������� ���� �������
*/
int PopRingBuffer(RingBuffer* buffer);

/**
���������� ���������� � ��������� ����� � ��������� ������
\param buffer ��������� �� �����
\return int ��������� ����� � ������
 */
int FreeMemoryInfo(RingBuffer* buffer);

/**
���������� ���������� � ������� ����� � ��������� ������
\param buffer ��������� �� �����
\return int ������� ����� � ������
 */
int UsedMemoryInfo(RingBuffer* buffer);

/**
�������� ������ ���������� ������
\param buffer ��������� �� �����
 */
void ResizeRingBuffer(RingBuffer* buffer);

/**
������� ��������� ������
\return RingBuffer* nullptr ������� ���������
*/
RingBuffer* DeleteRingBuffer(RingBuffer* buffer);