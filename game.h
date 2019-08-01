#pragma once
#include "window.h"
#include "boxes.h"
#include "node.h"
#include "avl.h"
#include<iostream>

class Game
{
    public:
        Game();
        void run();
        Window *GetWindow();
        Box ins;
        Box del;
        Box serch;


    private:
        void processevents();
        void update();
        void render();
        Window m_window;
        //sf::CircleShape circle;
        int nodetag;
        Avl avl;
};

