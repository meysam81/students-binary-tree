#include "student.h"

// ============================================= comparison =================================================
bool student::operator < (student &secondStudent)
{
    return (this->studentID <= secondStudent.studentID);
}

bool student::operator > (student &secondStudent)
{
    return (this->studentID >= secondStudent.studentID);
}

bool student::operator ==(student &secondStudent)
{
    return (this->studentID == secondStudent.studentID);
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
// ============================================ constructors ================================================
student::student(int ID, string firstName, string lastName, int units, int grade,
                 student *leftChild, student *rightChild)
    : studentID(ID), firstName(firstName), lastName(lastName),
      units(units), grade(grade), leftChild(leftChild), rightChild(rightChild)
{
    // nothing happens here!
}
