#include "binarytree.h"

int main(int argc, char *argv[])
{
    binarytree bt;
    do
    {
        system("clear"); // to clear the terminal for linux; change the argument to 'cls' for windows
        cout << "1. Search a student by ID\n"
             << "2. Find the best student\n"
             << "3. Print info of all students\n"
             << "4. Print failed students\n"
             << "5. [last but not least] add a student\n"
             << "6. Exit\n\n"
             << "Enter your choice: ";
        int input;
        cin >> input;
        switch (input) {
        case 1:
            int id;
            cout << "\nEnter an id to search for: ";
            cin >> id;
            bt.searchByID(id);
            break;
        case 2:
            bt.findBestStudent();
            break;
        case 3:
            bt.printAllStudentsInfo();
            break;
        case 4:
            bt.printFailedInfo();
            break;
        case 5:
            bt.addNode();
            break;
        case 6:
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
