#pragma once
#include <iostream>
#include <string>

class SNode
{
public:
	int value;
	SNode* next;

	SNode();
	SNode(int value);

	void printList();

	SNode* pushBack(int newValue);
	SNode* walk(int steps);

	static SNode* getRandomList(int size);
	static SNode* getSortedList(int size);
	static SNode* getReverseSortedList(int size);
	static SNode* arrToList(int* arr, int size);
	
	static void testIsSorted(int nTests);


};

