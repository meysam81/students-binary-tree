#include "student.h"

// ============================================= comparison =================================================
bool student::operator <= (student &secondStudent)
{
    return (this->getStudentID() <= secondStudent.getStudentID());
}

bool student::operator ==(student &secondStudent)
{
    return (this->getStudentID() == secondStudent.getStudentID());
}
// ============================================== toString ==================================================
ostream& operator <<(ostream &output, student &std)
{
    output << "Student ID: " << std.getStudentID() << endl
           << "First Name: " << std.getFirstName() << endl
           << "Last Name: " << std.getLastName()<< endl
           << "Current Grade: " << std.getGrade() << endl;
    return output;
}
// =============================================== getters ==================================================
int student::getStudentID() const
{
    return studentID;
}

int student::getGrade() const
{
    return grade;
}

string student::getFirstName() const
{
    return firstName;
}

string student::getLastName() const
{
    return lastName;
}

student *student::getLeftChild() const
{
    return leftChild;
}

student *student::getRightChild() const
{
    return rightChild;
}
// =============================================== setters ==================================================
void student::setRightChild(student *value)
{
    rightChild = value;
}

void student::setLeftChild(student *value)
{
    leftChild = value;
}
// ============================================ constructors ================================================
student::student() : studentID(0), grade(0), firstName(NULL),
    lastName(NULL), leftChild(NULL), rightChild(NULL)
{

}

student::student(int ID) : studentID(ID), grade(0), firstName(NULL),
    lastName(NULL), leftChild(NULL), rightChild(NULL)
{

}

student::student(int ID, int grade, string firstName, string lastName, student *leftChild, student *rightChild)
    : studentID(ID), grade(grade), firstName(firstName), lastName(lastName), leftChild(leftChild), rightChild(rightChild)
{

}
