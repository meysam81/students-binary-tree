#ifndef STUDENT_H
#define STUDENT_H


class student
{
private:
    int data;
    student* leftChild,
        *rightChild;
public:
    student();
    student(int ID, student* leftChild, student* rightChild);
};

#endif // STUDENT_H
