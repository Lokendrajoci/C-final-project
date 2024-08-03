#include <iostream>
#include "OnlineForm.h"
#include "quiz.hpp"
#include "VehicleRegistration.hpp"
#include "LicenseRenewal.hpp" // Include the header file for license renewal
#include "welcome.hpp"
#include <fstream>
#include <regex>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
using namespace std;

void options()
{
    system("cls");
    cout << "\tEnter 1 for  registration: " << endl
         << "\tEnter 2 for LISCENSE exam: " << endl
         << "\tEnter 3 for Vehicle Registration: " << endl
         << "\tEnter 4 for BlueBook Renew: " << endl
         << "\tEnter 5 for Liscense Renew: " << endl
         << "\tEnter 6 Exit:  " << endl;
}

int main()
{

    Initializing_Display();

    int userInput = 0;

    VehicleRegistrationSystem regSystem("vehicle_database.bin");
    BlueBookRenewalSystem blueBookRenewalSystem(regSystem);

    while (true)
    {
        options();
        cout << setfill(' ');
        cout << setw(15) << "\tEnter your choice: ";
        std::cin >> userInput;
        system("cls");
        if (cin.fail())
        {
            std::cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a number.\n";
            continue;
        }

        switch (userInput)
        {
        case 1:
        {
            OnlineForm o1;
            // o1.display();
            o1.saveToFile();
            o1.id_display();
            break;
        }

        case 2:
        {
            Quiz quiz("oopProject//qData.json");
            quiz.start();
            std::cin.get();
            break;
        }
        case 3:
        {
            srand(time(0));
            int choice;

            while (true)
            {
                cout << "\n\n";
                cout << "1. Register Vehicle\n";
                cout << "2. Search Vehicle by Plate Number\n";
                cout << "3. Return to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                // Handle invalid input in the inner loop
                if (cin.fail())
                {
                    cin.clear();                                         // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input, please enter a number.\n";
                    continue; // Skip to the next iteration of the loop
                }

                switch (choice)
                {
                case 1:
                {
                    int result = system("cls"); // Use "cls" for Windows
                    if (result == -1)
                    {
                        cerr << "Error clearing the screen" << endl;
                    }
                    regSystem.registerVehicle();
                    break;
                }
                case 2:
                {
                    int result = system("cls"); // Use "cls" for Windows
                    if (result == -1)
                    {
                        cerr << "Error clearing the screen" << endl;
                    }
                    regSystem.searchVehicleByPlateNumber();
                    break;
                }
                case 3:
                    goto main_menu;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
            }
        main_menu:
            break;
        }

        case 4:
        {
            int result = system("cls"); // Use "cls" for Windows
            if (result == -1)
            {
                cerr << "Error clearing the screen" << endl;
            }
            blueBookRenewalSystem.renewVehicle();
            break;
        }
        case 5:
        {
            renewLicense();
        }
        case 6:
        {
            cout << "Exiting the system. Goodbye!\n";
            return 0;
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