//
// Created by maxim on 27.10.20.
//

#ifndef TESTING_QUESTION_H
#define TESTING_QUESTION_H
#include <string>
#include <vector>
using namespace std;
class Question {
public:
    vector<string> ans;
    string question;
    string right_answer;
    void set(string question_, string right_answer_, vector<string> ans_);
    bool check(int n);
//    void draw();
};


#endif //TESTING_QUESTION_H
