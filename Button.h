#pragma once
#include "SFML/Graphics.hpp"

class Button
{
private:
	sf::Vector2f size;
	sf::Vector2f position;
	bool press = false;
public:
	sf::RectangleShape rect;
	sf::Color color;
	Button(sf::Vector2f bSize, sf::Vector2f bPos, sf::Color col, sf::RenderWindow& window) {
		size = bSize;
		position = bPos;
		color = col;
		rect.setFillColor(color);
		rect.setPosition(position);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(rect);
	}

};

