#include <iostream>

#include "minHeap.h"

using namespace std; 

int main()
{
    MinHeap heap(20);
    heap.insert(5);
    heap.insert(6);
    heap.insert(2);
    heap.insert(4);
    heap.insert(3);
    heap.insert(1);
    heap.insert(10);
    heap.insert(11);
    heap.insert(12);
    heap.insert(8);
    heap.insert(7);
    heap.insert(9);
    heap.insert(15);
    heap.insert(16);


    heap.printHeap();
    // cout<<heap.extractMin()<<endl;
    // heap.printHeap();
    heap.decreaseKey(12, 1);
    heap.printHeap();
    heap.deleteKey(12);
    heap.printHeap();


    return 0;
}