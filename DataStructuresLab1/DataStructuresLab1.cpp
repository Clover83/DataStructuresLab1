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
        SNode* randomList = SNode::getRandomList(i);
        auto start = high_resolution_clock::now();
        BSortAlgs::singleBSort(randomList);
        auto stop = high_resolution_clock::now();
        // memory leak
        auto duration = duration_cast<microseconds>(stop - start);
        dh.push(i, duration.count());
    }
    dh.write();
}

int main() {
    exportSingleBSort("test", 1000000, 100);
}