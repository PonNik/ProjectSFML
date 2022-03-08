#include "GameEngine.h"

void GameEngine::start() {
	// ������ ���������� ������
	sf::Vector2i resolution;
	// ���������� ���������� ������ � ������
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

	// ������, �������, ����������, �������� ������� ����� ����������
    window.create(sf::VideoMode(resolution.x, resolution.y),
        "SFML Works!",
        sf::Style::Fullscreen);
	// �������� ������ �������
	sf::Clock loop_timer;
	font.loadFromFile("LetoTextSansDefect.otf");
	text.setFont(font);
	sf::String str(L" Esc - �����\n 1 - ������� ����\n 2 - ������� �������\n ��� - ������� ��������� ������\n ��� - ������� ��������� ������\n �������� ���� ���� - ��������� ������\n �������� ���� ����� - ��������� ������");
	text.setString(str);
	text.setCharacterSize(20);
	while (window.isOpen()){
		input();
		update();
		draw();
		sf::Int32 frame_duration = loop_timer.getElapsedTime().asMilliseconds(); 
		sf::Int32 time_to_sleep = int(1000.f / want_fps) - frame_duration;
		if(time_to_sleep > 0) {
			sf::sleep(sf::milliseconds(time_to_sleep));
		}
	}

}
void GameEngine::update() {
	while (window.pollEvent(event))
	{
		input();
		draw();
	}
}

void GameEngine::input() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sellectShape == 1) {
		//��������� ������ � ����� ������� 
		cS.push_back(createCircle(r, col, window));
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sellectShape == 2) {
		// ��������� ������ � ����� ������� 
		rS.push_back(createRectangle(width, height, col, window));
	}
	switch (event.type)
	{
		// ������������ ����� �� ������ ����������
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			// ����� ��������� ��� 
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
			sellectShape = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
			sellectShape = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && sellectShape == 1) {
			cS.clear();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && sellectShape == 2) {
			rS.clear();
		}
		break;
		// ���������� � ���������� ������� ����� 
	case sf::Event::MouseWheelMoved:
		// ���� �������� ����� �������� ������� � �������
		if (event.mouseWheel.delta > 0) {
			r += 1;
			width += 1;
			height += 1;
		}
		// ����� �������� �������
		else
		{
			r -= 1;
			width -= 1;
			height -= 1;
		}
		break;
	case sf::Event::MouseMoved:
		for (int i = 0; i < cS.size(); i++) {
			// �������� ����� �� �������
			if (cS[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
				// ���� ������ ������� �� ���� �� �� ���������� �������
				cS[i].setFillColor(sf::Color::Red);
				if (sf::Event::MouseButtonPressed) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
						// �������� �������� ������� 
						std::vector<sf::CircleShape>::iterator it1 = cS.begin() + i;
						cS.erase(it1);
					}
				}
			}
			else if (cS[i].getFillColor() != sf::Color::Green) {
				// ���� ������ �� ������� �� ����, �� �� ���������� �������
				cS[i].setFillColor(sf::Color::Green);
			}
		}
		for (int i = 0; i < rS.size(); i++) {
			// �������� ����� �� �������
			if (rS[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
				// ���� ������ ������� �� ���� �� �� ���������� �������
				rS[i].setFillColor(sf::Color::Red);
				if (sf::Event::MouseButtonPressed) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
						// �������� �������� ������� 
						std::vector<sf::RectangleShape>::iterator it1 = rS.begin() + i;
						rS.erase(it1);
					}
				}
			}
			else if (rS[i].getFillColor() != sf::Color::Green) {
				// ���� ������ �� ������� �� ����, �� �� ���������� �������
				rS[i].setFillColor(sf::Color::Green);
			}
		}
		break;
	default:
		break;
	}
}

void GameEngine::draw() {
	// ������� ����
	window.clear();
	// ��������� � ��������� ������
	for (int i = 0; i < cS.size(); i++) {
		// ��������� ������� ����� � �������
		window.draw(cS[i]);
	}
	for (int i = 0; i < rS.size(); i++) {
		// ��������� ������� ����� � �������
		window.draw(rS[i]);
	}
	window.draw(text);
	// ��������� ����	
	window.display();

}


////////
// �������� ������
sf::CircleShape GameEngine::createCircle(float R, sf::Color color, sf::RenderWindow& window) {
	// �������� ����� � �������� R
	sf::CircleShape s(R);
	// ���������� ����������� � �������� �����
	s.setOrigin(R, R);
	// ������� ����� ������� ������
	s.setFillColor(sf::Color::Green);
	// �������� ������� �������� ����� � ���������� ����
	s.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	return s;
}
sf::RectangleShape GameEngine::createRectangle(float width, float height, sf::Color color, sf::RenderWindow& window) {
	sf::Vector2f vecRect(width, height);
	// �������� ����� � �������� R
	sf::RectangleShape s(vecRect);
	// ���������� ����������� � �������� �����
	s.setOrigin(width/2, height/2);
	// ������� ����� ������� ������
	s.setFillColor(sf::Color::Green);
	// �������� ������� �������� ����� � ���������� ����
	s.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	return s;
}