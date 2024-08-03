#include <iostream>
#include "welcome.hpp"

void Initializing_Display() // This function contains the statements that show the information about the developers of the project.
{
    std::cout << "\nCpp Programming Project:\n\n"
              << "\t\t_________________________________________________________________________________\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t Project By:\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t*************\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t1. BIBEK POUDEL(PUR079BCT018)\t\t\t|\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t2. BIKASH CHAUDHARY(PUR079BCT019)\t\t|\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t3. INTAF MALIK(PUR079bct029)\t\t\t|\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t4. LOKENDRA JOSHI(PUR079bct036)\t\t\t|\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t| Faculty: Department of Electronics and Computer Engineering.\t\t\t|\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t| Semester: 3rd\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t| College: Purwanchal Campus.\t\t\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t| Enrolled Year : 2079 B.S.\t\t\t\t\t\t\t|\n"
              << "\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
              << "\t\t|_______________________________________________________________________________|\n\n";

    std::cout << "Press Enter to Continue...";
    std::cin.ignore(); // Waits for the user to press Enter
}
