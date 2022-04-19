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
        SNode* randomList = SNode::getReverseSortedList(i);
        auto start = high_resolution_clock::now();
        BSortAlgs::singleBSort(randomList);
        auto stop = high_resolution_clock::now();
        // (one of many) memory leaks
        auto duration = duration_cast<microseconds>(stop - start);
        dh.push(i, duration.count());
    }
    dh.write();
}

void exportDoubleBSort(std::string name, int size, int resolution) {
    int increment = size / resolution;

    DataHandler dh(name);

    for (int i = increment; i < size; i += increment) {
        int completeness = 100 * i / size;
        std::cout << std::to_string(completeness) << "%" << std::endl;
        DNode* randomList = DNode::getRandomList(i);
        auto start = high_resolution_clock::now();
        BSortAlgs::doubleBSort(randomList);
        auto stop = high_resolution_clock::now();
        // (one of many) memory leaks
        auto duration = duration_cast<microseconds>(stop - start);
        dh.push(i, duration.count());
    }
    dh.write();
}


int main() {
    //exportSingleBSort("singleReversed", 10000, 100);
    exportDoubleBSort("bigDoubly", 100000, 5);
    //Tests::doubleBSortCanSort(1000000);
    //Tests::singleBSortCanSort(100000);

    //int* arr = new int[] {3, 7, 0, 4, 10, 2, 1, 1, 11, 4, 4, 7};
    //int* arr = new int[] {0, 4, 3, 5, 1, 1};
    //DNode* doublyHead = DNode::arrToList(arr, 6);
    // Random list:
    //DNode* doublyHead = DNode::getRandomList(12);

    //for (int i = 0; i < 100000; i++) {
    //    DNode* doublyHead = DNode::getRandomList(12);
    //    //Print the list 
    //    std::cout << "-------------- U:" << std::endl;
    //    doublyHead->printList();
    //    doublyHead = BSortAlgs::doubleBSort(doublyHead);
    //    std::cout << "-------------- S:" << std::endl;
    //    doublyHead->printList();
    //}

    
    // Print the list 
    //std::cout << "-------------- U:" << std::endl;
    //doublyHead->printList();
    //doublyHead = BSortAlgs::doubleBSort(doublyHead);
    //std::cout << "-------------- S:" << std::endl;
    //doublyHead->printList();
    

}