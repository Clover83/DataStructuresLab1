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

DNode* BSortAlgs::doubleBSort(DNode* doublyHead) {
    int sortedLength = 0;

    DNode* firstUnsorted = doublyHead->next;

    DNode* highest = doublyHead;
    DNode* lowest = doublyHead;

    lowest->next = nullptr;
    lowest->prev = nullptr;

    while (firstUnsorted != nullptr) {
        sortedLength++;
        DNode* unsorted = firstUnsorted;
        firstUnsorted = firstUnsorted->next;
        unsorted->next = nullptr;
        unsorted->prev = nullptr;

        // Check edges
        if (unsorted->value >= highest->value) {
            highest->next = unsorted;
            unsorted->prev = highest;
            highest = unsorted;
            continue;
        }
        else if (unsorted->value <= lowest->value) {
            unsorted->next = lowest;
            lowest->prev = unsorted;
            lowest = unsorted;
            continue;
        }

        int lowerBound = 0, higherBound = sortedLength - 1;
        int middle = (lowerBound + higherBound) / 2;
        DNode* middleNode = lowest->walk(middle);
        while (true) {
            if (middleNode == nullptr) {
                int middle = (lowerBound + higherBound) / 2;
                middleNode = lowest->walk(middle);
            }

            // Left
            if (unsorted->value < middleNode->value) {
                // Insert
                if (higherBound - lowerBound <= 1) {
                    DNode* prev = middleNode->prev;
                    if (prev != nullptr) {
                        prev->next = unsorted;
                        unsorted->prev = prev;
                    }
                    unsorted->next = middleNode;
                    middleNode->prev = unsorted;
                    break;
                }
                higherBound = middle; //yep

                middle = (lowerBound + higherBound) / 2;
                if (middleNode != nullptr) {
                    middleNode = middleNode->walk(-middle);
                }
            }

            // Right
            else if (unsorted->value > middleNode->value) {
                // Insert
                if (higherBound - lowerBound <= 1) {
                    DNode* next = middleNode->next; //mid next
                    if (next != nullptr) {
                        next->prev = unsorted; //mid next prev = unsorted
                        unsorted->next = next; //unsorted next = mid next
                    }
                    middleNode->next = unsorted;  //yep
                    unsorted->prev = middleNode; //yep
                    break;
                }
                lowerBound = middle;
                middle = (lowerBound + higherBound) / 2;
                if (middleNode != nullptr) {
                    middleNode = middleNode->walk(sortedLength-middle);
                }

            }

            // Equal
            else {
                // Insert right of middle
                DNode* next = middleNode->next; //mid next
                if (next != nullptr) {
                    next->prev = unsorted; //mid next prev = unsorted
                    unsorted->next = next; //unsorted next = mid next
                }
                middleNode->next = unsorted;  //yep
                unsorted->prev = middleNode; //yep

                break;
            }

        }

    }
    return lowest;
}