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
  // (Static) List generators

};

void singleBSort(SNode* head);

void printList(SNode* n) {
	while (n != nullptr) {
		cout << n->Value << endl;
		n = n->Next;
	}
}
void SinglyGenerator(SNode** head, int newValue) {
	//create a new node
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

  // (Static) List generators
};

void DoublyGenerator(DNode** head, int newValue) {
  DNode * newNode = new DNode();
  newNode->Prev = nullptr;
  newNode->Value = newValue;
  newNode->Next = *head;
  *head = newNode;
}

int main() {

  //Run indepentant random values
  srand(time(0));
  
  //Makes first node for singly linked
  SNode* singlyHead = new SNode();
  singlyHead->Value = rand();
  
  //Makes first node for doubly
  DNode* doublyHead = new DNode();
  doublyHead->Value = rand();

  //Number of Nodes
	int numberOfNodes = 10;
	

	for (size_t i = 0; i < numberOfNodes; i++)
	{
		int randomValue = i;
    //Uncomment when need to generate
    
		SinglyGenerator(&singlyHead, randomValue);

    
    //DoublyGenerator(&doublyHead,randomValue);
    
	} 
  printList(singlyHead);
  singleBSort(singlyHead);
}

void singleBSort(SNode* singlyHead) {
  int sortedLength = 0;
  //while loop that continues until next pointer != nullptr

  SNode* firstUnsorted = singlyHead->Next;
  SNode* newHead = singlyHead;
  
  // First loop
  while(firstUnsorted != nullptr) {
    // Move P and unlink
    SNode* unsorted = firstUnsorted;
    firstUnsorted = unsorted->Next;
    unsorted->Next = nullptr;
    // Set bounds and increment
    int lowerBound = 0, upperBound = sortedLength, toWalk = 0;
    sortedLength++;
    
    // Perform binary search
    int middle = floor((lowerBound+upperBound)/2);
    SNode* middleNode = newHead;
    while (true) {
      // Walk to get middle value
      for(int i = 0; i < middle; i++) {
        if(middleNode->Next != nullptr) {
          middleNode = middleNode->Next;  
        } 
        else break;
      }
      // calculate new middle bounds



      // at end
      if (upperBound - lowerBound > 1) {
        // insert
        break;
      }
    } 
  }
  
}

void doubleBSort(DNode* head) {

}


class Data {
private:
  vector<int> nValues;
  vector<float> times;
  string filename;

public:
  Data(string name) {
    filename = name + ".csv";
  }

  void push(int n, float time) {
    nValues.push_back(n);
    times.push_back(time);
  }

  void write() {
    ofstream fh;
    if (nValues.size() != times.size()) {
      cout << "Data.write: dict mismatch!" << endl;
    }

    fh.open(filename);
    fh << "n,time\n";
    for(int i = 0; i < nValues.size(); i++) {
      fh << to_string(nValues.at(i)) << "," << to_string(times.at(i)) << "\n";
    }
    fh.close();
    
  }
};
