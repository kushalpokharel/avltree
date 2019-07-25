#include "game.h"
//#include "boxes.h"

Game::Game()
{
    static int tag=-1;
    circle.setRadius(10);
    circle.setPosition(10,10);
    circle.setFillColor(sf::Color::Cyan);
    nodetag=tag;
    ins.settype(1);
    del.settype(2);
    serch.settype(3);
}

void Game::run()
{
        processevents();
        update();
        render();
}

Window *Game::GetWindow() { return &m_window; }

void Game::processevents()
{
    sf::Event event;
    string c,d,e;
   while( m_window.GetRenderWindow()->pollEvent(event))
   {

      c=ins.event( m_window,event);
      if(c!="")
        avl.add(c);
      d=del.event( m_window,event);
      if(d!="")
        avl.del(d);
      e=serch.event( m_window,event);
      if(e!="")
        cout<<"well..";
   }
}
void Game::update()
{
   // m_window.Update();
}

void Game::render()
{
//    int i;
    m_window.BeginDraw();
    m_window.Draw(circle);
    ins.Render(m_window,"Insert");
    del.Render(m_window,"Delete");
    serch.Render(m_window,"Search");
   /* for(i=0;i<15;i++)
    {
        nodes[i].Render(*(m_window.GetRenderWindow()));
    }*/
    m_window.EndDraw();
}

