#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <vector>
#include <string>
#include "json.hpp"

class Quiz {
public:
    Quiz(const std::string& filename); // Constructor to initialize the quiz with questions
    void start(); // Starts the quiz
    int getScore() const; // Returns the current score
    void printRandomSixDigitNumber() const; // Prints a random 6-digit number
    void writeDetailsToFile(int randomNumber) const; // Writes details to a file

private:
    class Question {
    public:
        std::string qName; // Question text
        int qNum; // Question number
        std::string aName, bName, cName, dName; // Answer options
        std::string ansNum; // Correct answer
    };

    void loadQuestions(const std::string& filename); // Loads questions from a JSON file
    void printQuestion(const Question& q, std::string& userChoice); // Prints a question and checks the answer
    bool isValidToken(const std::string& token) const; // Validates the token
    void readTokenFromFile(const std::string& tokenFile); // Reads tokens from a file
    void printAllQuestions() const; // Prints all questions

    std::vector<Question> qSet; // List of questions
    int score; // User's score
    std::vector<std::string> tokens; // Store all tokens
};

#endif // QUIZ_H
