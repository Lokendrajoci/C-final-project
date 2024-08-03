#include <iostream>
#include "Exam.h"
#include "Question.h"
#include "OnlineForm.h"
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

void options()
{
    cout << "Enter 1 for registration: " << endl;
    cout << "Enter 2 for LICENSE Exam" << endl;
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
            o1.loadFromFile();
            break;
        }
        case 2:
        {
            string userToken; 
            cout << "Enter your token number: ";
            cin >> userToken; 
            // Open the file for reading
            ifstream file("form_details.txt"); 
            if (file.is_open()) {
                string line;
                // Read each line in the file
                while (getline(file, line)) {
                    // Extract the token number from the line
                    stringstream ss(line);
                    string tokenNumber; 
                    getline(ss, tokenNumber, ' '); // Assuming token number is the first item on the line
                    // Compare the token numbers
                    if (tokenNumber == userToken) {
                        cout << "Token number verified! You can proceed with the exam." << endl;
                        Exam bikeExam(Question::getQuestions());
                        bikeExam.conductExam();
                        bikeExam.displayResult();
                        file.close(); // Close the file
                    }
                    // else { 
                    //     std::cout << "Token number is invalid. Please register first." << std::endl;

                    // }
                    
                }
                // If we reach here, the token number wasn't found
                if (file.is_open()) { // Check if the file is still open
                    file.close(); // Close the file if it's open
                }
            
            }
            std::cout << "Token number is invalid. Please register first." << std::endl;
            break;
        }
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Optionally exit after each valid action or allow the user to choose another option
        cout << "Press Enter to return to the main menu...";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
