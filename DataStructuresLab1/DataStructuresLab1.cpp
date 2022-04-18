#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

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

SNode* mid_node(SNode* start, SNode* last, int& middlepos) {
	if (start == NULL)
		return NULL;
	SNode* slow = start;//head
	SNode* fast = start->Next;//next88
	middlepos++;
	while (fast != last->Next and last->Next != nullptr) { //while not null
		fast = fast->Next; //take next 98
		if (fast != last->Next && last->Next != nullptr) { //if not null
			slow = slow->Next; //
			middlepos++;
			fast = fast->Next;
		}
	}
	if (last->Next == nullptr) {
		while (fast != last) {
			fast = fast->Next;
			if (fast != last) {
				slow = slow->Next;
				fast = fast->Next;
				middlepos++;
			}
		}
	}
	cout << endl;
	cout << endl;
	cout << "middle position " << middlepos;
	cout << endl;
	cout << endl;
	cout << "middle value" << slow->Value << endl;
	cout << endl;
	cout << endl;
	cout << "unsorted value" << last->Value;
	return slow;
}




void SinglyGenerator(SNode** head, int newValue) {
	SNode* newNode = new SNode();
	newNode->Value = newValue;
	newNode->Next = *head;
	*head = newNode;
}

int BinarySearch(SNode* head, SNode* temp, int value, int sortedlen) { //int value is the unsorted value
	SNode* last = temp;
	SNode* start = head;
	//int upperbound = sortedlen;
	//int lowerbound = 1;
	int bob = 0;
	do {
		int middlepos = 0;
		SNode* mid = mid_node(start, last, middlepos);
		int midvalue = middlepos;
		if (mid == NULL)
			return NULL;
		if (mid->Value == value) { //unsorted == mid
			break;
		}
		else if (mid->Value < value) {
			if (mid->Next->Value != value) {
				start = mid->Next;
				//lowerbound = middlepos;
			}// unsorted > mid
			else {
				bob = 1;
				mid->Value;
				break;

			}
		}
		else {
			last = mid;
			if (middlepos == 1) {
				bob = 2;
				if (temp->Next != nullptr) {

					for (size_t i = 1; i < sortedlen; i++)
					{
						head = head->Next; //get tail
					}
					head->Value;
				}

				//SNode* tailnext = temp->Next;
				//tailnext->Value = temp->Next->Value;
				//head->Next = tailnext; //tail go to temp next
				//SNode* midnext = mid->Next;

				//temp = mid->Next; //temp is midnext
				//temp->Next = mid;
				//mid->Next = midnext;
				//cout << endl;
				//printList(head);
				//SNode* temp = currY->next;
				//currY->next = currX->next;
				//currX->next = temp;
				break;
			}
		} //unsorted < mid
	} while (true);

	if (bob == 2) {
		cout << "left";

	}
	if (bob == 1) {

		//for (size_t i = 1; i < sortedlen; i++)
		//{
		//	head = head->Next;
		//}
		//head->Next = temp->Next;
		//temp->Next=
		cout << "right";

	}
	if (bob == 0) {
		cout << "same";

	}

}


void bSort(SNode* head) {


	SNode* temp = head;
	SNode* start = head;
	int sortedLenght = 0;
	if (sortedLenght == 0 && start->Next != nullptr) {
		sortedLenght++;
		temp = temp->Next;
	}
	while (temp != nullptr) {
		BinarySearch(head, temp, temp->Value, sortedLenght);

		//end
		temp = temp->Next;
		sortedLenght++;
	}



}




int main() {


	srand(time(0));

	//Makes first node for singly linked
	SNode* singlyHead = new SNode();
	singlyHead->Value = 10;


	//Number of Nodes
	int numberOfNodes = 10;

	for (size_t i = 0; i < numberOfNodes; i++)
	{
		int randomValue = rand();


		SinglyGenerator(&singlyHead, randomValue);

	}
	printList(singlyHead);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	bSort(singlyHead);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	printList(singlyHead);
	return 0;
}