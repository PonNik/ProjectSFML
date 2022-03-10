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
	// �������� ������
	void createCircle(float R, sf::RenderWindow& window);
	// �������� ��������
	void createRectangle(float width, float height, sf::RenderWindow& window);
	// �������� ���������� ���������������
	void createPolygon(float R, int angle, sf::RenderWindow& window);
	
	// �������� ������
	void deleteCircle();
	// �������� ��������
	void deleteRectangle();
	// �������� ���������� ���������������
	void deletePolygon();

	// �������� �� ������ 
	void sellectedShape(sf::RenderWindow& window);
	
	// ��������� �����
	void draw(sf::RenderWindow& window);
};

