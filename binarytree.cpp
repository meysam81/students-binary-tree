#include "binarytree.h"
// ============================================ constructors ================================================
binarytree::binarytree() : root(nullptr), numberOfNodes(0)
{

}

binarytree::binarytree(student *rootNode) : root(rootNode), numberOfNodes(0)
{

}
// ============================================== add node =================================================
bool binarytree::notExist(student *find)
{
    if (root == nullptr)
        return false;
    student *p = root;
    while (true)
    {
        if (p == nullptr)
            return true;
        if (p < find)
            p = p->getLeftChild();
        else if (find < p)
            p = p->getRightChild();
        else
            return false;
    }
}
bool binarytree::addNode()
{
    int studentID;
    int grade;
    string firstName;
    string lastName;

    cout << "Enter Student ID: ";
    cin >> studentID;
    cout << "Enter Student Grade: ";
    cin >> grade;
    cout << "Enter Student First Name: ";
    cin >> firstName;
    cout << "Enter Student Last Name: ";
    cin >> lastName;

    if (root == nullptr)
    {
        root = new student(studentID, grade, firstName, lastName, nullptr, nullptr);
        return true;
    }
    else
    {
        student *p = new student(studentID, grade, firstName, lastName, nullptr, nullptr);
        if (notExist(p))
        {
            student *q = root;
            while (true)
            {
                if (p < q)
                {
                    if (q->getLeftChild() == nullptr)
                    {
                        q->setLeftChild(p);
                        return true;
                    }
                    else
                        q = q->getLeftChild();
                }
                else if (q < p)
                {
                    if (q->getRightChild() == nullptr)
                    {
                        q->setRightChild(p);
                        return true;
                    }
                    else
                        q = q->getLeftChild();
                }
            }
        }
        else
        {
            cerr << "Student already exist in tree.\n";
            return false;
        }
    }

}
// ============================================= question 1 ================================================
void binarytree::searchByID(int studentID)
{
    student *p = root;
    student *q = new student(studentID);
    while(true)
    {
        if (*p == *q) // overloaded operator
        {
            cout << *p;
            return;
        }
        if (p == nullptr)
        {
            cout << "No such student found!\n";
            return;
        }
        if (*p <= *q) // overloaded operator
            p = p->getLeftChild();
        else
            p = p->getLeftChild();
    }
}
