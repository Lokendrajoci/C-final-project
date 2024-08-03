#ifndef LICENSERENEWAL_HPP
#define LICENSERENEWAL_HPP

#include <string>

using namespace std;

struct LicenseDetails {
    string licenseNumber;
    string name;
    string dateOfBirth;
    string age;          // Kept as string for consistency
    string nationalID;   // Kept as string for consistency
    string renewalDate;

    void displayDetails() const;
    void inputRenewalDate();
};

bool findLicenseByLicenseNumber(const string &licenseNumber, LicenseDetails &details);
void updateLicenseDetails(const LicenseDetails &details);
void renewLicense();

#endif // LICENSERENEWAL_HPP
