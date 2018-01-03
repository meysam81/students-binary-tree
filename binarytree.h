#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "student.h"
#include <vector>

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

    // find the best student
    void findBestStudent();

    // print students info
    void printAllStudentsInfo(student *start);

    // print failed students info
    void printFailedStudentsInfo(student *start);
};

#endif // BINARYTREE_H
