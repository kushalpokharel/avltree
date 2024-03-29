#include "node.h"

extern sf::Font font;

node::node()
{
    static int num=-1;
    num++;
    tag=num;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(18);
    nodeshape.setRadius(25);
    nodeshape.setFillColor(sf::Color::Blue);
    nodeshape.setOutlineColor(sf::Color::Magenta);
    nodeshape.setOutlineThickness(5);
}

void node::Create(int x, int y)
{
    posx=x;
    posy=y;
    nodeshape.setPosition(x,y);
    text.setPosition(x+35,y+35);
    sf::FloatRect textRect = nodeshape.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
}

void node::Create(int x, int y, std::string a)
{
    nodeshape.setPosition(x,y);
    text.setPosition(x+52,y+35);
    sf::FloatRect textRect = nodeshape.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text.setString(a);
}

void node::setString(std::string str)
{
    st=str;
    text.setString(str);
}

sf::Vector2f node::getPosition()
{
    return nodeshape.getPosition();
}

void node::Render(sf::RenderWindow* l_window)
{
    l_window->draw(nodeshape);
    l_window->draw(text);
}

void node::highlight()
{
    nodeshape.setFillColor(sf::Color::Green);
    text.setFillColor(sf::Color::Red);
}

