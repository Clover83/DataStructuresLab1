#include <iostream>
#include <string>
#include <chrono>

#include "SNode.h"
#include "DNode.h"
#include "BSortAlgs.h"
#include "Tests.h"
#include "DataHandler.h"


using namespace std::chrono;

void exportSingleBSort(std::string name, int size, int resolution) {
    int increment = size / resolution;

    DataHandler dh(name);

    for (int i = increment; i < size; i += increment) {
        int completeness = 100 * i / size;
        std::cout << std::to_string(completeness) << "%" << std::endl;
        SNode* randomList = SNode::getRandomList(i);
        auto start = high_resolution_clock::now();
        BSortAlgs::singleBSort(randomList);
        auto stop = high_resolution_clock::now();
        // (one of many) memory leaks
        auto duration = duration_cast<microseconds>(stop - start);
        dh.push(i, duration.count());
    }
    dh.write();
}

int main() {
    //exportSingleBSort("random", 4800, 100);
    //Tests::doubleBSortCanSort(1000000);

    int* arr = new int[] {0, 1, 3, 3, 4, 6, 5, 7, 7, 9};
    DNode* doublyHead = DNode::arrToList(arr, 10);
    //Random list of n elements
    //DNode* doublyHead = DNode::getRandomList(10);
    //Print the list 
    doublyHead->printList();
    doublyHead = BSortAlgs::doubleBSort(doublyHead);
    std::cout << "--------------" << std::endl;
    doublyHead->printList();
}