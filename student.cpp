#include "student.h"

student::student() : data(0), leftChild(nullptr), rightChild(nullptr)
{

}

student::student(int ID, student *leftChild, student *rightChild)
    : data(ID), leftChild(leftChild), rightChild(rightChild)
{

}

