#include "OnlineForm.h"
#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

OnlineForm::OnlineForm()
{
    cout << "Enter your name: ";
    getline(cin, name); // Using getline to capture full name

    while (true) {
        cout << "Enter your DOB (DD/MM/YYYY): ";
        getline(cin, DOB); // Using getline to capture full DOB

        if (isValidDOB(DOB)) {
            break;
        } else {
            cout << "Invalid DOB format. Please use DD/MM/YYYY." << endl;
        }
    }

    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your NID: ";
    cin >> NID;
    cin.ignore(); // To ignore the newline character left in the input buffer
}

void OnlineForm::display() const
{
    cout << "Name: " << name << endl
         << "Date of Birth: " << DOB << endl
         << "Age: " << age << endl
         << "NID: " << NID << endl;
}

bool OnlineForm::isValidDOB(const string& dob) const
{
    regex pattern(R"(^\d{2}/\d{2}/\d{4}$)");
    return regex_match(dob, pattern);
}

void OnlineForm::saveToFile() const
{
    ofstream outFile("form_details.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << name << endl
                << DOB << endl
                << age << endl
                << NID << endl
                << "------------------------" << endl;
        outFile.close();
    }
    else
    {
        cout << "Unable to open file for writing." << endl;
    }
}

void OnlineForm::loadFromFile() const
{
    ifstream inFile("form_details.txt");
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
        inFile.close();
    }
    else
    {
        cout << "Unable to open file for reading." << endl;
    }
}
