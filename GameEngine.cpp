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
	switch (event.type)
	{
		// ������������ ����� �� ������ ����������
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			// ����� ��������� ��� 
			window.close();
		}
		break;
		// �������� ������ � ��������� ����������
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left) {
			// ��������� ������ � ����� ������� 
			cS.push_back(createShape(r, col, window));
		}
		break;
		// ���������� � ���������� ������� ����� 
	case sf::Event::MouseWheelMoved:
		// ���� �������� ����� �������� ������� � �������
		if (event.mouseWheel.delta > 0) {
			r += 1;
		}
		// ����� �������� �������
		else
		{
			r -= 1;
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
			else {
				// ���� ������ �� ������� �� ����, �� �� ���������� �������
				cS[i].setFillColor(sf::Color::Green);
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
	// ��������� ����	
	window.display();

}


////////
// �������� ������
sf::CircleShape GameEngine::createShape(float R, sf::Color color, sf::RenderWindow& window) {
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