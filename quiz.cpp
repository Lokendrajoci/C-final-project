#include "quiz.hpp"
#include "json.hpp" // Ensure you include the nlohmann json library
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <algorithm> // For std::find

#include <cstdlib>
#include <ctime>

Quiz::Quiz(const std::string &filename) : score(0)
{
    // Read tokens from form_details.txt
    readTokenFromFile("oopProject//form_details.txt");

    // Validate token input
    std::string userToken;
    std::cout << "Enter token: ";
    std::cin >> userToken;

    if (!isValidToken(userToken))
    {
        std::cerr << "Invalid token. Exiting application." << std::endl;
        exit(EXIT_FAILURE);
    }

    loadQuestions(filename);
}

void Quiz::readTokenFromFile(const std::string &tokenFile)
{
    std::ifstream file(tokenFile);
    if (!file.is_open())
    {
        std::cerr << "Failed to open token file: " << tokenFile << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    std::string currentToken;

    while (std::getline(file, line))
    {
        if (line == "------------------------")
        {
            if (!currentToken.empty())
            {
                tokens.push_back(currentToken); // Store each token
                currentToken.clear();           // Clear for next block
            }
        }
        else
        {
            currentToken = line; // Update currentToken
        }
    }

    // Handle the last token if not followed by a separator
    if (!currentToken.empty())
    {
        tokens.push_back(currentToken);
    }

    file.close();
}

bool Quiz::isValidToken(const std::string &token) const
{
    return std::find(tokens.begin(), tokens.end(), token) != tokens.end(); // Check all tokens
}

void Quiz::loadQuestions(const std::string &filename)
{
    std::ifstream jsonFileVar(filename); // Open the JSON file for reading
    if (!jsonFileVar.is_open())
    {
        std::cerr << "Failed to open JSON file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    // Parse the JSON data
    std::stringstream s;
    s << jsonFileVar.rdbuf();
    std::string data = s.str();
    jsonFileVar.close();

    nlohmann::json qData;
    try
    {
        qData = nlohmann::json::parse(data);
    }
    catch (const nlohmann::json::parse_error &e)
    {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Extract questions from JSON
    int qCount = qData["number of questions"];
    if (qCount <= 0)
    {
        std::cerr << "No questions found in JSON file." << std::endl;
        exit(EXIT_FAILURE);
    }

    qSet.resize(qCount);

    int z = 0;
    for (int i = 0; i < qCount; i++)
    {
        // Ensure enough data for each question
        if (z + 6 > qData["questions"].size())
        {
            std::cerr << "Insufficient data for question " << i + 1 << std::endl;
            exit(EXIT_FAILURE);
        }

        qSet[i].qNum = i + 1;
        qSet[i].qName = qData["questions"][z];
        qSet[i].aName = qData["questions"][z + 1];
        qSet[i].bName = qData["questions"][z + 2];
        qSet[i].cName = qData["questions"][z + 3];
        qSet[i].dName = qData["questions"][z + 4];
        qSet[i].ansNum = qData["questions"][z + 5];
        z += 6;
    }
}

void Quiz::printQuestion(const Question &q, std::string &userChoice)
{
    std::cout << "Q" << q.qNum << ") " << q.qName << std::endl;
    std::cout << "A) " << q.aName << std::endl;
    std::cout << "B) " << q.bName << std::endl;
    std::cout << "C) " << q.cName << std::endl;
    std::cout << "D) " << q.dName << std::endl;
    std::cout << "Your answer (A-D): ";
    std::cin >> userChoice;
    if (userChoice == q.ansNum)
    {
        std::cout << "Correct!" << std::endl
                  << std::endl;
        score++;
    }
    else
    {
        std::cout << "Incorrect!" << std::endl
                  << std::endl;
    }
}

void Quiz::printRandomSixDigitNumber() const
{

    srand(time(0));

    int random_number = rand() % 900000 + 100000;
    std::cout << "\n\n\n\n\n\t\t\t\t!!!!!!!!!!!!!CONGRATULATIONS!!!!!!!!!!!!!\n\n\n\n\n"
              << std::endl;
    std::cout << "\t\t\t\tYour license number is: " << random_number << std::endl
              << std::endl
              << std::endl
              << std::endl;

    writeDetailsToFile(random_number);
}

void Quiz::writeDetailsToFile(int randomNumber) const
{
    std::ofstream outFile("oopProject//output_details.txt", std::ios::app);
    if (!outFile.is_open())
    {
        std::cerr << "Failed to open output file." << std::endl;
        return;
    }

    std::string name, dob, age, nid;
    std::cout << "Enter your name: ";
    std::cin.ignore(); // To clear the newline character from the buffer
    std::getline(std::cin, name);
    std::cout << "Enter your date of birth (dd/mm/yyyy): ";
    std::getline(std::cin, dob);
    std::cout << "Enter your age: ";
    std::getline(std::cin, age);
    std::cout << "Enter your national ID: ";
    std::getline(std::cin, nid);

    outFile << "Your license number is: " << randomNumber << std::endl;
    outFile << "Name: " << name << std::endl;
    outFile << "Date of Birth: " << dob << std::endl;
    outFile << "Age: " << age << std::endl;
    outFile << "National ID: " << nid << std::endl;
    outFile << "------------------------" << std::endl;

    outFile.close();
}

int Quiz::getScore() const { return score; }

void Quiz::start()
{
    std::string userChoice;
    std::cout << std::endl
              << std::endl
              << std::endl
              << std::endl
              << std::endl
              << std::endl
              << std::endl;
    std::cout << "\t\t\t\t\tWelcome to QUIZ" << std::endl
              << std::endl
              << std::endl
              << std::endl;

    std::cout << "\t\t\t\t***********|KEY POINTS|***********" << std::endl;
    std::cout << "\t\t\t1. One marks will be alotted for each question." << std::endl;
    std::cout << "\t\t\t2. total numbers of question are 15." << std::endl;
    std::cout << "\t\t\t3. No electronics devices are allowded." << std::endl;
    std::cout << "\t\t\t4. Minimum 10 marks is required to secure liscense exam\n\n"
              << std::endl;

    for (const auto &q : qSet)
    {
        printQuestion(q, userChoice);
    }

    system("cls");
   
    std::cout << "Your total score is:"
              << score << std::endl;
    if (score > 10)
    {
        printRandomSixDigitNumber();
    }

    // std::cout << "Press enter to exit (if you are on a Windows machine)"
    //           << std::endl;
    // std::cin.ignore(); // Wait for user input before closing
    // std::cin.get();
}
