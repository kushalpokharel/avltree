#include "node.h"

extern sf::Font font;

Node::Node()
{
    static int num=-1;
    num++;
    tag=num;
    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(10);
    nodeshape.setRadius(5);
    nodeshape.setFillColor(sf::Color::Green);
}

void Node::Create(int x, int y)
{
    nodeshape.setPosition(x,y);
    text.setPosition(x,y);
}

void Node::setString(std::string str)
{
    text.setString(str);
}

sf::Vector2f Node::getPosition()
{
    return nodeshape.getPosition();
}

void Node:: Render(sf::RenderWindow &l_window)
{
    l_window.draw(nodeshape);
    l_window.draw(text);
}



