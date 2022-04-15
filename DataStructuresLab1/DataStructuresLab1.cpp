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
	int lowerBound = 0;
	int upperBound = 0;
	int sortedLength = 0;
	int toWalk = 0; // prob dont need
	SNode* newHead = singlyHead;
	while (singlyHead->Next != nullptr) {
		if (sortedLength == 0) {
			sortedLength++;
		}
		else {

			SNode* middleNode = newHead;
			int newUnsortedValue = singlyHead->Next->Value;
			//compare it with middle value index
			//middle should be floor(upper-lower)/2 etc.
			int middle = (floor(sortedLength) / 2);
			//get middle value
			for (size_t i = 0; i < middle; i++) // might need to do a seperate function that gets called
			{
				if (middle == 0)
					middle = middleNode->Value;
				else
					middleNode = middleNode->Next;
			}
			if (middleNode->Value == newUnsortedValue) {
				//equal insert next to
			}
			if (middleNode->Value > newUnsortedValue) {
				//to the left
				cout << "to left" << endl;
				//upperBound = middle;
			}
			if (middleNode->Value < newUnsortedValue) {
				//to the right
				cout << "to right" << endl;
				//lowerBound = middle;
			}

			//test
			cout << middleNode->Value << endl;
			cout << newUnsortedValue << endl;

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
}
