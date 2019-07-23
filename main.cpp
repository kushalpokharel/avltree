#include <iostream>
//#include "window.h"
#include "game.h"

using namespace std;

sf::Font font;

int main()
{

    if (!font.loadFromFile("ariblk.ttf"))
    {
        std::cout << "Error!!!" << endl;
    }
    Game game;
    while(!game.GetWindow()->IsDone())
    {
        //cout<<"hello";
        game.run();
    }
        //Window m_wind;

}

