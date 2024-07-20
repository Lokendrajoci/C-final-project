#include "Exam.h"
#include <iostream>

Exam::Exam(const std::vector<Question>& q) : questions(q), score(0), passingScore(10) {}

void Exam::conductExam() {
    int userOption;
    for (const auto& q : questions) {
        std::cout << q.questionText << std::endl;
        for (size_t i = 0; i < q.options.size(); ++i) {
            std::cout << i + 1 << ". " << q.options[i] << std::endl;
        }
        std::cout << "Your answer: ";
        std::cin >> userOption;
        if (userOption == q.correctOption) {
            ++score;
        }
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