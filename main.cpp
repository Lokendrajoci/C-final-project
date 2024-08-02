#include <iostream>
#include "OnlineForm.h"
#include <fstream>
#include <regex>
#include <limits>
#include <cstdlib>

using namespace std;

void options()
{
    cout << "Enter 1 for registration: " << endl
         << "Enter 2 for LISCENSE exam: ";
}

int main()
{
    int userInput = 0;

    while (true)
    {
        options();
        cin >> userInput;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a number.\n";
            continue;
        }

        switch (userInput)
        {
        case 1:
        {
            OnlineForm o1;
            o1.display();
            o1.saveToFile();
            o1.loadFromFile();
            break;
        }
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        exit(0);
    }

    return 0;
}