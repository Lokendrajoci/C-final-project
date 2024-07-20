#include <iostream>
#include "OnlineForm.h"
#include <fstream>
#include <regex>
using namespace std;

void options()
{
    cout << "Enter 1 for registration: ";
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
            break;
        }
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }

    return 0;
}
