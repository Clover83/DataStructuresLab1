#include "Tests.h"


void Tests::singleBSortCanSort(int nTests) {
    for (int i = 0; i < nTests; i++) {
        SNode* singlyHead = SNode::getRandomList(10);
        singlyHead = BSortAlgs::singleBSort(singlyHead);

        SNode* current = singlyHead;
        while (current->next != nullptr) {
            if (current->next->value < current->value) {
                std::cout << "Failed!" << std::endl;
                break;
            }
            current = current->next;
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
        DNode* doublyHead = DNode::getRandomList(10);
        doublyHead = BSortAlgs::doubleBSort(doublyHead);

        DNode* current = doublyHead;
        while (current->next != nullptr) {
            if (current->next->value < current->value) {
                std::cout << "Failed!" << std::endl;
                break;
            }
            current = current->next;
        }
        if (i % 10000 == 0) {
            int completeness = 100 * i / nTests;
            std::cout << std::to_string(completeness) << "%" << std::endl;
        }
    }
    std::cout << "Tests complete." << std::endl;
}