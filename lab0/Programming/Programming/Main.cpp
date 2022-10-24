#include <iostream>
#include "ArrayActions.h"

using namespace std;

void PrintMenu()
{
	system("cls");
	cout << "Select the task number:" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Breakpoints first task" << endl;
	cout << "2. Breakpoints second task" << endl;
	cout << "3. Arrays first task" << endl;
	cout << "4. Arrays second task" << endl;
	cout << "5. Arrays third task" << endl;
	cout << "6. Functions first task" << endl;
	cout << "7. Functions second task" << endl;
	cout << "8. Adresses first task" << endl;
	cout << "9. Adresses second task" << endl;
	cout << "10. Adresses third task" << endl;
	cout << "11. Adresses fourth task" << endl;
	cout << "12. Adresses fifth task" << endl;
	cout << "13. Adresses sixth task" << endl;
	cout << "14. Adresses seventh task" << endl;
	cout << "15. Dynamic memory first task" << endl;
	cout << "16. Dynamic memory second task" << endl;
	cout << "17. Dynamic memory third task" << endl;
	cout << "18. Dynamic memory fourth task" << endl;
	cout << "19. Dynamic memory fifth task" << endl;
	cout << "20. Dynamic memory sixth task" << endl;
	cout << "21. Dynamic memory seventh task" << endl;
	cout << "22. Dynamic memory eighth task" << endl;
	cout << endl;
}


int main()
{
	int variant;

	while (true)
	{
		PrintMenu();
		cout << "Enter nubmer of action: ";
		cin >> variant;
		switch (variant) {
		case 0:
		{
			return -1;
			break;
		}
		case 1:
		{
			BreakpointsFirstTask();
			break;
		}
		case 2:
		{;
			BreakpointsSecondTask();
			break;
		}
		case 3:
		{
			ArraysFirstTask();
			break;
		}
		case 4:
		{
			ArraysSecondTask();
			break;
		}
		case 5:
		{
			ArraysThirdTask();
			break;
		}
		case 6:
		{
			FunctionsFirstTask();
			break;
		}
		case 7:
		{
			FunctionsSecondTask();
			break;
		}
		case 8:
		{
			AdressesFirstTask();
			break;
		}
		case 9:
		{
			AdressesSecondTask();
			break;
		}
		case 10:
		{
			AdressesThirdTask();
			break;
		}
		case 11:
		{
			AdressesFourthTask();
			break;
		}
		case 12:
		{
			AdressesFifthTask();
			break;
		}
		case 13:
		{
			AdressesSixthTask();
			break;
		}
		case 14:
		{
			AdressesSeventhTask();
			break;
		}
		case 15:
		{
			DynamicMemoryFirstTask();
			break;
		}
		case 16:
		{
			DynamicMemorySecondTask();
			break;
		}
		case 17:
		{
			DynamicMemoryThirdTask();
			break;
		}
		case 18:
		{
			DynamicMemoryFourthTask();
			break;
		}
		case 19:
		{
			DynamicMemoryFifthTask();
			break;
		}
		case 20:
		{
			DynamicMemorySixthTask();
			break;
		}
		case 21:
		{
			DynamicMemorySeventhTask();
			break;
		}
		case 22:
		{
			DynamicMemoryEighthTask();
			break;
		}
		default:
		{
			cout << "You selected the incorrect number, please select it again" << endl;
		}
		}
		system("pause");
	}
}