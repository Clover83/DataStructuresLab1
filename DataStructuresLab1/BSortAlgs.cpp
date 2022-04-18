#include "BSortAlgs.h"

SNode* BSortAlgs::singleBSort(SNode* singlyHead) {
    int sortedLength = 0;
    SNode* firstUnsorted = singlyHead->next;
    SNode* newHead = singlyHead;
    newHead->next = nullptr;

    SNode* highest = newHead;
    SNode* lowest = newHead;

    while (firstUnsorted != nullptr) {
        sortedLength++;
        // Move first unsorted, unlink
        SNode* unsorted = firstUnsorted;
        firstUnsorted = firstUnsorted->next;
        unsorted->next = nullptr;

        // Check edges
        if (unsorted->value >= highest->value) {
            highest->next = unsorted;
            highest = unsorted;
            continue;
        }
        else if (unsorted->value <= lowest->value) {
            unsorted->next = lowest;
            lowest = unsorted;
            newHead = lowest; // remove one of these, they are equivalent
            continue;
        }

        // Set bounds and middle
        int lowerBound = 0, higherBound = sortedLength - 1;
        int middle = (lowerBound + higherBound) / 2;
        SNode* middleNode = newHead->walk(middle);
        // Binary search
        while (true) {
            middle = (lowerBound + higherBound) / 2;
            middleNode = newHead->walk(middle); // replace with trick
            // Left
            if (unsorted->value < middleNode->value) {
                // Insert
                if (higherBound - lowerBound <= 1) {
                    SNode* prev = newHead->walk(middle - 1);
                    if (prev != newHead && prev != nullptr) {
                        prev->next = unsorted;
                    }

                    unsorted->next = middleNode;
                    if (middleNode->next == unsorted) {
                        middleNode->next = nullptr;
                    }
                    if (prev == newHead) {
                        newHead = unsorted;
                    }
                    break;
                }

                higherBound = middle;
            }
            // Right
            else if (unsorted->value > middleNode->value) {
                // Insert
                if (higherBound - lowerBound <= 1) {
                    unsorted->next = middleNode->next;
                    middleNode->next = unsorted;
                    break;
                }
                lowerBound = middle;
            }
            // Equal
            else {
                // Insert right of middle
                unsorted->next = middleNode->next;
                middleNode->next = unsorted;
                break;
            }
        }
        // Binary search end, sorting next
    }
    return newHead;
}

//DNode* BSortAlgs::doubleBSort(DNode* doublyHead) {
//
//}