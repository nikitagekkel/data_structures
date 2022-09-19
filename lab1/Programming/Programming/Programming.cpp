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
	int arr[arraySize]{};
	for (int i = 0; i < arraySize; i++)
	{
		arr[i] = rand()%100;
	}

	cout << "Source array is:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = i + 1; j < arraySize; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}

	cout << "Sorted array is:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void ArraysSecondTask()
{
	const int arraySize = 12;
	int count = 0;
	float arr[arraySize] = { 94.8F, 98.3F, 3.1F, 2.2F, 67.9F, 62.5F,
		50.4F, 12.7F, 55.6F, 3.3F, 53.1F, 63.4F };
	cout << "Source array is:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl << "Enter searching value: ";
	float searchingValue = 0;
	cin >> searchingValue;
	for (int i = 0; i < arraySize; i++)
	{
		if (arr[i] > float(searchingValue))
		{
			count += 1;
		}
	}
	cout << "Elements of array more than " << searchingValue << " is: " << count << endl;
}

void ArraysThirdTask()
{
	const int arraySize = 8;
	char arr[arraySize]{};
	string properChars;
	char c;
	cout << "Enter array of 8 chars" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> c;
		arr[i] = c;
	}

	cout << "Your array is:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < arraySize; i++)
	{
		if (isalpha(arr[i]))
		{
			properChars = properChars + arr[i] + " ";
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

void FirstFoo(double a)
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
	FirstFoo(a);
	cout << endl;
	cout << "Value of a in main(): " << a << endl;
}

void SecondFoo(double& a)
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
	SecondFoo(a);
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

void ThirdFoo(double* a)
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
	ThirdFoo(pointer);
	cout << endl;
	cout << "Value of a in main(): " << value << endl;
}

void DynamicMemoryFirstTask()
{
	int size = 3;
	double* arr = new double[size] {1.0,15.0,-8.2};
	cout << "Array of double:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
}

void DynamicMemorySecondTask()
{
	int size = 3;
	bool* arr = new bool[size] {true, false, true};

	cout << "Array of bool:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << boolalpha << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
}

void DynamicMemoryThirdTask()
{
	int n = 0;
	cout << "Enter char array size: ";
	cin >> n;
	if (n > 0)
	{
		char* arr = new char[n];
		for (int i = 0; i < n; i++)
		{
			cout << "Enter a[" << i << "]: ";
			cin >> arr[i];
		}
		cout << endl;
		cout << "Your char array is: ";
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		delete[] arr;
	}
	else
	{
		cout << "Array size must be larger than 0" << endl;
	}
}

void DynamicMemoryFourthTask()
{
	int size = 10;
	double* arr = new double[size] {1.0, 15.0, -8.2, -3.5, 12.6, 38.4,
		-0.5, 4.5, 16.7, 4.5};
	cout << "Array of double:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}

	cout << "Sorted array of double:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
}

void DynamicMemoryFifthTask()
{
	int index = -1;
	int searchingValue;
	int size = 10;
	int* arr = new int[size] {1, 15, -8, -3, 12, 38, 0, 4, 16, 4};
	cout << "Int array:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << endl << "Enter searching value: ";
	cin >> searchingValue;
	for (int i = 0; i < size; i++)
	{
		index += 1;
		if (searchingValue == arr[i])
		{
			break;
		}
	}
	cout << "Index of searching value " << searchingValue << " is: " << index << endl;
	delete[] arr;
}

void DynamicMemorySixthTask()
{
	string properChars;
	int size = 15;
	char* arr = new char[size] {'a', '1', '4', 'x', 'z', 'v', '0', 'b', 'j', '8', 'g',
		'k', '3', 'y', 's'};
	cout << "Char array is: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		if (isalpha(arr[i]))
		{
			properChars = properChars + arr[i] + " ";
		}
	}
	cout << "All letter in your array:" << endl << properChars << endl;
	delete[] arr;
}

int* MakeRandomArray(int arraySize)
{
	int size = arraySize;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
	return arr;
}

void DynamicMemorySeventhTask()
{
	int* arr1 = MakeRandomArray(5);
	cout << "Random array of 5: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl << endl;

	int* arr2 = MakeRandomArray(8);
	cout << "Random array of 8: " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl << endl;

	cout << "Random array of 13: " << endl;
	int* arr3 = MakeRandomArray(13);
	for (int i = 0; i < 13; i++)
	{
		cout << arr3[i] << " ";
	}
	cout << endl << endl;
	
	delete[] arr1, arr2, arr3;
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
	int count;

	count = 15;
	int* firstValues = ReadArray(count);
	cout << "Count is: " << CountPositiveValues(firstValues, count) << endl;
	delete[] firstValues;

	count = 20;
	int* secondValues = ReadArray(count);
	cout << "Count is: " << CountPositiveValues(secondValues, count) << endl;

	delete[] secondValues;
}

void PrintMenu()
{
	system("cls");
	cout << "Select the task number:" << endl;
	cout << "1. Task 1.1.1.1" << endl;
	cout << "2. Task 1.1.1.2" << endl;
	cout << "3. Task 1.1.2.1" << endl;
	cout << "4. Task 1.1.2.2" << endl;
	cout << "5. Task 1.1.2.3" << endl;
	cout << "6. Task 1.1.3.3" << endl;
	cout << "7. Task 1.1.3.4" << endl;
	cout << "8. Task 1.1.4.1" << endl;
	cout << "9. Task 1.1.4.2" << endl;
	cout << "10. Task 1.1.4.3" << endl;
	cout << "11. Task 1.1.4.4" << endl;
	cout << "12. Task 1.1.4.5" << endl;
	cout << "13. Task 1.1.4.6" << endl;
	cout << "14. Task 1.1.4.8" << endl;
	cout << "15. Task 1.1.5.1" << endl;
	cout << "16. Task 1.1.5.2" << endl;
	cout << "17. Task 1.1.5.3" << endl;
	cout << "18. Task 1.1.5.4" << endl;
	cout << "19. Task 1.1.5.5" << endl;
	cout << "20. Task 1.1.5.6" << endl;
	cout << "21. Task 1.1.5.7" << endl;
	cout << "22. Task 1.1.5.8" << endl;
	cout << endl;
}

int GetVariant()
{
	int variant = 0;
	cin >> variant;
	return variant;
}

void ReturnToMenu(void(*menu)())
{
	cout << "1. Return to menu" << endl;
	int newVariant = GetVariant();
	if (newVariant == 1)
	{
		menu();
	}
	else
	{
		cout << "You selected the incorrect number, please select it again" << endl;
		system("Pause");
		ReturnToMenu(*menu);
	}
}

void Menu()
{
	PrintMenu();
	int variant = GetVariant();
	if (variant >= 1 && variant <= 22)
	{
		switch (variant)
		{
		case 1:
		{
			system("cls");
			BreakpointsFirstTask();
			ReturnToMenu(Menu);
		}
		case 2:
		{
			system("cls");
			BreakpointsSecondTask();
			ReturnToMenu(Menu);
		}
		case 3:
		{
			system("cls");
			ArraysFirstTask();
			ReturnToMenu(Menu);
		}
		case 4:
		{
			system("cls");
			ArraysSecondTask();
			ReturnToMenu(Menu);
		}
		case 5:
		{
			system("cls");
			ArraysThirdTask();
			ReturnToMenu(Menu);
		}
		case 6:
		{
			system("cls");
			FunctionsFirstTask();
			ReturnToMenu(Menu);
		}
		case 7:
		{
			system("cls");
			FunctionsSecondTask();
			ReturnToMenu(Menu);
		}
		case 8:
		{
			system("cls");
			AdressesFirstTask();
			ReturnToMenu(Menu);
		}
		case 9:
		{
			system("cls");
			AdressesSecondTask();
			ReturnToMenu(Menu);
		}
		case 10:
		{
			system("cls");
			AdressesThirdTask();
			ReturnToMenu(Menu);
		}
		case 11:
		{
			system("cls");
			AdressesFourthTask();
			ReturnToMenu(Menu);
		}
		case 12:
		{
			system("cls");
			AdressesFifthTask();
			ReturnToMenu(Menu);
		}
		case 13:
		{
			system("cls");
			AdressesSixthTask();
			ReturnToMenu(Menu);
		}
		case 14:
		{
			system("cls");
			AdressesSeventhTask();
			ReturnToMenu(Menu);
		}
		case 15:
		{
			system("cls");
			DynamicMemoryFirstTask();
			ReturnToMenu(Menu);
		}
		case 16:
		{
			system("cls");
			DynamicMemorySecondTask();
			ReturnToMenu(Menu);
		}
		case 17:
		{
			system("cls");
			DynamicMemoryThirdTask();
			ReturnToMenu(Menu);
		}
		case 18:
		{
			system("cls");
			DynamicMemoryFourthTask();
			ReturnToMenu(Menu);
		}
		case 19:
		{
			system("cls");
			DynamicMemoryFifthTask();
			ReturnToMenu(Menu);
		}
		case 20:
		{
			system("cls");
			DynamicMemorySixthTask();
			ReturnToMenu(Menu);
		}
		case 21:
		{
			system("cls");
			DynamicMemorySeventhTask();
			ReturnToMenu(Menu);
		}
		case 22:
		{
			system("cls");
			DynamicMemoryEighthTask();
			ReturnToMenu(Menu);
		}
		}
	}
	else
	{
		cout << "You selected the incorrect number, please select it again" << endl;
		system("Pause");
		Menu();
	}
}

int main()
{
	Menu();
}
