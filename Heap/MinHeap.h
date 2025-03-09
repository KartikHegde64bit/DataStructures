#include<iostream>
#include<vector>
using namespace std;


class MinHeap{
    private:
        vector<int> minHeap;
        int heapSize;   // represents the current size of heap
        int capacity;   // represents the total capacity

        int lastIndex;  // this is where new elements will be inserted

    public:
        MinHeap(int capacity);
        
        int extractMin();
        void insertKey(int value);
        void deleteKey(int value);

        void shiftDown(int index);
        void shiftUp(int index);

        int getParentIndex(int index);
        int getLeftChild(int index);
        int getRightChild(int index);
};