#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

struct node
{
   public:
       node();
       void Create(int ,int );
       void Create(int ,int ,std::string);
       sf::Vector2f getPosition();
       void Render (sf::RenderWindow* l_window);
       int nodenumber;
       void setString(std::string str);
       int data;
       struct node* left;
       struct node* right;
       void highlight();
       int posx;
       int posy;
       std::string st;

   private:
        sf::Vector2f m_position;
        sf::CircleShape nodeshape;
        sf::Text text;
        int tag;
};
