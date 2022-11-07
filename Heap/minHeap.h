#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#include <iostream>

// min heap : all nodes are smaller than their descendents

class MinHeap{
    int *arr;
    int size;
    int cap;
    public:
    MinHeap(int c){
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
        int extractMin();
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
void MinHeap::insert(int x){
    if(size == cap)
        return ;
    arr[size] = x;
    size++;
    int temp;
    for(int i = size-1;i !=0 && arr[parent(i)] > x;)
    {
        temp = arr[i];
        arr[i] = arr[parent(i)];
        arr[parent(i)] = temp;
        i = parent(i);
    }
}

// time comp :O(log(size))
// here parameter i is index of node we want to heapify
void MinHeap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < size &&  arr[l]<arr[i])
        smallest = l;
    if(r< size && arr[r]< arr[smallest])
        smallest = r;
    
    if(smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(smallest);
    }
}


// time comp :O(log(size)) , for heapify, rest of tasks are O(1)
int MinHeap::extractMin(){
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
void MinHeap::decreaseKey(int ind, int newVal){
    arr[ind] = newVal;
    int temp;
    while(ind!=0 && arr[parent(ind)]>arr[ind])
    {
        temp = arr[ind];
        arr[ind] = arr[parent(ind)];
        arr[parent(ind)] = temp;
        ind = parent(ind);
    }
}

// delete key : delete node at index i
// time comp : O(log(size))
void MinHeap::deleteKey(int ind){
    decreaseKey(ind, INT_MIN);
    extractMin();
}

#endif