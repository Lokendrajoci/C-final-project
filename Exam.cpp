#include "Exam.h"
#include <iostream>
#include <cstdlib>  // For system()
#include <limits> // Add this line to include numeric_limits

Exam::Exam(const std::vector<Question>& q) : questions(q), score(0), passingScore(10) {}

void Exam::conductExam() {
    int userOption;
    for (size_t i = 0; i < questions.size(); ++i) {
        // Clear screen based on operating system
        #ifdef _WIN32
            system("cls");  // For Windows
        #endif

        std::cout << questions[i].questionText << std::endl;
        for (size_t j = 0; j < questions[i].options.size(); ++j) {
            std::cout << j + 1 << ". " << questions[i].options[j] << std::endl;
        }
        std::cout << "Your answer (1-4): ";
        std::cin >> userOption;

        // Use a while loop to repeat the question until a valid input is entered
        while (std::cin.fail() || userOption < 1 || userOption > questions[i].options.size()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option. Please enter a number between 1 and " << questions[i].options.size() << "." << std::endl;
            std::cout << "Your answer (1-4): ";
            std::cin >> userOption;
        }

        if (userOption - 1 == questions[i].correctOption) {
            ++score;
        }

     
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Wait for Enter key
    }
}

void Exam::displayResult() {
    std::cout << "Your score: " << score << "/" << questions.size() << std::endl;
    if (score >= passingScore) {
        std::cout << "Congratulations! You passed the exam." << std::endl;
    } else {
        std::cout << "Sorry, you failed the exam. See you next time." << std::endl;
    }
}
