#include "GameEngine.h"

void GameEngine::start() {
	// Вектор разрешения экрана
	sf::Vector2i resolution;
	// Записываем разрешение экрана в вектор
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

	// Объект, который, собственно, является главным окном приложения
    window.create(sf::VideoMode(resolution.x, resolution.y),
        "SFML Works!",
        sf::Style::Fullscreen);
	// Начинаем запись времени
	sf::Clock loop_timer;
	font.loadFromFile("LetoTextSansDefect.otf");
	text.setFont(font);
	sf::String str(L" Esc - Выход\n 1 - Выбрать круг\n 2 - Выбрать квадрат\n ЛКМ - создать выбранную фигуру\n ПКМ - удалить выбранную фигуру\n Колесико мыши вниз - Уменьшить фигуру\n Колксико мыши вверх - Увеличить фигуру\n DEL - Удалить все выбранные фигуры");
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
		//добавляем запись в конец массива 
		cS.push_back(createCircle(r, col, window));
		sf::sleep(sf::milliseconds(50));
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sellectShape == 2) {
		// добавляем запись в конец массива 
		rS.push_back(createRectangle(width, height, col, window));
		sf::sleep(sf::milliseconds(50));
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sellectShape == 3) {
		// добавляем запись в конец массива 
		tS.push_back(createCircle(r, angle, col, window));
		sf::sleep(sf::milliseconds(50));
	}
	switch (event.type)
	{
		// Пользователь нажал на кнопку клавиатуры
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			// тогда закрываем его 
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
			cS.clear();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && sellectShape == 2) {
			rS.clear();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && sellectShape == 3) {
			tS.clear();
		}
		break;
		// Увеличение и уменьшение радиуса круга 
	case sf::Event::MouseWheelMoved:
		// Если колесико вверх добаляем единицу к радиусу
		if (event.mouseWheel.delta > 0) {
			r += 1;
			width += 1;
			height += 1;
		}
		// Иначе забираем единицу
		else
		{
			r -= 1;
			width -= 1;
			height -= 1;
		}
		break;
	case sf::Event::MouseMoved:
		for (int i = 0; i < cS.size(); i++) {
			// Удаление круга из массива
			if (cS[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
				// Если курсор наведен на круг то он становится красным
				cS[i].setFillColor(sf::Color::Red);
				if (sf::Event::MouseButtonPressed) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
						// удаление элемента массива 
						std::vector<sf::CircleShape>::iterator it1 = cS.begin() + i;
						cS.erase(it1);
					}
				}
			}
			else if (cS[i].getFillColor() != sf::Color::Green) {
				// Если курсор не наведен на круг, то он становится зеленым
				cS[i].setFillColor(sf::Color::Green);
			}
		}
		for (int i = 0; i < rS.size(); i++) {
			// Удаление круга из массива
			if (rS[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
				// Если курсор наведен на круг то он становится красным
				rS[i].setFillColor(sf::Color::Red);
				if (sf::Event::MouseButtonPressed) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
						// удаление элемента массива 
						std::vector<sf::RectangleShape>::iterator it1 = rS.begin() + i;
						rS.erase(it1);
					}
				}
			}
			else if (rS[i].getFillColor() != sf::Color::Green) {
				// Если курсор не наведен на круг, то он становится зеленым
				rS[i].setFillColor(sf::Color::Green);
			}
		}
		for (int i = 0; i < tS.size(); i++) {
			// Удаление круга из массива
			if (tS[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
				// Если курсор наведен на круг то он становится красным
				tS[i].setFillColor(sf::Color::Red);
				if (sf::Event::MouseButtonPressed) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
						// удаление элемента массива 
						std::vector<sf::CircleShape>::iterator it1 = tS.begin() + i;
						tS.erase(it1);
					}
				}
			}
			else if (tS[i].getFillColor() != sf::Color::Green) {
				// Если курсор не наведен на круг, то он становится зеленым
				tS[i].setFillColor(sf::Color::Green);
			}
		}
		break;
	default:
		break;
	}
}

void GameEngine::draw() {
	// Очистка окна
	window.clear();
	if (sellectShape == 1) {
		sf::String st = L" Круг ";
		sellShapeText.setString(st + std::to_string(r));
	}
	else if (sellectShape == 2) {
		sf::String st = L" Квадрат ";
		sellShapeText.setString(st + std::to_string(width));
	}
	else {
		sf::String st = L" Треугольник ";
		sellShapeText.setString(st + std::to_string(r));
	}
	// рисование и изменение кругов
	for (int i = 0; i < cS.size(); i++) {
		// Отрисовка каждого круга в массиве
		window.draw(cS[i]);
	}
	for (int i = 0; i < rS.size(); i++) {
		// Отрисовка каждого круга в массиве
		window.draw(rS[i]);
	}
	for (int i = 0; i < tS.size(); i++) {
		// Отрисовка каждого круга в массиве
		window.draw(tS[i]);
	}
	window.draw(sellShapeText);
	window.draw(text);

	// Отрисовка окна	
	window.display();
	sf::sleep(sf::microseconds(50));
}


////////
// Создание кругов
sf::CircleShape GameEngine::createCircle(float R, sf::Color color, sf::RenderWindow& window) {
	// Создание круга с радиусом R
	sf::CircleShape s(R);
	// Координаты переносятся в середину круга
	s.setOrigin(R, R);
	// Заливка круга зеленым цветом
	s.setFillColor(color);
	// Задается позиция середины круга в координаты мыши
	s.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	return s;
}
sf::CircleShape GameEngine::createCircle(float R,int angle, sf::Color color, sf::RenderWindow& window) {
	// Создание круга с радиусом R
	sf::CircleShape s(R, angle);
	// Координаты переносятся в середину круга
	s.setOrigin(R, R);
	// Заливка круга зеленым цветом
	s.setFillColor(color);
	// Задается позиция середины круга в координаты мыши
	s.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	return s;
}
sf::RectangleShape GameEngine::createRectangle(float width, float height, sf::Color color, sf::RenderWindow& window) {
	sf::Vector2f vecRect(width, height);
	// Создание круга с радиусом R
	sf::RectangleShape s(vecRect);
	// Координаты переносятся в середину круга
	s.setOrigin(width/2, height/2);
	// Заливка круга зеленым цветом
	s.setFillColor(color);
	// Задается позиция середины круга в координаты мыши
	s.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	return s;
}