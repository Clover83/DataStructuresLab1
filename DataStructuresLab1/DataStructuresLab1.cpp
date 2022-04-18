#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



// Singly linked node class
class SNode {
public:
    int value;
    SNode* next;

    SNode() {
        value = 0;
        next = nullptr;
    }

    SNode(int value) {
        this->value = value;
        next = nullptr;
    }

    void printList() {
        SNode* n = this;
        while (n != nullptr) {
            cout << n->value << endl;
            n = n->next;
            if (n == this) {
                cout << "Circular list detected! Stopping print\n";
                return;
            }
        }
    }

    SNode* pushBack(int newValue) {
        SNode* newNode = new SNode(newValue);
        newNode->next = this;
        return newNode;
    }

    // (Static) List generators

    static SNode* getRandomList(int size) {
        // time(0) returns current time, resolution in seconds
        unsigned int seed = time(0);
        cout << "Using seed: " << to_string(seed) << endl;
        srand(seed);
        //srand(10928);
        SNode* singlyHead = new SNode(rand() % size);
        // Start from one since one node is already created above
        for (int i = 1; i < size; i++) {
            singlyHead = singlyHead->pushBack(rand() % size);
        }
        return singlyHead;
    }

    static SNode* getSortedList(int size) {
        SNode* singlyHead = new SNode(size-1);
        // Start from s-2 since one node is already created above
        for (int i = size - 2; i >= 0; i--) {
            singlyHead = singlyHead->pushBack(i);
        }
        return singlyHead;
    }

    static SNode* getReverseSortedList(int size) {
        SNode* singlyHead = new SNode(0);
        // Start from one since one node is already created above
        for (int i = 1; i < size; i++) {
            singlyHead = singlyHead->pushBack(i);
        }
        return singlyHead;
    }
};

SNode* singleBSort(SNode* singlyHead) {
    int sortedLength = 0;
    SNode* firstUnsorted = singlyHead->next;
    SNode* newHead = singlyHead;
    newHead->next = nullptr;

    // First loop
    while (firstUnsorted != nullptr) {
        // Move P and unlink
        SNode* unsorted = firstUnsorted;
        firstUnsorted = unsorted->next;
        unsorted->next = nullptr;
        // Set bounds and increment sorted size
        sortedLength++;
        int lowerBound = 0, upperBound = sortedLength;

        // Binary search start
        int toWalk = 0;
        int middle;

        SNode* middleNode = newHead;
        while (true) {
            middle = (lowerBound + upperBound) / 2;
            cout << to_string(middle) << " ";
            // Compare with middle
            // Right
            if (unsorted->value > middleNode->value) {
                lowerBound = middle;

                // Insert right of middle
                if (upperBound - lowerBound <= 1) {
                    SNode* next = middleNode->next;
                    middleNode->next = unsorted;
                    unsorted->next = next;
                    break;
                }

                // Middle walk from middle (the trick)
                int oldMiddle = middle;
                middle = (lowerBound + upperBound) / 2;
                for (int i = oldMiddle; i < middle; i++) {
                    if (middleNode->next != nullptr) {
                        middleNode = middleNode->next;
                    }
                    else break;
                }
            }
            // Left
            else if (unsorted->value < middleNode->value) {
                upperBound = middle;

                // Insert left of middle
                if (upperBound - lowerBound <= 1) {
                    SNode* prev = nullptr;
                    // Get node left of middle
                    if (newHead != middleNode) {
                        prev = newHead;
                        for (int i = 1; i < middle - 1; i++) {
                            if (prev->next != nullptr) {
                                prev = prev->next;
                            }
                            else break;
                        }
                    }
                    else {
                        newHead = unsorted;
                    }
                    // Insert
                    unsorted->next = middleNode;
                    if (prev != nullptr) {
                        prev->next = unsorted;
                    }
                    break;
                }

                // Middle walk from head
                middleNode = newHead;
                for (int i = 1; i < middle; i++) {
                    if (middleNode->next != nullptr) {
                        middleNode = middleNode->next;
                    }
                    else break;
                }
            }
            // Equal
            else {
                // Insert right of middle
                SNode* next = middleNode->next;
                middleNode->next = unsorted;
                unsorted->next = next;
                break;
            }

        }
        // Binary search end, sorting next
        cout << "--------------" << endl;
        newHead->printList();
    }
    return newHead;
}
// Doubly linked node class
class DNode {
public:
    int value;
    DNode* next;
    DNode* prev;

    DNode() {
        value = 0;
        next = nullptr;
        prev = nullptr;
    }

    DNode(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }

    void printList() {
        DNode* n = this;
        while (n != nullptr) {
            cout << n->value << endl;
            n = n->next;
            if (n == this) {
                cout << "Circular list detected! Stopping print\n";
                return;
            }
        }
    }

    DNode* pushBack(int newValue) {
        DNode* newNode = new DNode(newValue);
        newNode->next = this;
        this->prev = newNode;
        return newNode;
    }

    // (Static) List generators

    static DNode* getRandomList(int size) {
        // time(0) returns current time, resolution in seconds
        srand(time(0));
        DNode* doublyHead = new DNode(rand() % size);
        // Start from one since one node is already created above
        for (int i = 1; i < size; i++) {
            doublyHead = doublyHead->pushBack(rand() % size);
        }
        return doublyHead;
    }

    static DNode* getSortedList(int size) {
        DNode* doublyHead = new DNode(size - 1);
        // Start from s-2 since one node is already created above
        for (int i = size - 2; i >= 0; i--) {
            doublyHead = doublyHead->pushBack(i);
        }
        return doublyHead;
    }

    static DNode* getReverseSortedList(int size) {
        DNode* doublyHead = new DNode(0);
        // Start from one since one node is already created above
        for (int i = 1; i < size; i++) {
            doublyHead = doublyHead->pushBack(i);
        }
        return doublyHead;
    }
};





int main() {
    SNode* singlyHead = SNode::getRandomList(6);
    singlyHead->printList();
    cout << "--------------" << endl;
    singlyHead = singleBSort(singlyHead);
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
