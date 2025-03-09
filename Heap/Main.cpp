#include<iostream>
#include<bits/stdc++.h>
#include "MinHeap.h"
using namespace std;


int main(){
    MinHeap* minHeap = new MinHeap(10);
    vector<int> inputArray = {10, 9, -1, 3, 5, 9};
    for(auto inp: inputArray)
        minHeap->insertKey(inp);
    
    cout << minHeap->extractMin() << endl;
    cout << minHeap->extractMin() << endl;
    cout << minHeap->extractMin() << endl;
}