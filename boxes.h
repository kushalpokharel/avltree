#pragma once
#include <iostream>
#include "window.h"
#include <SFML/Graphics.hpp>
#include "avl.h"
using namespace std;

class  Box
{

public:
    Box();
    void Render(Window& l_window, std::string);
    bool IsPressed();
    //void event();
    sf::Vector2f getPosition();
    string event(Window& l_window,sf::Event );
    char type;
    void settype(int );

private:
    sf::RectangleShape rectangle;
    sf::Text text;
    bool isPressed;
    int tag;
    std::string s;
    sf::Text inside;
    Avl avl;
    string del;
};


