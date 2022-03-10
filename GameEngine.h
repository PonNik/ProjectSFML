#pragma once
#include <SFML/Graphics.hpp>
#include "Objects.h"

class GameEngine
{
	sf::RenderWindow window;
	sf::Event event;
	float want_fps = 50.0f;

	// Выбранная фигура
	int sellectShape = 1;
	int angle = 3;

	Objects objects;

	int r = 50;

	sf::Font font;
	sf::Text text;
	sf::Text sellShapeText;

	int width = 100;
	int height = 100;
public:
	void start();
	void update();
	void input();
	void draw();
};

