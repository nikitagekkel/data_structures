#pragma once
#include <string>

using namespace std;

/**
������ ������ �� ����
*/
struct Node
{
	/**
	��������� �� ��������� ����
	*/
	Node* Next = nullptr;

	/**
	�������� �������� � ����
	*/
	string Value = "";

	/**
	�������� ����� � ����
	*/
	string Key = "";
};