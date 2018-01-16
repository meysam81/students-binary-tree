#include "student.h"

// ============================================= comparison =================================================
bool student::operator < (student &secondStudent)
{
    return (this->studentID < secondStudent.studentID);
}

bool student::operator > (student &secondStudent)
{
    return (this->studentID > secondStudent.studentID);
}

bool student::operator ==(student &secondStudent)
{
    return (this->studentID == secondStudent.studentID);
}
// =========================================== copy instance ===============================================
student &student::operator =(student &secondStudent)
{
    this->studentID = secondStudent.studentID;
    this->firstName = secondStudent.firstName;
    this->lastName = secondStudent.lastName;
    this->units = secondStudent.units;
    this->grade = secondStudent.grade;
    this->leftChild = secondStudent.leftChild;
    this->rightChild = secondStudent.rightChild;
    return (*this);
}
// ============================================== toString ==================================================
ostream& operator <<(ostream &output, student &std)
{
    output
            << "First Name: " << std.firstName << endl
            << "Last Name: " << std.lastName<< endl
            << "Student ID: " << std.studentID << endl
            << "Grade: " << std.grade << endl
            << "Current Grade: " << std.grade << endl;
    return output;
}
// ============================================== inputStd ==================================================
istream &operator >>(istream &input, student &std)
{
    cout << "First name: ";
    input >> std.firstName;
    cout << "Last name: ";
    input >> std.lastName;
    cout << "Student ID: ";
    input >> std.studentID;
    cout << "Units: ";
    input >> std.units;
    cout << "Grade: ";
    input >> std.grade;
    return input;
}
// ============================================ constructor ================================================
student::student(int ID, string firstName, string lastName, int units, int grade,
                 student *leftChild, student *rightChild)
    : studentID(ID), firstName(firstName), lastName(lastName),
      units(units), grade(grade), leftChild(leftChild), rightChild(rightChild)
{
    // nothing happens here!
}
// ============================================ destructor ================================================
student::~student()
{
    leftChild = nullptr;
    rightChild = nullptr;
    delete leftChild;
    delete rightChild;
}
