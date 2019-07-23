#pragma once
#include "window.h"
#include "boxes.h"

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
        sf::CircleShape circle;


};

