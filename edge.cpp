#include "edge.h"
#include "window.h"
#include <math.h>

edge::edge()
{
    line.setFillColor(sf::Color::Red);
    line.setSize(sf::Vector2f(45,2));
}

void edge::create(sf::Vector2f pos1, sf::Vector2f pos2)
{
    float dy=pos2.y-pos1.y;
    float dx=(pos2.x-pos1.x);
    rotation=atan2(dy,dx)*180/3.142;
    line.setOrigin({line.getSize().x/2, line.getSize().y/2});
    line.setPosition((pos1.x+pos2.x)/2+25,(pos1.y+pos2.y)/2+18);
    line.setRotation(rotation);
}

void edge:: render(Window &l_wind)
{
    l_wind.Draw(line);
}
