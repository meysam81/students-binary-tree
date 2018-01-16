#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "student.h"

class student;

class binarytree
{
private:
    student *root; // head of the tree

public:
    // constructors
    binarytree(student *rootNode = nullptr);

    // add node
    bool addNode();

    // search students by id
    bool searchByID(int studentID);

    // find the best student
    bool findBestStudent();

    // print students info
    void inorderTraverse(student *start = nullptr);
    void preorderTraverse(student *start = nullptr);
    void postorderTraverse(student *start = nullptr);

};

#endif // BINARYTREE_H
