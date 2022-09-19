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
		array[i] = rand()%100;
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
	string properC;
	char c;
	cout << "Input array of 8 chars" << endl;
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
			properC = properC + array[i] + " ";
		}
	}
	cout << "All letter in your array:" << endl << properC << endl;
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
	cout << "Input a number to round: ";
	cin >> value;
	int oldValue = value;
	RoundToTens(value);
	cout << "For " << oldValue << " rounded value is " << value << endl;
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
}

int GetVariant()
{
	int variant;
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
		ReturnToMenu((*menu));
	}
}

void Menu()
{
	PrintMenu();
	int variant = GetVariant();
	if (variant >= 1 && variant <= 7)
	{
		switch (variant)
		{
		case 1:
		{
			BreakpointsFirstTask();
			ReturnToMenu(Menu);
		}
		case 2:
		{
			BreakpointsSecondTask();
			ReturnToMenu(Menu);
		}
		case 3:
		{
			ArraysFirstTask();
			ReturnToMenu(Menu);
		}
		case 4:
		{
			ArraysSecondTask();
			ReturnToMenu(Menu);
		}
		case 5:
		{
			ArraysThirdTask();
			ReturnToMenu(Menu);
		}
		case 6:
		{
			FunctionsFirstTask();
			ReturnToMenu(Menu);
		}
		case 7:
		{
			FunctionsSecondTask();
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
