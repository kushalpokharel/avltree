#include "game.h"
//#include "boxes.h"

Game::Game()
{
    circle.setRadius(10);
    circle.setPosition(10,10);
    circle.setFillColor(sf::Color::Cyan);
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
  ins.event( m_window);
  del.event( m_window);
  serch.event( m_window);
}
void Game::update()
{
   // m_window.Update();
}

void Game::render()
{
    m_window.BeginDraw();
    m_window.Draw(circle);
    ins.Render(m_window,"Insert");
    del.Render(m_window,"Delete");
    serch.Render(m_window,"Search");
    m_window.EndDraw();
}

