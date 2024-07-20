#include "Question.h"

Question::Question(const std::string& q, const std::vector<std::string>& opts, int correct)
    : questionText(q), options(opts), correctOption(correct) {}

