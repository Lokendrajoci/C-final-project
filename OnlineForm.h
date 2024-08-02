#ifndef ONLINEFORM_H
#define ONLINEFORM_H

#include <string>
using namespace std;

class OnlineForm
{
private:
    std::string name, DOB;
    int age, NID,TEMPORARY_ID_NUMBER;

public:
    OnlineForm();
    void display() const;
    bool isValidDOB(const string& dob) const;
    void saveToFile() const;
    void loadFromFile() const;
    int nidCheck(int NID) const;
};

#endif 