#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class student
{
private:
    // student class containing 3 fields as follow
    int studentID;
    int grade;
    string firstName;
    string lastName;
    student *leftChild;
    student *rightChild;

public:
    // constructor
    student();
    student(int ID);
    student(int ID, int grade,
            string firstName, string lastName,
            student* leftChild, student* rightChild);

    // getters
    int getStudentID() const;
    int getGrade() const;
    student *getRightChild() const;
    student *getLeftChild() const;
    string getFirstName() const;
    string getLastName() const;

    // setters
    void setRightChild(student *value);
    void setLeftChild(student *value);

    // comparison operator overloading
    bool operator <= (student &secondStudent);
    bool operator == (student &secondStudent);

    // just a declaration of toString method
    friend ostream &operator <<(ostream& output, student& std);
};

ostream& operator <<(ostream &output, student &std);

#endif // STUDENT_H
