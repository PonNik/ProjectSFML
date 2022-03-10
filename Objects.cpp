#include "Objects.h"

// Создание кругов
void Objects::createCircle(float R, sf::RenderWindow& window) {
	color = (sf::Color(rand() % 255, rand() % 255, rand() % 255));
	// Создание круга с радиусом R
	sf::CircleShape s(R);
	// Координаты переносятся в середину круга
	s.setOrigin(R, R);
	// Заливка круга зеленым цветом
	s.setFillColor(color);
	// Задается позиция середины круга в координаты мыши
	s.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	cS.push_back(s);
}

// Создание правильных многоугольников
void Objects::createPolygon(float R, int angle, sf::RenderWindow& window) {
	color = (sf::Color(rand() % 255, rand() % 255, rand() % 255));
	// Создание круга с радиусом R
	sf::CircleShape s(R, angle);
	// Координаты переносятся в середину круга
	s.setOrigin(R, R);
	// Заливка круга зеленым цветом
	s.setFillColor(color);
	// Задается позиция середины круга в координаты мыши
	s.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	tS.push_back(s);
}

// Создание прямоугольников
void Objects::createRectangle(float width, float height, sf::RenderWindow& window) {
	color = (sf::Color(rand() % 255, rand() % 255, rand() % 255));
	sf::Vector2f vecRect(width, height);
	// Создание круга с радиусом R
	sf::RectangleShape s(vecRect);
	// Координаты переносятся в середину круга
	s.setOrigin(width / 2, height / 2);
	// Заливка круга зеленым цветом
	s.setFillColor(color);
	// Задается позиция середины круга в координаты мыши
	s.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	rS.push_back(s);
}

// Удаление кругов
void Objects::deleteCircle() {
	cS.clear();
}

// Удаление квадрата
void Objects::deleteRectangle() {
	rS.clear();
}

// Удаление правильных многоугольников
void Objects::deletePolygon() {
	tS.clear();
}

void Objects::sellectedShape(sf::RenderWindow& window) {
	for (int i = 0; i < cS.size(); i++) {
		// Удаление круга из массива
		if (cS[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			if (sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					// удаление элемента массива 
					std::vector<sf::CircleShape>::iterator it1 = cS.begin() + i;
					cS.erase(it1);
				}
			}
		}
	}
	for (int i = 0; i < rS.size(); i++) {
		// Удаление круга из массива
		if (rS[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			if (sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					// удаление элемента массива 
					std::vector<sf::RectangleShape>::iterator it1 = rS.begin() + i;
					rS.erase(it1);
				}
			}
		}
	}
	for (int i = 0; i < tS.size(); i++) {
		// Удаление круга из массива
		if (tS[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			if (sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					// удаление элемента массива 
					std::vector<sf::CircleShape>::iterator it1 = tS.begin() + i;
					tS.erase(it1);
				}
			}
		}
	}
}

// Отрисовка фигур
void Objects::draw(sf::RenderWindow& window) {
	// рисование и изменение кругов
	for (int i = 0; i < cS.size(); i++) {
		// Отрисовка каждого круга в массиве
		window.draw(cS[i]);
	}
	for (int i = 0; i < rS.size(); i++) {
		// Отрисовка каждого прямоугольника в массиве
		window.draw(rS[i]);
	}
	for (int i = 0; i < tS.size(); i++) {
		// Отрисовка каждого правильного многоугольника в массиве
		window.draw(tS[i]);
	}
}