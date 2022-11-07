#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include <iostream>

// Max heap : all nodes are smaller than their descendents

class MaxHeap{
    int *arr;
    int size;
    int cap;
    public:
    MaxHeap(int c){
        arr = new int[c];
        cap = c;
        size = 0;
    }
    public:
        int left(int i){return (2*i+1);}
        int right(int i){return (2*i+2);}
        int parent(int i){return (i-1)/2;}
        void insert(int x);
        void heapify(int i);
        int extractMax();
        void decreaseKey(int ind, int newVal);
        void deleteKey(int ind);
        void printHeap()
        {
            for(int i=0;i<size;i++)
                std::cout<<arr[i]<<" ";
            std::cout<<std::endl;
        }
};

// insert time comp : O(log(size)), we traverse across height
void MaxHeap::insert(int x){
    if(size == cap)
        return ;
    arr[size] = x;
    size++;
    int temp;
    for(int i = size-1;i !=0 && arr[parent(i)] < x;)
    {
        temp = arr[i];
        arr[i] = arr[parent(i)];
        arr[parent(i)] = temp;
        i = parent(i);
    }
}

// time comp :O(log(size))
// here parameter i is index of node we want to heapify
void MaxHeap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l < size &&  arr[l] > arr[i])
        largest = l;
    if(r< size && arr[r] > arr[largest])
        largest = r;
    
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(largest);
    }
}


// time comp :O(log(size)) , for heapify, rest of tasks are O(1)
int MaxHeap::extractMax(){
    if(size == 0)
        return INT_MAX;
    if(size == 1)
    {
        size--;
        return arr[0];
    }
    int temp = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = temp;
    size--;
    heapify(0);
    return arr[size];
}

// decrease key : changing value of node to some smaller value 
// time comp : O(log(size))
void MaxHeap::decreaseKey(int ind, int newVal){
    arr[ind] = newVal;
    int temp;
    while(ind!=0 && arr[parent(ind)] < arr[ind])
    {
        temp = arr[ind];
        arr[ind] = arr[parent(ind)];
        arr[parent(ind)] = temp;
        ind = parent(ind);
    }
}

// delete key : delete node at index i
// time comp : O(log(size))
void MaxHeap::deleteKey(int ind){
    decreaseKey(ind, INT_MAX);
    extractMax();
}

#endif