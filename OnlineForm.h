#ifndef ONLINEFORM_H
#define ONLINEFORM_H

#include <string>
using namespace std;

class OnlineForm
{
private:
    string name, DOB;
    int age, NID;

public:
    OnlineForm();
    void display() const;
    bool isValidDOB(const string& dob) const;
    void saveToFile() const;
    void loadFromFile() const;
};

#endif 
