#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int nodeSum;
    int leftIndex, rightIndex; // Replacing vector with two variables
    
    Node(int l, int r) : left(nullptr), right(nullptr), nodeSum(0), leftIndex(l), rightIndex(r) {}
};

class SegmentTree {
private:
    Node* root;

    void updateRange(Node* node, int index, int value);
    Node* constructTree(vector<int>& inputArray, int left, int right);
    int getRangeSum(int left, int right, Node* node);

public:
    SegmentTree(vector<int> inputArray);
    void updateTree(int index, int value);
    int getSum(int left, int right);
};

#endif
