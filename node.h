#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Node
{
   public:
       Node();
       void Create(int ,int );
       sf::Vector2f getPosition();
       void Render (sf::RenderWindow& l_window);
       int nodenumber;
       void setString(std::string str);

   private:
        sf::Vector2f m_position;
        sf::CircleShape nodeshape;
        sf::Text text;
        int tag;

};
