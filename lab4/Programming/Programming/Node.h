#pragma once
#include <string>

using namespace std;

/**
’ранит данные об узле
*/
struct Node
{
	/**
	”казатель на следующий узел
	*/
	Node* Next = nullptr;

	/**
	«начение элемента в узле
	*/
	string Value = "";

	/**
	«начение ключа в узле
	*/
	string Key = "";
};