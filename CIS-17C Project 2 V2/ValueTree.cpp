#include "ValueTree.h"
#include <iostream>
using namespace std;

ValueTree::ValueTree() {
    tree = nullptr;
}

ValueNode* ValueTree::insertNode(ValueNode *newNode, int value) {
    if(newNode == nullptr) {
        newNode = new ValueNode;
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    else if(value <= newNode->value) newNode->left = insertNode(newNode->left, value);
    else newNode->right = insertNode(newNode->right, value);
    return newNode;
}

void ValueTree::traverse(ValueNode *node) {
    if(node == nullptr) return;
    traverse(node->left);
    cout << node->value << " ";
    traverse(node->right);
}

void ValueTree::deleteTree(ValueNode *node) {
    if(node == nullptr) return;
    
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}