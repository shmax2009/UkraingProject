//
// Created by maxim on 27.10.20.
//
#include "Testing_system.h"

void Testing_system::Test(RenderWindow &window, string path) {
    ifstream file(path);
    string line;
    vector<string> input_strings;
    while (getline(file, line)) {
        input_strings.push_back(line);
    }
    vector<Question> question_;
    for (int i = 0; i < input_strings.size(); ++i) {
        Question asd;
        string right_answer;
        vector<string> ans;
        string question;
        int index = 0;
        for (int j = index; j < input_strings[i].size(); ++j) {
            if (input_strings[i][j] == '"') {
                index = j;
                break;
            } else {
                question += input_strings[i][j];
            }

        }
        index++;
        for (int j = index; j < input_strings[i].size(); ++j) {
            if (input_strings[i][j] == '"') {
                index = j;

                break;
            } else {
                right_answer += input_strings[i][j];
            }

        }
        index++;

        string itgh;
        for (int j = index; j < input_strings[i].size(); ++j) {
            if (input_strings[i][j] == '"') {
                ans.push_back(itgh);
                itgh = "";
                break;
            } else {

                if (input_strings[i][j] == ',') {
                    ans.push_back(itgh);
                    j++;
                    itgh = "";
                }
                itgh += input_strings[i][j];

            }

        }
        asd.set(question, right_answer, ans);
        question_.push_back(asd);
    }

    Font font;
    font.loadFromFile("/home/maxim/CLionProjects/Testing/resources/arial.ttf");
    Text question_text;
    question_text.setFont(font);
    question_text.setString(question_[0].question);
    question_text.setPosition(450, 450);

    Text answer_text1;
    answer_text1.setFont(font);
    answer_text1.setString(question_[0].ans[0]);
    answer_text1.setPosition(0, 650);

    Text answer_text2;
    answer_text2.setFont(font);
    answer_text2.setString(question_[0].ans[1]);
    answer_text2.setPosition(980 - (question_[0].ans[1].size() - 1) * 14, 650);
    Text checking;
    checking.setFont(font);
    checking.setPosition(0, 0);
    int iterator = 0;

    while (window.isOpen()) {
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Right) {

                    if (checking.getString() != "") {
                        iterator++;
                        if(iterator >= question_.size())
                            return;
                        question_text.setString(question_[iterator].question);
                        answer_text1.setString(question_[iterator].ans[0]);
                        answer_text2.setString(question_[iterator].ans[1]);
                        answer_text2.setPosition(980 - (question_[iterator].ans[1].size() - 1) * 14, 650);
                        checking.setString("");
                    }
                }

                if (event.key.code == Keyboard::Escape) {
                    string add = "..";
//                    cin >> add;

                    path += '/' + add;
                }

            }
            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Button::Left) {
                    if (localPosition.y < 680 && localPosition.y > 640) {
                        if (localPosition.x < 500) {
//                            cout << question_[0].check(1) << endl;
                            if (question_[0].check(1))
                                checking.setString("RIGHT");
                            else
                                checking.setString("WRONG");

                        }
                        if (localPosition.x > 500) {
                            if (question_[0].check(2))
                                checking.setString("RIGHT");
                            else
                                checking.setString("WRONG");
                        }
                    }
                }
            }
        }
        if (localPosition.y < 680 && localPosition.y > 640) {
            if (localPosition.x < 500) {
                answer_text1.setFillColor(Color::Green);
                answer_text2.setFillColor(Color::White);

            } else if (localPosition.x > 500) {
                answer_text1.setFillColor(Color::White);
                answer_text2.setFillColor(Color::Green);
            }
        } else {
            answer_text1.setFillColor(Color::White);
            answer_text2.setFillColor(Color::White);

        }

        window.clear();
//        if (b == true)
        window.draw(checking);
        window.draw(question_text);
        window.draw(answer_text1);
        window.draw(answer_text2);
        window.display();
    }
    return;
}