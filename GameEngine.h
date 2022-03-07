#include <SFML/Graphics.hpp>
#pragma once

class GameEngine
{
	sf::RenderWindow window;
	sf::Event event;
	float want_fps = 50.0f;

	// ��������

	int r = 50;
	std::vector<sf::CircleShape> cS;
	sf::Color col = sf::Color::Green;
public:
	void start();
	void update();
	void input();
	void draw();

	// �������� 
	// �������� ������
	sf::CircleShape createShape(float R, sf::Color color, sf::RenderWindow& window);
};

