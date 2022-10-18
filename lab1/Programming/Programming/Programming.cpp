#include <iostream>
#include "ArrayActions.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

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
	cout << "23. Exit" << endl;
	cout << endl;
}


int main()
{
	int variant;
	while (true)
	{
		PrintMenu();
		cin >> variant;
		switch (variant) {
		case 1:
		{
			system("cls");
			BreakpointsFirstTask();
			break;
		}
		case 2:
		{
			system("cls");
			BreakpointsSecondTask();
			break;
		}
		case 3:
		{
			system("cls");
			ArraysFirstTask();
			break;
		}
		case 4:
		{
			system("cls");
			ArraysSecondTask();
			break;
		}
		case 5:
		{
			system("cls");
			ArraysThirdTask();
			break;
		}
		case 6:
		{
			system("cls");
			FunctionsFirstTask();
			break;
		}
		case 7:
		{
			system("cls");
			FunctionsSecondTask();
			break;
		}
		case 8:
		{
			system("cls");
			AdressesFirstTask();
			break;
		}
		case 9:
		{
			system("cls");
			AdressesSecondTask();
			break;
		}
		case 10:
		{
			system("cls");
			AdressesThirdTask();
			break;
		}
		case 11:
		{
			system("cls");
			AdressesFourthTask();
			break;
		}
		case 12:
		{
			system("cls");
			AdressesFifthTask();
			break;
		}
		case 13:
		{
			system("cls");
			AdressesSixthTask();
			break;
		}
		case 14:
		{
			system("cls");
			AdressesSeventhTask();
			break;
		}
		case 15:
		{
			system("cls");
			DynamicMemoryFirstTask();
			break;
		}
		case 16:
		{
			system("cls");
			DynamicMemorySecondTask();
			break;
		}
		case 17:
		{
			system("cls");
			DynamicMemoryThirdTask();
			break;
		}
		case 18:
		{
			system("cls");
			DynamicMemoryFourthTask();
			break;
		}
		case 19:
		{
			system("cls");
			DynamicMemoryFifthTask();
			break;
		}
		case 20:
		{
			system("cls");
			DynamicMemorySixthTask();
			break;
		}
		case 21:
		{
			system("cls");
			DynamicMemorySeventhTask();
			break;
		}
		case 22:
		{
			system("cls");
			DynamicMemoryEighthTask();
			break;
		}
		case 23:
		{
			return -1;
			break;
		}
		default:
		{
			cout << "You selected the incorrect number, please select it again" << endl;
		}
		}
		system("pause");
	}
	_CrtDumpMemoryLeaks();
}