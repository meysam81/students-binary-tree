#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "student.h"

class binarytree
{
private:
    student *root;
    int numberOfNodes;


    // node uniqueness
    bool notExist(student *find);

public:
    // constructors
    binarytree();
    binarytree(student *rootNode);

    // add node
    bool addNode();


    // search students by id
    void searchByID(int studentID);
};

#endif // BINARYTREE_H
