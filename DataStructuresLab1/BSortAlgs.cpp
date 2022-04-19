#include "BSortAlgs.h"

SNode* BSortAlgs::singleBSort(SNode* singlyHead) {
    int sortedLength = 0;
    SNode* firstUnsorted = singlyHead->next;
    SNode* lowest = singlyHead;
    lowest->next = nullptr;

    SNode* highest = lowest;

    while (firstUnsorted != nullptr) {
        sortedLength++;
        // Move first unsorted, unlink
        SNode* unsorted = firstUnsorted;
        firstUnsorted = firstUnsorted->next;
        unsorted->next = nullptr;

        // Check edges
        // Insert right end
        if (unsorted->value >= highest->value) {
            highest->next = unsorted;
            highest = unsorted;
            continue;
        }
        // Insert left end
        else if (unsorted->value <= lowest->value) {
            unsorted->next = lowest;
            lowest = unsorted;
            lowest = lowest; // remove one of these, they are equivalent
            continue;
        }

        // Set bounds and middle
        int lowerBound = 0, higherBound = sortedLength - 1;
        int middle = (lowerBound + higherBound) / 2;
        SNode* middleNode = lowest->walk(middle);
        int oldMiddle = middle;
        // Binary search
        while (true) {
            // Left
            if (unsorted->value < middleNode->value) {
                // Insert
                if (higherBound - lowerBound <= 1) {
                    SNode* prev = lowest->walk(middle - 1);
                    if (prev != lowest && prev != nullptr) {
                        prev->next = unsorted;
                    }

                    unsorted->next = middleNode;
                    if (middleNode->next == unsorted) {
                        middleNode->next = nullptr;
                    }
                    if (prev == lowest) {
                        lowest = unsorted;
                    }
                    break;
                }

                higherBound = middle;

                oldMiddle = middle;
                middle = (lowerBound + higherBound) / 2;
                middleNode = lowest->walk(middle);
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

                // Trick
                oldMiddle = middle;
                middle = (lowerBound + higherBound) / 2;
                middleNode = middleNode->walk(middle - oldMiddle);
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
    return lowest;
}

DNode* BSortAlgs::doubleBSort(DNode* doublyHead) {
    int sortedLength = 0;
    DNode* firstUnsorted = doublyHead->next;

    DNode* lowest = doublyHead;
    lowest->next = nullptr;
    lowest->prev = nullptr;

    DNode* highest = lowest;

    while (firstUnsorted != nullptr) {
        sortedLength++;
        // Move first unsorted, unlink
        DNode* unsorted = firstUnsorted;
        firstUnsorted = firstUnsorted->next;
        unsorted->next = nullptr;
        unsorted->prev = nullptr;

        // Check edges
        // Insert right end
        if (unsorted->value >= highest->value) {
            highest->next = unsorted;
            unsorted->prev = highest;
            highest = unsorted;
            continue;
        }
        // Insert left end
        else if (unsorted->value <= lowest->value) {
            unsorted->next = lowest;
            lowest->prev = unsorted;
            lowest = unsorted;
            continue;
        }

        // Set bounds and middle
        int lowerBound = 0, higherBound = sortedLength - 1;
        int middle = (lowerBound + higherBound) / 2;
        int oldMiddle = middle;
        DNode* middleNode = lowest->walk(middle);
        // Binary search
        while (true) {
            // Left
            if (unsorted->value < middleNode->value) {
                // Insert
                if (higherBound - lowerBound <= 1) {
                    DNode* prev = middleNode->prev;
                    if (prev != nullptr) {
                        prev->next = unsorted;
                    }
                    unsorted->prev = prev;

                    unsorted->next = middleNode;
                    middleNode->prev = unsorted;
                    break;
                }

                higherBound = middle;

                oldMiddle = middle;
                middle = (lowerBound + higherBound) / 2;
                middleNode = middleNode->walk(-oldMiddle + middle);
            }
            // Right
            else if (unsorted->value > middleNode->value) {
                // Insert
                if (higherBound - lowerBound <= 1) {
                    DNode* next = middleNode->next;
                    if (next != nullptr) {
                        next->prev = unsorted;
                    }
                    unsorted->next = next;

                    middleNode->next = unsorted;
                    unsorted->prev = middleNode;
                    break;
                }
                lowerBound = middle;

                oldMiddle = middle;
                middle = (lowerBound + higherBound) / 2;
                middleNode = middleNode->walk(middle - oldMiddle);
            }
            // Equal
            else {
                // Insert right of middle
                DNode* next = middleNode->next;
                if (next != nullptr) {
                    next->prev = unsorted;
                }
                unsorted->next = next;

                middleNode->next = unsorted;
                unsorted->prev = middleNode;
                break;
            }
        }
        // Binary search end, sorting next
    }
    return lowest;
}

//DNode* BSortAlgs::oldDoubleBSort(DNode* doublyHead) {
//    int sortedLength = 0;
//
//    DNode* firstUnsorted = doublyHead->next;
//
//    DNode* highest = doublyHead;
//    DNode* lowest = doublyHead;
//
//    lowest->next = nullptr;
//    lowest->prev = nullptr;
//
//    while (firstUnsorted != nullptr) {
//        sortedLength++;
//        DNode* unsorted = firstUnsorted;
//        firstUnsorted = firstUnsorted->next;
//        unsorted->next = nullptr;
//        unsorted->prev = nullptr;
//
//        // Check edges
//        if (unsorted->value >= highest->value) {
//            highest->next = unsorted;
//            unsorted->prev = highest;
//            highest = unsorted;
//            continue;
//        }
//        else if (unsorted->value <= lowest->value) {
//            unsorted->next = lowest;
//            lowest->prev = unsorted;
//            lowest = unsorted;
//            continue;
//        }
//
//        int lowerBound = 0, higherBound = sortedLength - 1;
//        int middle = (lowerBound + higherBound) / 2;
//        DNode* middleNode = lowest->walk(middle);
//        while (true) {
//            if (middleNode == nullptr) {
//                int middle = (lowerBound + higherBound) / 2;
//                middleNode = lowest->walk(middle);
//            }
//
//            // Left
//            if (unsorted->value < middleNode->value) {
//                // Insert
//                if (higherBound - lowerBound <= 1) {
//                    DNode* prev = middleNode->prev;
//                    if (prev != nullptr) {
//                        prev->next = unsorted;
//                        unsorted->prev = prev;
//                    }
//                    unsorted->next = middleNode;
//                    middleNode->prev = unsorted;
//                    break;
//                }
//                higherBound = middle; //yep
//
//                middle = (lowerBound + higherBound) / 2;
//                if (middleNode != nullptr) {
//                    middleNode = middleNode->walk(-middle);
//                }
//            }
//
//            // Right
//            else if (unsorted->value > middleNode->value) {
//                // Insert
//                if (higherBound - lowerBound <= 1) {
//                    DNode* next = middleNode->next; //mid next
//                    if (next != nullptr) {
//                        next->prev = unsorted; //mid next prev = unsorted
//                        unsorted->next = next; //unsorted next = mid next
//                    }
//                    middleNode->next = unsorted;  //yep
//                    unsorted->prev = middleNode; //yep
//                    break;
//                }
//                lowerBound = middle;
//                middle = (lowerBound + higherBound) / 2;
//                if (middleNode != nullptr) {
//                    middleNode = middleNode->walk(sortedLength - middle);
//                }
//
//            }
//
//            // Equal
//            else {
//                // Insert right of middle
//                DNode* next = middleNode->next; //mid next
//                if (next != nullptr) {
//                    next->prev = unsorted; //mid next prev = unsorted
//                    unsorted->next = next; //unsorted next = mid next
//                }
//                middleNode->next = unsorted;  //yep
//                unsorted->prev = middleNode; //yep
//
//                break;
//            }
//
//        }
//
//    }
//    return lowest;
//}