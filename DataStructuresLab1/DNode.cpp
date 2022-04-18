#include "DNode.h"


DNode::DNode() {
    value = 0;
    next = nullptr;
    prev = nullptr;
}
DNode::DNode(int value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
}

void DNode::printList() {
    DNode* n = this;
    while (n != nullptr) {
        std::cout << n->value << std::endl;
        n = n->next;
        if (n == this) {
            std::cout << "Circular list detected! Stopping print\n";
            return;
        }
    }
}

DNode* DNode::pushBack(int newValue) {
    DNode* newNode = new DNode(newValue);
    newNode->next = this;
    this->prev = newNode;
    return newNode;
}

//DNode* DNode::walk(int steps) {
//
//}

DNode* DNode::getRandomList(int size) {
    // time(0) returns current time, resolution in seconds
    srand(time(0));
    DNode* doublyHead = new DNode(rand() % size);
    // Start from one since one node is already created above
    for (int i = 1; i < size; i++) {
        doublyHead = doublyHead->pushBack(rand() % size);
    }
    return doublyHead;
}
DNode* DNode::getSortedList(int size) {
    DNode* doublyHead = new DNode(size - 1);
    // Start from s-2 since one node is already created above
    for (int i = size - 2; i >= 0; i--) {
        doublyHead = doublyHead->pushBack(i);
    }
    return doublyHead;
}
DNode* DNode::getReverseSortedList(int size) {
    DNode* doublyHead = new DNode(0);
    // Start from one since one node is already created above
    for (int i = 1; i < size; i++) {
        doublyHead = doublyHead->pushBack(i);
    }
    return doublyHead;
}
//DNode* DNode::arrToList(int* arr, int size) {
//
//}

//void DNode::testIsSorted(int nTests) {
//
//}