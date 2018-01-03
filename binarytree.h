#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "student.h"

class binarytree
{
private:
    student *root;
    int numberOfNodes;
public:
    binarytree();
    binarytree(student *rootNode);
};

#endif // BINARYTREE_H
