#include <iostream>
#include "Exam.h"
#include "Question.h"
#include "OnlineForm.h"
#include <fstream>
#include <regex>
#include <limits>
#include <cstdlib>
#include<vector>

using namespace std;

void options()
{
    cout << "Enter 1 for registration: ";
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
std::vector<Question> questions = {
    Question("What is the speed limit in a residential area?", {"30 km/h", "50 km/h", "60 km/h", "80 km/h"}, 1),
      Question("What should you do at a stop sign?", {"Stop completely", "Slow down", "Speed up", "Yield"}, 0),
      Question("What is the legal blood alcohol limit for drivers?", {"0.05%", "0.08%", "0.10%", "0.15%"}, 1),
      Question("When should you use your headlights?", {"At all times", "Only at night", "In bad weather", "In tunnels"}, 2),
      Question("What is the proper way to make a right turn?", {"Speed up", "Slow down", "Maintain speed", "Stop"}, 1),
      Question("What should you do if you see an emergency vehicle with lights on?", {"Speed up", "Slow down", "Pull over to the right", "Continue driving"}, 2),
      Question("What is the correct tire pressure for a car?", {"20 psi", "30 psi", "40 psi", "50 psi"}, 1),
      Question("How often should you change your car's oil?", {"Every 3 months", "Every 6 months", "Every year", "Every 2 years"}, 0),
      Question("What is the best way to handle a wet road?", {"Speed up", "Slow down", "Maintain speed", "Stop"}, 1),
      Question("What should you do if you have a flat tire while driving?", {"Stop immediately", "Continue driving", "Speed up", "Signal and pull over safely"}, 3),
      Question("What should you check before every drive?", {"Oil level", "Tire pressure", "Brakes", "All of the above"}, 3),
      Question("What is the safe following distance?", {"1 second", "2 seconds", "3 seconds", "4 seconds"}, 2),
      Question("When should you use your horn?", {"At all times", "Only in emergencies", "When passing another vehicle", "When you see a pedestrian"}, 1),
      Question("What should you do if you encounter a pothole?", {"Speed up", "Slow down", "Maintain speed", "Swerve around it"}, 1),
      Question("What is the best way to handle a curve?", {"Speed up", "Slow down", "Maintain speed", "Stop"}, 1)
    };
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
        case 2:{
            Exam bikeExam(questions);

            bikeExam.conductExam();

            bikeExam.displayResult();
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
