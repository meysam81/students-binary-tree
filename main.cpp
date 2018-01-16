#include "binarytree.h"

int main(int argc, char *argv[])
{
    binarytree bt;
    do
    {
        system("clear"); // to clear the terminal for linux; change the argument to 'cls' for windows
        cout
                << "1. Add a student\n"
                << "2. Search a student by ID\n"
                << "3. Delete a student\n"
                << "4. Inorder traverse\n"
                << "5. Preorder traverse\n"
                << "6. Postorder traverse\n"
                << "7. Exit\n\n"
                << "Enter your choice: ";
        int input;
        cin >> input;
        switch (input) {
        case 1:
            bt.addNode();
            break;
        case 2:
            int id;
            cout << "\nEnter an id to search for: ";
            cin >> id;
            bt.searchByID(id);
            break;
        case 3:
            cout << "Enter student ID to be deleted: ";
            id;
            cin >> id;
            bt.deleteStudent(id);
            break;
        case 4:
            bt.inorderTraverse();
            break;
        case 5:
            bt.preorderTraverse();
            break;
        case 6:
            bt.postorderTraverse();
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
        }

        // to hold the screen for showing the results
        cout << "\nPress any key to continue...\n" << flush;
        cin.ignore();
        cin.ignore();

    } while (true);
    return 0;
}
