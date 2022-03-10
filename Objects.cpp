#include "Objects.h"

// �������� ������
void Objects::createCircle(float R, sf::RenderWindow& window) {
	color = (sf::Color(rand() % 255, rand() % 255, rand() % 255));
	// �������� ����� � �������� R
	sf::CircleShape s(R);
	// ���������� ����������� � �������� �����
	s.setOrigin(R, R);
	// ������� ����� ������� ������
	s.setFillColor(color);
	// �������� ������� �������� ����� � ���������� ����
	s.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	cS.push_back(s);
}

// �������� ���������� ���������������
void Objects::createPolygon(float R, int angle, sf::RenderWindow& window) {
	color = (sf::Color(rand() % 255, rand() % 255, rand() % 255));
	// �������� ����� � �������� R
	sf::CircleShape s(R, angle);
	// ���������� ����������� � �������� �����
	s.setOrigin(R, R);
	// ������� ����� ������� ������
	s.setFillColor(color);
	// �������� ������� �������� ����� � ���������� ����
	s.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	tS.push_back(s);
}

// �������� ���������������
void Objects::createRectangle(float width, float height, sf::RenderWindow& window) {
	color = (sf::Color(rand() % 255, rand() % 255, rand() % 255));
	sf::Vector2f vecRect(width, height);
	// �������� ����� � �������� R
	sf::RectangleShape s(vecRect);
	// ���������� ����������� � �������� �����
	s.setOrigin(width / 2, height / 2);
	// ������� ����� ������� ������
	s.setFillColor(color);
	// �������� ������� �������� ����� � ���������� ����
	s.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	rS.push_back(s);
}

// �������� ������
void Objects::deleteCircle() {
	cS.clear();
}

// �������� ��������
void Objects::deleteRectangle() {
	rS.clear();
}

// �������� ���������� ���������������
void Objects::deletePolygon() {
	tS.clear();
}

void Objects::sellectedShape(sf::RenderWindow& window) {
	for (int i = 0; i < cS.size(); i++) {
		// �������� ����� �� �������
		if (cS[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			if (sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					// �������� �������� ������� 
					std::vector<sf::CircleShape>::iterator it1 = cS.begin() + i;
					cS.erase(it1);
				}
			}
		}
	}
	for (int i = 0; i < rS.size(); i++) {
		// �������� ����� �� �������
		if (rS[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			if (sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					// �������� �������� ������� 
					std::vector<sf::RectangleShape>::iterator it1 = rS.begin() + i;
					rS.erase(it1);
				}
			}
		}
	}
	for (int i = 0; i < tS.size(); i++) {
		// �������� ����� �� �������
		if (tS[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			if (sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					// �������� �������� ������� 
					std::vector<sf::CircleShape>::iterator it1 = tS.begin() + i;
					tS.erase(it1);
				}
			}
		}
	}
}

// ��������� �����
void Objects::draw(sf::RenderWindow& window) {
	// ��������� � ��������� ������
	for (int i = 0; i < cS.size(); i++) {
		// ��������� ������� ����� � �������
		window.draw(cS[i]);
	}
	for (int i = 0; i < rS.size(); i++) {
		// ��������� ������� �������������� � �������
		window.draw(rS[i]);
	}
	for (int i = 0; i < tS.size(); i++) {
		// ��������� ������� ����������� �������������� � �������
		window.draw(tS[i]);
	}
}