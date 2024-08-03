#include "LicenseRenewal.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>

using namespace std;

// Function to display the license details
void LicenseDetails::displayDetails() const {
    cout << "License Number: " << licenseNumber << "\n";
    cout << "Name: " << name << "\n";
    cout << "Date of Birth: " << dateOfBirth << "\n";
    cout << "Age: " << age << "\n";
    cout << "National ID: " << nationalID << "\n";
    cout << "Renewal Date: " << renewalDate << "\n";
}

// Function to input the new renewal date
void LicenseDetails::inputRenewalDate() {
    cout << "Enter new Renewal Date (YYYY-MM-DD): ";
    cin >> renewalDate;
}

// Function to find a license by License Number and read details
bool findLicenseByLicenseNumber(const string &licenseNumber, LicenseDetails &details) {
    ifstream file("output_details.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find("Your license number is: " + licenseNumber) != string::npos || 
            line.find("Random 6-digit number: " + licenseNumber) != string::npos) {
            details.licenseNumber = licenseNumber;

            for (int i = 0; i < 5; ++i) {
                getline(file, line); // Reading each line for details
                size_t pos = line.find(": ");
                string value = line.substr(pos + 2);

                switch (i) {
                    case 0: details.name = value; break;
                    case 1: details.dateOfBirth = value; break;
                    case 2: details.age = value; break;
                    case 3: details.nationalID = value; break;
                    case 4: details.renewalDate = value; break;
                }
            }
            found = true;
            break;
        }
    }

    file.close();
    return found;
}

// Function to update the license details in the file
void updateLicenseDetails(const LicenseDetails &details) {
    ifstream file("output_details.txt");
    stringstream buffer;
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find("Your license number is: " + details.licenseNumber) != string::npos || 
            line.find("Random 6-digit number: " + details.licenseNumber) != string::npos) {
            // Skip the current block to replace it with new data
            for (int i = 0; i < 6; ++i) getline(file, line);

            // Write the updated details to the buffer
            buffer << "Random 6-digit number: " << details.licenseNumber << "\n";
            buffer << "Name: " << details.name << "\n";
            buffer << "Date of Birth: " << details.dateOfBirth << "\n";
            buffer << "Age: " << details.age << "\n";
            buffer << "National ID: " << details.nationalID << "\n";
            buffer << "Renewal Date: " << details.renewalDate << "\n";
            buffer << "------------------------\n";
            found = true;
        } else {
            buffer << line << "\n";
        }
    }

    file.close();

    if (found) {
        ofstream outFile("output_details.txt");
        outFile << buffer.str();
        outFile.close();
        cout << "License details updated successfully!\n";
    } else {
        cout << "Error: License details not found for update.\n";
    }
}

// Function to renew a license
void renewLicense() {
    string licenseNumber;
    LicenseDetails details;

    cout << "Enter License Number for renewal: ";
    cin >> licenseNumber;

    if (findLicenseByLicenseNumber(licenseNumber, details)) {
        cout << "License found:\n";
        details.displayDetails();

        // Ask for payment
        double paymentAmount;
        cout << "Enter payment amount in Rs: ";
        while (!(cin >> paymentAmount) || paymentAmount < 0) {
            cout << "Invalid input. Please enter a positive number for payment: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Processing payment of Rs " << paymentAmount << "...\n";
        cout << "Payment successful.\n";

        // Update the renewal date
        details.inputRenewalDate();

        // Update the license details in the file
        updateLicenseDetails(details);
    } else {
        cout << "No license found for the given License Number.\n";
    }
}
