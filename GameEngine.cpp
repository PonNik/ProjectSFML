#include "GameEngine.h"

void GameEngine::start() {
	// Вектор разрешения экрана
	sf::Vector2i resolution;
	// Записываем разрешение экрана в вектор
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

	srand(time(NULL));

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
		objects.createCircle(r, window);
		sf::sleep(sf::milliseconds(50));
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sellectShape == 2) {
		// добавляем запись в конец массива 
		objects.createRectangle(width, height, window);
		sf::sleep(sf::milliseconds(50));
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sellectShape == 3) {
		// добавляем запись в конец массива 
		objects.createPolygon(r, angle, window);
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
			objects.deleteCircle();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && sellectShape == 2) {
			objects.deleteRectangle();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && sellectShape == 3) {
			objects.deletePolygon();
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
		objects.sellectedShape(window);
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
	objects.draw(window);
	window.draw(sellShapeText);
	window.draw(text);

	// Отрисовка окна	
	window.display();
	sf::sleep(sf::microseconds(50));
}