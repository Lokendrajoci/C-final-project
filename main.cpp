#include <iostream>
#include "OnlineForm.h"
#include <fstream>
#include <regex>
using namespace std;

int main()
{
    OnlineForm o1;
    o1.display();
    o1.saveToFile();

    cout << "\nReading from file:\n";
    o1.loadFromFile();

    return 0;
}
