#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "student.h"

class binarytree
{
private:
    student *root;

    // node uniqueness
    bool notExist(student *find);

    // print students info
    void printAllInfo(student *start);

    // print failed students info
    void printFailedStudentsInfo(student *start);
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

    // print all info HELPER
    void printAllStudentsInfo();

    // print failed students info
    void printFailedInfo();
};

#endif // BINARYTREE_H
