#include <SFML/Graphics.hpp>
#pragma once

class GameEngine
{
	sf::RenderWindow window;
	sf::Event event;
	float want_fps = 50.0f;

	int sellectShape = 1;

	// Временно

	int r = 50;
	std::vector<sf::CircleShape> cS;
	std::vector<sf::RectangleShape> rS;
	sf::Color col = sf::Color::Green;

	sf::Font font;
	sf::Text text;

	int width = 100;
	int height = 100;
public:
	void start();
	void update();
	void input();
	void draw();

	// Временно 
	// Создание кругов
	sf::CircleShape createCircle(float R, sf::Color color, sf::RenderWindow& window);
	// Создание квадрата
	sf::RectangleShape createRectangle(float width, float height, sf::Color color, sf::RenderWindow& window);
};

