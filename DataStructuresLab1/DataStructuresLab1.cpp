// DataStructuresLab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node {
public:
	int Value;
	Node* Next;
};

void printList(Node* n) {
	while (n != nullptr) {
		cout << n->Value << endl;
		n = n->Next;
	}
}

void insertAtTheHead(Node** head, int newValue) {
	//create a new node
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->Next = *head;
	*head = newNode;
}


int main()
{
    //cout << "Hello World!\n";
	//Run independant random
	srand(time(0));
	Node* head = new Node();
	head->Value = rand();
	int numberOfNodes = 10000;
	for (size_t i = 0; i < numberOfNodes; i++)
	{
		int bob = rand();
		insertAtTheHead(&head, bob);
	}
	printList(head);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error Lists window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
