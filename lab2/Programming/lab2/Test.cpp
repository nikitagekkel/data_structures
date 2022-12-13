#include <iostream>
#include "List.h"
#include <chrono>
#include <iomanip>

using namespace std;

void InsertTimeTest()
{
	List* list = new List;
	clock_t c_start = clock();

	for (int step = 0; step < 1010000; step +=10000)
	{
		auto t_start = chrono::high_resolution_clock::now();
		AddItemToList(list, (rand() % 9));
		clock_t c_end = clock();
		auto t_end = chrono::high_resolution_clock::now();

		cout << "For " << step;
		cout << fixed << setprecision(2) << " CPU time used: "
			<< 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";
	}
	delete list;
}

void DeletionTimeTest()
{
	List* list = new List;
	clock_t c_start = std::clock();

	for (int step = 0; step < 100; step ++)
	{
		AddItemToList(list, (rand() % 9));
	}

	for (int step = 0; step < 100; step++)
	{
		auto t_start = chrono::high_resolution_clock::now();
		RemoveItemFromList(list, step);
		clock_t c_end = clock();
		auto t_end = chrono::high_resolution_clock::now();

		cout << "For " << step;
		cout << fixed << setprecision(2) << " CPU time used: "
			<< 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";
	}
	delete list;
}