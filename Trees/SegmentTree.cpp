#include "SegmentTree.h"

SegmentTree::SegmentTree(vector<int> inputArray) {
    root = constructTree(inputArray, 0, inputArray.size() - 1);
}

Node* SegmentTree::constructTree(vector<int>& inputArray, int left, int right) {
    Node* node = new Node(left, right);
    
    if (left == right) {
        node->nodeSum = inputArray[left];
        return node;
    }
    
    int mid = left + (right - left) / 2;
    node->left = constructTree(inputArray, left, mid);
    node->right = constructTree(inputArray, mid + 1, right);
    node->nodeSum = node->left->nodeSum + node->right->nodeSum;
    
    return node;
}

void SegmentTree::updateTree(int index, int value) {
    updateRange(root, index, value);
}

void SegmentTree::updateRange(Node* node, int index, int value) {
    if (!node || index < node->leftIndex || index > node->rightIndex) 
        return;

    if (node->leftIndex == node->rightIndex) {
        node->nodeSum = value;
        return;
    }

    updateRange(node->left, index, value);
    updateRange(node->right, index, value);

    node->nodeSum = (node->left ? node->left->nodeSum : 0) + (node->right ? node->right->nodeSum : 0);
}

int SegmentTree::getRangeSum(int left, int right, Node* node) {
    if (!node || node->rightIndex < left || node->leftIndex > right) 
        return 0;
    if (left <= node->leftIndex && right >= node->rightIndex) 
        return node->nodeSum;
    return getRangeSum(left, right, node->left) + getRangeSum(left, right, node->right);
}

int SegmentTree::getSum(int left, int right) {
    return getRangeSum(left, right, root);
}
