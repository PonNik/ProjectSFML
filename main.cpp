#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

// ������ � ������ ����
int WIDTH = 800;
int HEIGHT = 600;

// ��������� �������� ���������� ������ 
float r = 50;
Color col = Color::Green;
bool pause = false;

// ���������� �������
CircleShape createShape(float R, Color color, RenderWindow& window);
void eventGroup(Event event, RenderWindow& window, std::vector<CircleShape>& cS);
void drawCircle(Event event, RenderWindow& window, std::vector<CircleShape>& cS);

int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML Works!", sf::Style::Titlebar | sf::Style::Close);
	
	// ������������ ������ ������
	std::vector<CircleShape> cS;

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{ 
			// ������ ������ � ������ 
			eventGroup(event, window, cS);
		}
		// ������� ����
		window.clear();
		// ��������� � ��������� ������
		drawCircle(event, window, cS);
		// ��������� ����	
		window.display();
	}

	return 0;
}

// �������� ������
CircleShape createShape(float R, Color color, RenderWindow& window) {
	// �������� ����� � �������� R
	CircleShape s(R);
	// ���������� ����������� � �������� �����
	s.setOrigin(R, R);
	// ������� ����� ������� ������
	s.setFillColor(Color::Green);
	// �������� ������� �������� ����� � ���������� ����
	s.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
	return s;
}

// ������ ����������
void eventGroup(Event event, RenderWindow& window, std::vector<CircleShape>& cS) {
	switch (event.type)
	{
		// ������������ ����� �� �������� � ����� ������� ����?
	case event.Closed:
		// ����� ��������� ��� 
		window.close();
		break;
		// �������� ������ � ��������� ����������
	case Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left && pause == false) {
			// ��������� ������ � ����� ������� 
			cS.push_back(createShape(r, col, window));
		}
		break;
		// ���������� � ���������� ������� ����� 
	case Event::MouseWheelMoved:
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
	default:
		break;
	}
}

void drawCircle(Event event, RenderWindow& window, std::vector<CircleShape>& cS) {
	for (int i = 0; i < cS.size(); i++) {
		// �������� ����� �� �������
		if (cS[i].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && pause == false) {
			// ���� ������ ������� �� ���� �� �� ���������� �������
			cS[i].setFillColor(Color::Red);
			if (Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Right && pause == false) {
					// �������� �������� ������� 
					std::vector<CircleShape>::iterator it1 = cS.begin() + i;
					cS.erase(it1);
					continue;
				}
			}
		}
		else {
			// ���� ������ �� ������� �� ����, �� �� ���������� �������
			cS[i].setFillColor(Color::Green);
		}
		// ��������� ������� ����� � �������
		window.draw(cS[i]);
	}
}