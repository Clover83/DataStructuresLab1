#include <iostream>
#include <string>

#include "SNode.h"
#include "DNode.h"
#include "BSortAlgs.h"
#include "Tests.h"
#include "DataHandler.h"




int main() {
    // Any decending array only trigger left side in sort
    //int* arr = new int[] {6, 0, 9, 2, 4, 7, 5, 7, 5, 5};
    //SNode* singlyHead = SNode::arrToList(arr, 10);

    // test
    Tests::singleBSortCanSort(10000000);
}