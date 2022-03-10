#pragma once
#include "SFML/Graphics.hpp"

class Objects
{
private:
	std::vector<sf::CircleShape> cS;
	std::vector<sf::RectangleShape> rS;
	std::vector<sf::CircleShape> tS;
	sf::Color color;
public:
	// Создание кругов
	void createCircle(float R, sf::RenderWindow& window);
	// Создание квадрата
	void createRectangle(float width, float height, sf::RenderWindow& window);
	// Создание правильных многоугольников
	void createPolygon(float R, int angle, sf::RenderWindow& window);
	
	// Удаление кругов
	void deleteCircle();
	// Удаление квадрата
	void deleteRectangle();
	// Удаление правильных многоугольников
	void deletePolygon();

	// Выбранна ли фигура 
	void sellectedShape(sf::RenderWindow& window);
	
	// Отрисовка фигур
	void draw(sf::RenderWindow& window);
};

