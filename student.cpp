#include "student.h"

int student::getData() const
{
    return data;
}

bool student::operator <(student secondStudent)
{
    return (this->getData() < secondStudent.getData());
}

student::student() : data(0), leftChild(nullptr), rightChild(nullptr)
{

}

student::student(int ID, student *leftChild, student *rightChild)
    : data(ID), leftChild(leftChild), rightChild(rightChild)
{

}

