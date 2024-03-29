#pragma once

#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window
{
  public:
	Window();
	Window(const std::string &title, const sf::Vector2u &size);
	~Window();

	void BeginDraw();
	void EndDraw();

	void Update();
	bool Active();

	bool IsDone();
	bool IsFullscreen();
	sf::RenderWindow *GetRenderWindow();
	sf::Vector2u GetWindowSize();
    void ToggleFullscreen();
    void Draw(sf::Drawable &l_drawable);
    bool m_isDone;
    void clears();

  private:
	void Setup(const std::string title, const sf::Vector2u &size);
	void Create();
	void Destroy();
	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
    bool m_isFullscreen;
	std::string s1;
	std::string s2;
	std::string s3;
};



