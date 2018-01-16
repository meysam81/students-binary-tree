#include "binarytree.h"
// ============================================ constructor =================================================
binarytree::binarytree(student *rootNode) : root(rootNode)
{

}
// ============================================ destructor =================================================
binarytree::~binarytree()
{
    root = nullptr;
    delete root;
}
// ============================================== add node =================================================
bool binarytree::addNode()
{
    student *p;
    cin >> (*p);

    if (root == nullptr)
    {
        root = p;
        return true;
    }
    else
    {
        student *q = root; // used for traversing
        while (true)
        {
            if ((*p) < (*q)) // new node is less than the current node
            {
                if ((q->leftChild) == nullptr) // we can add as left child
                {
                    q->leftChild = p;
                    return true;
                }
                else // go left and compare again
                    q = q->leftChild;
            }
            else if ((*p) > (*q)) // new node is greater than the current node
            {
                if (q->rightChild == nullptr)
                {
                    q->rightChild = p;
                    return true;
                }
                else
                    q = q->rightChild;
            }
            else // new node is equal to the current node and therefor we have a duplicate
            {
                cerr << "Student already exists in tree.\n";
                return false;
            }
        }
    }

}
// ============================================ search tree ================================================
bool binarytree::searchByID(int studentID)
{
    if (root == nullptr)
    {
        cerr << "Tree is empty!\n";
        return false;
    }
    student *p = new student(studentID);
    student *q = root;
    while(true)
    {
        if (q == nullptr)
        {
            cerr << "Not found\n";
            return false;
        }
        if ((*p) < (*q)) // overloaded operator
            q = q->leftChild;
        else if ((*p) > (*q)) // again overloaded operator
            q = q->rightChild;
        else if ((*p) == (*q)) // overloaded operator
            // or just: else; no difference really
        {
            cout << (*p);
            return true;
        }
    }
}
// ========================================== show best student ============================================
bool binarytree::findBestStudent()
{
    if (root == nullptr)
    {
        cerr << "Tree is empty!\n";
        return false;
    }
    student *q = root;
    while (true)
    {
        if (q->rightChild == nullptr)
        {
            if (q->grade >= 17)
            {
                cout << (*q);
                return true;
            }
            return false;
        }
        else
            q = q->rightChild;
    }
}
// ============================================== traverse =================================================
void binarytree::inorderTraverse(student *start)
{
    if (start == nullptr)
    {
        inorderTraverse(root);
        return;
    }
    student *q = start;
    if (start->leftChild != nullptr)
        inorderTraverse(start->leftChild);
    cout << (*q);
    if (start->rightChild != nullptr)
        inorderTraverse(start->rightChild);
}

void binarytree::preorderTraverse(student *start)
{
    if (start == nullptr)
    {
        inorderTraverse(root);
        return;
    }
    student *q = start;
    cout << (*q);
    if (start->leftChild != nullptr)
        inorderTraverse(start->leftChild);
    if (start->rightChild != nullptr)
        inorderTraverse(start->rightChild);
}

void binarytree::postorderTraverse(student *start)
{
    if (start == nullptr)
    {
        inorderTraverse(root);
        return;
    }
    student *q = start;
    if (start->leftChild != nullptr)
        inorderTraverse(start->leftChild);
    if (start->rightChild != nullptr)
        inorderTraverse(start->rightChild);
    cout << (*q);
}
