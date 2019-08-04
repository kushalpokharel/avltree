#pragma once
#include "window.h"
#include <SFML/Graphics.hpp>

class edge
{
public:
    edge();
    void create(sf::Vector2f , sf::Vector2f );
    void render(Window &l_wind);
public:
    sf::RectangleShape line;
    sf::Vector2f nodea;
    sf::Vector2f nodeb;
    int rotation;
    float length;
};
