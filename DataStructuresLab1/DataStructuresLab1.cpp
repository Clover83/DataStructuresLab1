#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;
// Singly linked node class
class SNode {
public:
	int Value;
	SNode* Next;

};

void printList(SNode* n) {
	while (n != nullptr) {
		cout << n->Value << endl;
		n = n->Next;
	}
}
void SinglyGenerator(SNode** head, int newValue) {
	SNode* newNode = new SNode();
	newNode->Value = newValue;
	newNode->Next = *head;
	*head = newNode;
}

// Doubly linked node class
class DNode {
public:
	int Value;
	DNode* Next;
	DNode* Prev;
};




void bSort(SNode* singlyHead) {
	int sortedLength = 0;
	int upperBound = 0;
	int toWalk = 0; // prob dont need
	SNode* newHead = singlyHead;
	while (singlyHead->Next != nullptr) {
		if (sortedLength == 0) {
			sortedLength++;
		}
		else {
		
			SNode* middleNode = newHead;
			SNode* unsorted = singlyHead->Next;
			int newUnsortedValue = unsorted->Value;
			//
			//veikia..? binary atlieka
			upperBound = sortedLength;
			int lowerBound = 0;
			while ((upperBound - lowerBound) != 0) {
				int middle = (floor(upperBound-lowerBound)/ 2);

				for (size_t i = 0; i < middle; i++)
				{
					if (middle == 0)
						middle = middleNode->Value;
					else
						if(middleNode->Next != nullptr)
							middleNode = middleNode->Next;
						break;
				}
				if (middleNode->Value == newUnsortedValue) {
					break;
				}
				if (middleNode->Value > newUnsortedValue) {
					//to the left
					cout << "to left" << endl;
					upperBound = middle;
				}
				if (middleNode->Value < newUnsortedValue) {
					//to the right
					cout << "to right" << endl; //ceil
					lowerBound = (floor(upperBound - lowerBound) / 2)+1; //+1 maybe maybe not, ceil not doing as intended
					
				}
			}
		if (middleNode->Value > newUnsortedValue) {
			//SNode* temp = singlyHead->Next;



		}
		if (middleNode->Value < newUnsortedValue)
		{
			//nzn, kazka blogai darau cia
			
			cout << "entered";
			//sitas turbut ne
			/*SNode* temp = unsorted;
			unsorted->Next = middleNode->Next;
			middleNode->Next = unsorted;
			for (size_t i = 1; i < sortedLength; i++)
			{
				newHead->Next;
				cout << sortedLength;
			}
			newHead->Next = temp->Next;*/
			//SNode* unsorted = singlyHead;

			//nop
			/*singlyHead = singlyHead->Next->Next;
			unsorted->Next = middleNode->Next;
			middleNode->Next = unsorted->Next;*/


			//? irgi ne
			//SNode* temp = unsorted;
			//unsorted->Next = middleNode->Next;
			//middleNode->Next = unsorted;
			//newHead->Next->Next = temp->Next;
			
		}
		sortedLength++;
		singlyHead = singlyHead->Next;
		}
	}
}


int main() {

	//Run indepentant random values
	srand(time(0));

	//Makes first node for singly linked
	SNode* singlyHead = new SNode();
	singlyHead->Value = rand();
	//Makes first node for doubly
	//DNode* doublyHead = new DNode();
	//doublyHead->Value = 15;

	//Number of Nodes
	int numberOfNodes = 10;

	for (size_t i = 0; i < numberOfNodes; i++)
	{
		int randomValue = rand();
		//Uncomment when need to generate

		SinglyGenerator(&singlyHead, randomValue);

		//DoublyGenerator(&doublyHead,randomValue);

	}
	printList(singlyHead);
	bSort(singlyHead);
	cout << endl << "print after";
	printList(singlyHead);
}
