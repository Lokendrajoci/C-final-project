#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
public:
    std::string questionText;
    std::vector<std::string> options;
    int correctOption;

    Question(const std::string& q, const std::vector<std::string>& opts, int correct);

    // Static method to get a list of questions
    static std::vector<Question> getQuestions();
};

#endif
