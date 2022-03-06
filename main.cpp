#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

// ВЫсота и ширина окна
int WIDTH = 800;
int HEIGHT = 600;

// Начальные значения рисующихся кругов 
float r = 50;
Color col = Color::Green;
bool pause = false;

// Объявления функций
CircleShape createShape(float R, Color color, RenderWindow& window);
void eventGroup(Event event, RenderWindow& window, std::vector<CircleShape>& cS);
void drawCircle(Event event, RenderWindow& window, std::vector<CircleShape>& cS);

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML Works!", sf::Style::Titlebar | sf::Style::Close);
	
	// Динамический массив кругов
	std::vector<CircleShape> cS;

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{ 
			// Запись кругов в массив 
			eventGroup(event, window, cS);
		}
		// Очистка окна
		window.clear();
		// рисование и изменение кругов
		drawCircle(event, window, cS);
		// Отрисовка окна	
		window.display();
	}

	return 0;
}

// Создание кругов
CircleShape createShape(float R, Color color, RenderWindow& window) {
	// Создание круга с радиусом R
	CircleShape s(R);
	// Координаты переносятся в середину круга
	s.setOrigin(R, R);
	// Заливка круга зеленым цветом
	s.setFillColor(Color::Green);
	// Задается позиция середины круга в координаты мыши
	s.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
	return s;
}

// Группа управления
void eventGroup(Event event, RenderWindow& window, std::vector<CircleShape>& cS) {
	switch (event.type)
	{
		// Пользователь нажал на «крестик» и хочет закрыть окно?
	case event.Closed:
		// тогда закрываем его 
		window.close();
		break;
		// Создание кругов с заданными значениями
	case Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left && pause == false) {
			// добавляем запись в конец массива 
			cS.push_back(createShape(r, col, window));
		}
		break;
		// Увеличение и уменьшение радиуса круга 
	case Event::MouseWheelMoved:
		// Если колесико вверх добаляем единицу к радиусу
		if (event.mouseWheel.delta > 0) {
			r += 1;
		}
		// Иначе забираем единицу
		else
		{
			r -= 1;
		}
		break;
	default:
		break;
	}
}

void drawCircle(Event event, RenderWindow& window, std::vector<CircleShape>& cS) {
	for (int i = 0; i < cS.size(); i++) {
		// Удаление круга из массива
		if (cS[i].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && pause == false) {
			// Если курсор наведен на круг то он становится красным
			cS[i].setFillColor(Color::Red);
			if (Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Right && pause == false) {
					// удаление элемента массива 
					std::vector<CircleShape>::iterator it1 = cS.begin() + i;
					cS.erase(it1);
					continue;
				}
			}
		}
		else {
			// Если курсор не наведен на круг, то он становится зеленым
			cS[i].setFillColor(Color::Green);
		}
		// Отрисовка каждого круга в массиве
		window.draw(cS[i]);
	}
}