#include <iostream>
#include <cmath>
using namespace std;

void BreakpointsFirstTask()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sum += add * i;//0 1.1 3.52 7.513 13.3694 21.422 32.0513 45.6923 62.841 84.0626
		add *= 1.1;
	}
	cout << "Total sum is " << sum << endl;
}

void BreakpointsSecondTask()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 1000; i++)
	{
		sum += add * i; // Поставьте условную точку останова здесь // 3.2624579394327844
		if (i % 3 == 0)
		{
			add *= 1.1;
		}
		else
		{
			add /= 3.0;
		}
	}
	cout << "Total sum is " << sum << endl;
}

void ArraysFirstTask()
{
	const int arraySize = 10;
	int array[arraySize]{};
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % 100;
	}

	cout << "Source array is:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = i + 1; j < arraySize; j++)
		{
			if (array[i] > array[j])
			{
				swap(array[i], array[j]);
			}
		}
	}

	cout << "Sorted array is:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void ArraysSecondTask()
{
	const int arraySize = 12;
	int count = 0;
	float array[arraySize] = { 94.8F, 98.3F, 3.1F, 2.2F, 67.9F, 62.5F,
		50.4F, 12.7F, 55.6F, 3.3F, 53.1F, 63.4F };
	cout << "Source array is:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl << "Enter searching value: ";
	float searchingValue = 0;
	cin >> searchingValue;
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] > float(searchingValue))
		{
			count += 1;
		}
	}
	cout << "Elements of array more than " << searchingValue << " is: " << count << endl;
}

void ArraysThirdTask()
{
	const int arraySize = 8;
	char array[arraySize]{};
	string properChars;
	char c;
	cout << "Enter array of 8 chars" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> c;
		array[i] = c;
	}

	cout << "Your array is:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < arraySize; i++)
	{
		if (isalpha(array[i]))
		{
			properChars = properChars + array[i] + " ";
		}
	}
	cout << "All letter in your array:" << endl << properChars << endl;
}

double GetPower(double base, int exponent)
{
	double calculatedNumber = pow(base, exponent);
	return calculatedNumber;
}

void FunctionsFirstTask()
{
	double number = 0.0;
	int exponent = 0;
	int choice = 0;
	cout << "Input a number to exponent: " << endl;
	cin >> number;
	cout << "Input an exponent: " << endl;
	cin >> exponent;
	double result = GetPower(number, exponent);
	cout << "Result: " << number << " ^ " << exponent << " = " << result << endl;
	cout << "Do you want to do this operation again?" << endl << "1. Yes" << endl << "2. No" << endl;
	cin >> choice;
	if (choice == 1)
	{
		FunctionsFirstTask();
	}
	else
	{
		return;
	}
}

void RoundToTens(int& value)
{
	if (value % 10 < 5)
	{
		value = (value / 10) * 10;
	}
	else
	{
		value = value + (10 - (value % 10));
	}
}

void FunctionsSecondTask()
{
	int value;
	cout << "Enter a number to round: ";
	cin >> value;
	int oldValue = value;
	RoundToTens(value);
	cout << "For " << oldValue << " rounded value is " << value << endl;
}

void AdressesFirstTask()
{
	int a = 5;
	int b = 4;
	cout << "Address of a: " << &a << endl;
	cout << "Address of b: " << &b << endl;
	double c = 13.5;
	cout << "Address of c: " << &c << endl;
	bool d = true;
	cout << "Address of d: " << &d << endl;
}

void AdressesSecondTask()
{
	int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
	cout << "Size of int type: " << sizeof(int) << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Address of a[" << i << "]: " << &a[i] << endl;
	}
	cout << endl;
	cout << "Size of double type: " << sizeof(double) << endl;
	double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2
	};
	for (int i = 0; i < 10; i++)
	{
		cout << "Address of b[" << i << "]: " << &b[i] << endl;
	}
}

void AdressesThirdTask()
{
	int a = 5;
	int& b = a;
	cout << "Address of a: " << &a << endl;
	cout << "Address of b: " << &b << endl;
	cout << endl;
	b = 7;
	cout << "Value of a: " << a << endl;
}

void FooFirst(double a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;
	a = 15.0;
	cout << "New value of a in Foo(): " << a << endl;
}

void AdressesFourthTask()
{
	double a = 5.0;
	cout << "Address of a in main(): " << &a << endl;
	cout << "Value of a in main(): " << a << endl;
	cout << endl;
	FooFirst(a);
	cout << endl;
	cout << "Value of a in main(): " << a << endl;
}

void FooSecond(double& a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;
	a = 15.0;
	cout << "New value of a in Foo(): " << a << endl;
}

void AdressesFifthTask()
{
	double a = 5.0;
	cout << "Address of a in main(): " << &a << endl;
	cout << "Value of a in main(): " << a << endl;
	cout << endl;
	FooSecond(a);
	cout << endl;
	cout << "Value of a in main(): " << a << endl;
}

void AdressesSixthTask()
{
	int a = 5;
	int* pointer = &a;
	cout << "Address of a: " << &a << endl;
	cout << "Address in pointer: " << pointer << endl;
	cout << "Address of pointer: " << &pointer << endl;
	cout << endl;
	*pointer = 7;
	cout << "Value in a: " << a << endl;
	cout << "Value by pointer address: " << *pointer << endl;
}

void FooThird(double* a)
{
	cout << "Address in pointer: " << a << endl;
	cout << "Address of pointer: " << &a << endl;
	cout << "Value in pointer address: " << *a << endl;
	*a = 15.0;
	cout << "New value in pointer address: " << *a << endl;
}

void AdressesSeventhTask()
{
	double value = 5.0;
	double* pointer = &value;
	cout << "Address of value in main(): " << &value << endl;
	cout << "Address in pointer in main(): " << pointer << endl;
	cout << "Address of pointer in main(): " << &pointer << endl;
	cout << "Value of a in main(): " << value << endl;
	cout << endl;
	FooThird(pointer);
	cout << endl;
	cout << "Value of a in main(): " << value << endl;
}

void DynamicMemoryFirstTask()
{
	int size = 3;
	double* array = new double[size] {1.0, 15.0, -8.2};
	cout << "Array of double:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	delete[] array;
}

void DynamicMemorySecondTask()
{
	int size = 3;
	bool* array = new bool[size] {true, false, true};

	cout << "Array of bool:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << boolalpha << array[i] << " ";
	}
	cout << endl;
	delete[] array;
}

void DynamicMemoryThirdTask()
{
	int arraySize = 0;
	cout << "Enter char array size: ";
	cin >> arraySize;
	if (arraySize > 0)
	{
		char* array = new char[arraySize];
		for (int i = 0; i < arraySize; i++)
		{
			cout << "Enter a[" << i << "]: ";
			cin >> array[i];
		}
		cout << endl;
		cout << "Your char array is: ";
		for (int i = 0; i < arraySize; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
		delete[] array;
	}
	else
	{
		cout << "Array size must be larger than 0" << endl;
	}
}

void DynamicMemoryFourthTask()
{
	int arraySize = 10;
	double* array = new double[arraySize] {1.0, 15.0, -8.2, -3.5, 12.6, 38.4,
		-0.5, 4.5, 16.7, 4.5};
	cout << "Array of double:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = i + 1; j < arraySize; j++)
		{
			if (array[i] > array[j])
			{
				swap(array[i], array[j]);
			}
		}
	}

	cout << "Sorted array of double:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	delete[] array;
}

void DynamicMemoryFifthTask()
{
	int index = -1;
	int searchingValue;
	int arraySize = 10;
	int* array = new int[arraySize] {1, 15, -8, -3, 12, 38, 0, 4, 16, 4};
	cout << "Int array:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	cout << endl << "Enter searching value: ";
	cin >> searchingValue;
	for (int i = 0; i < arraySize; i++)
	{
		index += 1;
		if (searchingValue == array[i])
		{
			break;
		}
	}
	cout << "Index of searching value " << searchingValue << " is: " << index << endl;
	delete[] array;
}

void DynamicMemorySixthTask()
{
	string properChars;
	int arraySize = 15;
	char* array = new char[arraySize] {'a', '1', '4', 'x', 'z', 'v', '0', 'b', 'j', '8', 'g',
		'k', '3', 'y', 's'};
	cout << "Char array is: " << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < arraySize; i++)
	{
		if (isalpha(array[i]))
		{
			properChars = properChars + array[i] + " ";
		}
	}
	cout << "All letter in your array:" << endl << properChars << endl;
	delete[] array;
}

int* MakeRandomArray(int arraySize)
{
	int* array = new int[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % 100;
	}
	return array;
}

void DynamicMemorySeventhTask()
{
	int* firstArray = MakeRandomArray(5);
	cout << "Random array of 5: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << firstArray[i] << " ";
	}
	cout << endl << endl;

	int* secondArray = MakeRandomArray(8);
	cout << "Random array of 8: " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << secondArray[i] << " ";
	}
	cout << endl << endl;

	cout << "Random array of 13: " << endl;
	int* thirdArray = MakeRandomArray(13);
	for (int i = 0; i < 13; i++)
	{
		cout << thirdArray[i] << " ";
	}
	cout << endl << endl;

	delete[] firstArray, secondArray, thirdArray;
}

int* ReadArray(int count)
{
	int* values = new int[count];
	for (int i = 0; i < count; i++)
	{
		values[i] = rand() % 100;
	}
	return values;
}

int CountPositiveValues(int* values, int count)
{
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		if (values[i] > 0)
		{
			result++;
		}
	}
	return result;
}

void DynamicMemoryEighthTask()
{
	int count = 15;
	int* values = ReadArray(count);
	cout << "Count is: " << CountPositiveValues(values, count) << endl;
	delete[] values;

	count = 20;
	values = ReadArray(count);
	cout << "Count is: " << CountPositiveValues(values, count) << endl;

	delete[] values;
}