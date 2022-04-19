#include "Tests.h"


void Tests::singleBSortCanSort(int nTests) {
    for (int i = 0; i < nTests; i++) {
        const int size = 20;
        SNode* singlyHead = SNode::getRandomList(size);
        singlyHead = BSortAlgs::singleBSort(singlyHead);

        SNode* current = singlyHead;
        int count = 1;
        while (current->next != nullptr) {
            if (current->next->value < current->value) {
                std::cout << "Failed!" << std::endl;
                break;
            }
            current = current->next;
            count++;
        }
        if (count != size) {
            std::cout << "Failed! Size difference" << std::endl;
        }

        if (i % 10000 == 0) {
            int completeness = 100*i / nTests;
            std::cout << std::to_string(completeness) << "%" << std::endl;
        }
    }
    std::cout << "Tests complete." << std::endl;
}

void Tests::doubleBSortCanSort(int nTests) {
    for (int i = 0; i < nTests; i++) {
        const int size = 20;
        DNode* doublyHead = DNode::getRandomList(size);
        doublyHead = BSortAlgs::doubleBSort(doublyHead);

        DNode* current = doublyHead;
        int count = 1;
        while (current->next != nullptr) {
            if (current->next->value < current->value) {
                std::cout << "Failed!" << std::endl;
                break;
            }
            current = current->next;
            count++;
        }
        if (count != size) {
            std::cout << "Failed! Size difference" << std::endl;
        }
        if (i % 10000 == 0) {
            int completeness = 100 * i / nTests;
            std::cout << std::to_string(completeness) << "%" << std::endl;
        }
    }
    std::cout << "Tests complete." << std::endl;
}