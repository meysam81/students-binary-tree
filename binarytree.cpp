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
    student *p = new student();
    try
    {
        cin >> (*p);
    }
    catch (...)
    {
        cerr << "Enter correct input please!\n";
        return false;
    }

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
// =========================================== delete node =================================================
bool binarytree::deleteStudent(int value, student *start, student *startFather)
{
    if (start == nullptr)
    {
        if (root == nullptr)
        {
            cerr << "Tree is empty!\n";
            return false;
        }
        return deleteStudent(value, root);
    }

    student *p = new student(value);
    student *hold;
    if ((*p) == (*root)) // special case for root and for root ONLY
    {
        if ((root->leftChild == nullptr) && (root->rightChild == nullptr))
        {
            root = nullptr;
            cout << "Student deleted successfully!\n";
            return true;
        }
        else if (!(root->leftChild == nullptr) && (root->rightChild == nullptr))
        {
            student *tmp = root;
            root = root->leftChild;
            tmp = nullptr;
            cout << "Student deleted successfully!\n";
            return true;
        }
        else if ((root->leftChild == nullptr) && !(root->rightChild == nullptr))
        {
            student *tmp = root;
            root = root->rightChild;
            tmp = nullptr;
            cout << "Student deleted successfully!\n";
            return true;
        }
        else
        {
            student *tmp = root->rightChild;
            hold = root;
            while (tmp->leftChild != nullptr)
            {
                hold = tmp;
                tmp = tmp->leftChild;
            }
            (*root) = (*tmp);
            return deleteStudent(tmp->studentID, root->rightChild, hold);
        }
    }
    student *q = start;
    if (startFather != nullptr)
        hold = startFather;
    else
        hold = q;
    while (true)
    {
        if (q == nullptr)
        {
            cerr << "No such student found!\n";
            return false;
        }
        if ((*p) < (*q))
        {
            hold = q;
            q = q->leftChild;
        }
        else if ((*p) > (*q))
        {
            hold = q;
            q = q->rightChild;
        }
        else if ((*p) == (*q))
        {
            // first case: node is leaf
            if (q->leftChild == nullptr && q->rightChild == nullptr)
            {
                if (hold->leftChild == q)
                    hold->leftChild = nullptr;
                else if (hold->rightChild == q)
                    hold->rightChild = nullptr;
                q = nullptr;
                delete q;
                cout << "Student deleted successfully!\n";
                return true;
            }

            // second case: node has one child
            else if (!(q->leftChild == nullptr) && q->rightChild == nullptr)
            {
                if (hold->leftChild == q)
                    hold->leftChild = q->leftChild;
                else if (hold->rightChild == q)
                    hold->rightChild = q->leftChild;
                q = nullptr;
                delete q;
                cout << "Student deleted successfully!\n";
                return true;
            }
            // still second case
            else if (q->leftChild == nullptr && !(q->rightChild == nullptr))
            {
                if (hold->leftChild == q)
                    hold->leftChild = q->rightChild;
                else if (hold->rightChild == q)
                    hold->rightChild = q->rightChild;
                q = nullptr;
                delete q;
                cout << "Student deleted successfully!\n";
                return true;
            }

            // get ready, cause here comes the hardest case: the last case
            else
            {
                student *r = q;
                hold = q;
                r = r->rightChild;
                while (r->leftChild != nullptr)
                {
                    hold = r;
                    r = r->leftChild;
                }
                (*q) = (*r);
                return deleteStudent(r->studentID, q->rightChild, hold);
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
        else
            //            if ((*p) == (*q)) // overloaded operator
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
        if (root == nullptr)
        {
            cerr << "Tree is empty!\n";
            return;
        }
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
        if (root == nullptr)
        {
            cerr << "Tree is empty!\n";
            return;
        }
        preorderTraverse(root);
        return;
    }
    student *q = start;
    cout << (*q);
    if (start->leftChild != nullptr)
        preorderTraverse(start->leftChild);
    if (start->rightChild != nullptr)
        preorderTraverse(start->rightChild);
}

void binarytree::postorderTraverse(student *start)
{
    if (start == nullptr)
    {
        if (root == nullptr)
        {
            cerr << "Tree is empty!\n";
            return;
        }
        postorderTraverse(root);
        return;
    }
    student *q = start;
    if (start->leftChild != nullptr)
        postorderTraverse(start->leftChild);
    if (start->rightChild != nullptr)
        postorderTraverse(start->rightChild);
    cout << (*q);
}
