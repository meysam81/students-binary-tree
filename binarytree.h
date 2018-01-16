#ifndef BINARYTREE_H
#define BINARYTREE_H


#include "student.h"
class student;


class binarytree
{
private:
    student *root; // head of the tree

public:
    // constructor
    binarytree(student *rootNode = nullptr);
    // destructor
    ~binarytree();

    // add node
    bool addNode();

    // search students by id
    bool searchByID(int studentID);

    // find the best student
    bool findBestStudent();

    // destructor
    bool deleteStudent(int value, student *start = nullptr);

    // print students info
    void inorderTraverse(student *start = nullptr);
    void preorderTraverse(student *start = nullptr);
    void postorderTraverse(student *start = nullptr);

};

#endif // BINARYTREE_H
