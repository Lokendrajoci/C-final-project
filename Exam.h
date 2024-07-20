#ifndef EXAM_H
#define EXAM_H

#include "Question.h"
#include <vector>

class Exam {
private:
    std::vector<Question> questions;
    int score;
    int passingScore;

public:
    Exam(const std::vector<Question>& q);
    void conductExam();
    void displayResult();
};

#endif
