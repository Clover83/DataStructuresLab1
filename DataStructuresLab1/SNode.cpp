#include "SNode.h"

SNode::SNode() {
	value = 0;
	next = nullptr;
}

SNode::SNode(int value) {
	this->value = value;
	next = nullptr;
}

void SNode::printList() {
    SNode* n = this;
    while (n != nullptr) {
        std::cout << n->value << std::endl;
        n = n->next;
        if (n == this) {
            std::cout << "Circular list detected! Stopping print\n";
            return;
        }
    }
}

SNode* SNode::pushBack(int newValue) {
    SNode* newNode = new SNode(newValue);
    newNode->next = this;
    return newNode;
}

SNode* SNode::walk(int steps) {
    SNode* current = this;
    for (int i = 0; i < steps; i++) {
        current = current->next;
        if (current == nullptr) {
            return nullptr;
        }
    }
    return current;
}

SNode* SNode::getRandomList(int size) {
    // time(0) returns current time, resolution in seconds
    unsigned int seed = time(0);
    //cout << "Using seed: " << to_string(seed) << endl;
    srand(seed);
    //srand(10928);
    SNode* singlyHead = new SNode(rand() % size);
    // Start from one since one node is already created above
    for (int i = 1; i < size; i++) {
        singlyHead = singlyHead->pushBack(rand() % size);
    }
    return singlyHead;
}
SNode* SNode::getSortedList(int size) {
    SNode* singlyHead = new SNode(size - 1);
    // Start from s-2 since one node is already created above
    for (int i = size - 2; i >= 0; i--) {
        singlyHead = singlyHead->pushBack(i);
    }
    return singlyHead;
}
SNode* SNode::getReverseSortedList(int size) {
    SNode* singlyHead = new SNode(0);
    // Start from one since one node is already created above
    for (int i = 1; i < size; i++) {
        singlyHead = singlyHead->pushBack(i);
    }
    return singlyHead;
}
SNode* SNode::arrToList(int* arr, int size) {
    SNode* head = new SNode(*arr);
    SNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new SNode(*(arr + i));
        current = current->next;
    }
    return head;
}