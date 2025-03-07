#include<iostream>
#include<bits/stdc++.h>
#include "SegmentTree.h"
using namespace std;


int main() {
    vector<int> inputArray = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(inputArray);
    
    cout << "Sum of range (1, 3): " << segTree.getSum(1, 3) << endl;
    segTree.updateTree(1, 10);
    cout << "Sum of range (1, 3) after update: " << segTree.getSum(1, 3) << endl;
    
    return 0;
}