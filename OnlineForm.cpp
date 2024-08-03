#include "OnlineForm.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include <limits>
#include <random>
#include <cstdlib>

using namespace std;

OnlineForm::OnlineForm()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter your name: ";
    getline(cin, name);

    while (true)
    {
        cout << "Enter your DOB (DD/MM/YYYY): ";
        getline(cin, DOB);

        if (isValidDOB(DOB))
        {
            break;
        }
        else
        {
            cout << "Invalid DOB format. Please use DD/MM/YYYY." << endl;
        }
    }

    cout << "Enter your age: ";
    cin >> age;

    while (true)
    {
        cout << "Enter your NID: ";
        cin >> NID;

        if (nidCheck(NID) == 0)
        {
            break;
        }
        else
        {
            cout << "NID already exists. Please enter a different NID." << endl;
        }
    }
    srand((unsigned)time(NULL));
    TEMPORARY_ID_NUMBER = 1 + (rand());

    cin.ignore();
}

void OnlineForm::display() const
{
    cout << "Name: " << name << endl
         << "Date of Birth: " << DOB << endl
         << "Age: " << age << endl
         << "NID: " << NID << endl;
}

bool OnlineForm::isValidDOB(const string &dob) const
{
    regex pattern(R"(^\d{2}/\d{2}/\d{4}$)");
    return regex_match(dob, pattern);
}

void OnlineForm::saveToFile() const
{
    ofstream outFile("oopProject/form_details.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << name << endl
                << DOB << endl
                << age << endl
                << NID << endl
                << TEMPORARY_ID_NUMBER << endl
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
    ifstream inFile("oopProject/form_details.txt");
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

int OnlineForm::nidCheck(int idNo) const
{
    ifstream file("oopProject/form_details.txt");
    if (file.fail())
    {
        cout << "File failed to open." << endl;
        return 1;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        int num;
        if (ss >> num && num == idNo)
        {
            file.close();
            return 1;
        }
    }
    file.close();
    return 0;
}


void OnlineForm::id_display()const{
    cout<<"Your token number is: "<<TEMPORARY_ID_NUMBER<<endl;
}