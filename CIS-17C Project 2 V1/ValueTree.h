#ifndef VALUETREE_H
#define VALUETREE_H

#include "ValueNode.h"

class ValueTree {
    public: 
        ValueNode *tree = nullptr;
        ValueTree();
        ValueNode* insertNode(ValueNode *newNode, int value);
        void traverse(ValueNode *node);
        void deleteTree(ValueNode *tree);
};

#endif /* VALUETREE_H */
