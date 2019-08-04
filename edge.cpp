#include "edge.h"
#include "window.h"
#include <math.h>

edge::edge()
{
    line.setFillColor(sf::Color::Red);
}

void edge::create(sf::Vector2f pos1, sf::Vector2f pos2)
{
    float dy=pos2.y-pos1.y;
    float dx=(pos2.x-pos1.x);
    length=pow(dy,2)+pow(dx,2);
    length=sqrt(length);
    rotation=atan2(dy,dx)*180/3.142;
    line.setSize(sf::Vector2f(length-50,2));
    line.setOrigin({line.getSize().x/2, line.getSize().y/2});
    line.setPosition((pos1.x+pos2.x)/2+25,(pos1.y+pos2.y)/2+20);
    line.setRotation(rotation);
}

void edge:: render(Window &l_wind)
{
    l_wind.Draw(line);
}
