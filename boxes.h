#pragma once
#include<iostream>
#include "window.h"
#include <SFML/Graphics.hpp>
using namespace std;

class  Box
{
public:
    Box( );
    void Render(Window& l_window, std::string);
    bool IsPressed();
    //void event();
    sf::Vector2f getPosition();
    void event(Window& l_window);

private:
    sf::RectangleShape rectangle;
    sf::Text text;
    bool isPressed;
    int tag;
    std::string s;
    sf::Text inside;

};


