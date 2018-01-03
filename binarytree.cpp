#include "binarytree.h"
// ============================================ constructors ================================================
binarytree::binarytree() : root(nullptr), numberOfNodes(0)
{

}

binarytree::binarytree(student *rootNode) : root(rootNode), numberOfNodes(0)
{

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
