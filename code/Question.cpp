//
// Created by maxim on 27.10.20.
//

#include "Question.h"


    void Question::set(string question_, string right_answer_, vector<string> ans_) {
        ans = ans_;
        right_answer = right_answer_;
        question = question_;

    }

    bool Question::check(int n) {
        return ans[n - 1] == right_answer;
    }
