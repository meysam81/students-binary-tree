#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

// forward declaration as in we used both classes in each other
#include "binarytree.h"
class binarytree;

class student
{
private:
    // student class containing 3 fields as follow
    int studentID;
    int grade;
    int units;
    string firstName;
    string lastName;
    student *leftChild;
    student *rightChild;

public:
    // constructor
    student(int ID = 0,
            string firstName = NULL, string lastName = NULL,
            int units = 0, int grade = 0,
            student *leftChild = nullptr, student *rightChild = nullptr);

    // comparison operator overloading
    bool operator <= (student &secondStudent);
    bool operator >= (student &secondStudent);
    bool operator == (student &secondStudent);

    // just a declaration of toString method
    friend ostream &operator <<(ostream& output, const student& std);

    // as in: cin >> student
    friend istream &operator >>(istream& input, student& std);

    // to access it's private objects
    friend class binarytree;
    friend ostream &operator <<(ostream &output, student &std);
};

ostream &operator <<(ostream &output, const student &std);
istream &operator >>(istream &input, student& std);

#endif // STUDENT_H
