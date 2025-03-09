#include "MinHeap.h"


MinHeap::MinHeap(int capacity){
    minHeap.reserve(capacity);
    heapSize = 0;
    this->capacity = capacity;
}

void MinHeap::insertKey(int value){
    // check if size is full
    if(heapSize == capacity){
        cout << "CAPACITY FULL" << endl;
        return;
    }
    heapSize += 1; // after inserting update the lastNode;
    int index = heapSize-1;
    minHeap[index] = value;
    shiftUp(index);
    return;
}

int MinHeap::extractMin(){
    if(heapSize == 0){
        return INT_MIN; // basic value to be returned
    }
    if (heapSize == 1) {
        heapSize--;
        return minHeap[0];
    }
    int result = minHeap[0];
    minHeap[0] = minHeap[heapSize-1];
    heapSize -= 1; // decrease the size of heap
    if(heapSize > 0)
        shiftDown(0);
    return result;
}

void MinHeap::deleteKey(int index){
    if(heapSize > index){
        minHeap[index] = INT_MIN;
        shiftUp(index);
        extractMin();
    }  
}

void MinHeap::shiftDown(int index){
    int smallIndex = index;
    while(true){
        int leftIndex = getLeftChild(index);
        int rightIndex = getRightChild(index);
        if(leftIndex < heapSize && minHeap[leftIndex] < minHeap[smallIndex]){
            smallIndex = leftIndex;
        }
        if(rightIndex < heapSize && minHeap[rightIndex] < minHeap[smallIndex]){
            smallIndex = rightIndex;
        }

        if(smallIndex == index){
            break;
        }
        swap(minHeap[index], minHeap[smallIndex]);
        index = smallIndex;
    }
}

void MinHeap::shiftUp(int index){
    int parentIndex = getParentIndex(index);
    while (index > 0 && minHeap[parentIndex] > minHeap[index])
    {
        swap(minHeap[parentIndex], minHeap[index]);
        index = parentIndex;
        parentIndex = getParentIndex(index);
    }
    
}

int MinHeap::getParentIndex(int index){
    return (index - 1) / 2;
}

int MinHeap::getLeftChild(int index){
    return 2*index + 1;
}

int MinHeap::getRightChild(int index){
    return 2*index + 2;
}