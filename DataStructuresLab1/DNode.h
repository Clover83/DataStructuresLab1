#pragma once
#include <iostream>
#include <string>
class DNode
{
public:
	int value;
	DNode* next;
	DNode* prev;

	DNode();
	DNode(int value);

	void printList();

	DNode* pushBack(int newValue);
	DNode* walk(int steps);

	static DNode* getRandomList(int size);
	static DNode* getSortedList(int size);
	static DNode* getReverseSortedList(int size);
	static DNode* arrToList(int* arr, int size);
};

