#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include "Testing_system.h"
#include <cmath>

using namespace std;
using namespace sf;
namespace fs = std::filesystem;

String to_rusian(string stri) {
    return sf::String::fromUtf8(begin(stri), end(stri));
}

class Drawing {
public:
    void Draw(std::vector<string> files, RenderWindow &window, int each);
};

void Drawing::Draw(std::vector<string> files, RenderWindow &window, int each) {
    for (int i = 0; i < files.size(); ++i) {
        Font font;
        font.loadFromFile("/home/maxim/CLionProjects/Testing/resources/arial.ttf");
        Text text;
        string res = "";
        for (int j = files[i].length() - 1; j > 0; --j) {
            if (files[i][j] != '/') {
                res = files[i][j] + res;
            } else {
                break;
            }
        }
        if (i == each)
            text.setFillColor(Color::Yellow);
        string f = "";
        for (int j = res.size() - 1; j > 0; --j) {
            if (res[j] == '.')
                break;
            f = res[j] + f;


        }
//        cout<<f<<endl;
        if (f == "task")
            text.setFillColor(Color::Green);

        text.setFont(font);
        text.setPosition(0, 30 * i);
        text.setString(to_rusian(res));
        window.draw(text);
    }
}

int main() {
    vector<string> files;
    Testing_system testingSystem;
    string path = "/";
    RenderWindow window(VideoMode(1000, 1000), "test");
    Drawing drawing;
    View view(sf::FloatRect(0, 0, 1000.f, 1000.f));
    double addedeble = 0;
    while (window.isOpen()) {
        sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a sf::Window
        files.clear();
        for (const auto &entry : fs::directory_iterator(path))
            files.push_back(entry.path());
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    view.move(0, -10);
                    addedeble -= 10;
                }
                if (event.key.code == Keyboard::Down) {
                    view.move(0, 10);
                    addedeble += 10;

                }
                if (event.key.code == Keyboard::Escape) {
                    string add = "..";
//                    cin >> add;
                    cout << add << endl;

                    path += '/' + add;
                }

            }
            if (event.type == sf::Event::MouseWheelMoved) {
                view.move(0, event.mouseWheel.delta * 10);

                addedeble += 10 * event.mouseWheel.delta;

            }

            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Button::Left) {
                    string add = files[round(addedeble / 30 + (localPosition.y) / 30)];
//                    cout << add << endl;
//                    cin >> add;
                    string f = "";
                    for (int j = add.size() - 1; j > 0; --j) {
                        if (add[j] == '.')
                            break;
                        f = add[j] + f;


                    }
                    if(f == "task")
                    {
                        testingSystem.Test(window,add);
                    }
                    else
                    path = add;

                }
            }
        }
        window.clear();
        window.setView(view);
        drawing.Draw(files, window, round(addedeble / 30 + (localPosition.y) / 30));
        window.display();
    }
}


