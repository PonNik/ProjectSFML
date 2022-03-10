#include "GameEngine.h"

void GameEngine::start() {
	// ������ ���������� ������
	sf::Vector2i resolution;
	// ���������� ���������� ������ � ������
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

	srand(time(NULL));

	// ������, �������, ����������, �������� ������� ����� ����������
    window.create(sf::VideoMode(resolution.x, resolution.y),
        "SFML Works!",
        sf::Style::Fullscreen);
	// �������� ������ �������
	sf::Clock loop_timer;
	font.loadFromFile("LetoTextSansDefect.otf");
	text.setFont(font);
	sf::String str(L" Esc - �����\n 1 - ������� ����\n 2 - ������� �������\n ��� - ������� ��������� ������\n ��� - ������� ��������� ������\n �������� ���� ���� - ��������� ������\n �������� ���� ����� - ��������� ������\n DEL - ������� ��� ��������� ������");
	text.setString(str);
	text.setCharacterSize(20);

	sellShapeText.setFont(font);
	sellShapeText.setCharacterSize(20);
	sellShapeText.setPosition(0, resolution.y - 40);

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
		objects.createCircle(r, window);
		sf::sleep(sf::milliseconds(50));
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sellectShape == 2) {
		// ��������� ������ � ����� ������� 
		objects.createRectangle(width, height, window);
		sf::sleep(sf::milliseconds(50));
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sellectShape == 3) {
		// ��������� ������ � ����� ������� 
		objects.createPolygon(r, angle, window);
		sf::sleep(sf::milliseconds(50));
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
			sellectShape = 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && sellectShape == 1) {
			objects.deleteCircle();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && sellectShape == 2) {
			objects.deleteRectangle();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && sellectShape == 3) {
			objects.deletePolygon();
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
		objects.sellectedShape(window);
		break;
	default:
		break;
	}
}

void GameEngine::draw() {
	// ������� ����
	window.clear();
	if (sellectShape == 1) {
		sf::String st = L" ���� ";
		sellShapeText.setString(st + std::to_string(r));
	}
	else if (sellectShape == 2) {
		sf::String st = L" ������� ";
		sellShapeText.setString(st + std::to_string(width));
	}
	else {
		sf::String st = L" ����������� ";
		sellShapeText.setString(st + std::to_string(r));
	}
	// ��������� � ��������� ������
	objects.draw(window);
	window.draw(sellShapeText);
	window.draw(text);

	// ��������� ����	
	window.display();
	sf::sleep(sf::microseconds(50));
}