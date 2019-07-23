#include "boxes.h"
#include<iostream>
#include <SFML/Graphics.hpp>

extern sf::Font font;

Box::Box()
{
    isPressed=false;
    static int num=-1;
    num++;
    tag=num;
    s="";
    std::cout<<num;
    rectangle.setSize(sf::Vector2f(60,25));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(3);
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    inside.setFont(font);
    inside.setCharacterSize(18);
    inside.setFillColor(sf::Color::Blue);
}

void Box::event(Window& l_window)
{
/*    sf::IntRect rect (rectangle.getPosition().x,rectangle.getPosition().y,rectangle.getGlobalBounds().width,rectangle.getGlobalBounds().height);
    if(rectangle.getGlobalBounds().contains(sf::Mouse::getPosition())&&(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
        isPressed = true;
        std::cout<<"here";
    }*/

   sf::Vector2f Mouse = (l_window.GetRenderWindow())->mapPixelToCoords(sf::Mouse::getPosition(*(l_window.GetRenderWindow())));
    //std::cout << "Mouse.x = " << Mouse.x << ", Mouse.y = " << Mouse.y << std::endl;

    if (rectangle.getGlobalBounds().contains(Mouse)&&(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
           // std::cout << "COLLISION!" << std::endl;
            isPressed=true;
    }
    if(isPressed && sf::Keyboard::isKeyPressed (sf::Keyboard::Return))
    {
            isPressed=false;
            s="";
    }
	sf::Event event;
	while(l_window.GetRenderWindow()->pollEvent(event))
    {
		if(event.type == sf::Event::Closed)
        {
            l_window.GetRenderWindow()->close();
            l_window.m_isDone=true;
        }
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
             l_window.GetRenderWindow()->close();
             l_window.m_isDone=true;
        }
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Comma)
        {
            l_window.ToggleFullscreen();
        }
        else if(isPressed && event.type == sf::Event::TextEntered)
        {
            cout<<"lol";
            s+=event.text.unicode;
        }
    }
}

sf::Vector2f Box:: getPosition()
{
    return rectangle.getPosition();
}

void Box::Render(Window& l_window,std::string str)
{

    if(isPressed)
        rectangle.setFillColor(sf::Color::Cyan);
    else
        rectangle.setFillColor(sf::Color::White);

    rectangle.setPosition(700+200*tag,10);

    text.setPosition(rectangle.getPosition().x+65,rectangle.getPosition().y);
    text.setString(str);

    std::cout<<s;
    inside.setPosition(rectangle.getPosition().x,rectangle.getPosition().y);
    inside.setString(s);
    l_window.Draw(text);
    l_window.Draw(rectangle);
    l_window.Draw(inside);

}

bool Box:: IsPressed()
{
    return isPressed;
}

