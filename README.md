06.03.22
ProjectSFML 
Это мой проект в котором я изучаю C++ вместе с библиотекой SFML

На данный момент в нем реализованно создание и удаление примитивов в виде кругов
![image](https://user-images.githubusercontent.com/93863311/156939845-70554b41-0c2d-49a7-9d02-63b44a26c30d.png)

- Создание кругов производится нажатием ЛКМ на области окна! Там и будет середина круга
- Удаление кругов производится нажатием ПКМ на нужный объект!
- Колесико мыши вниз и вверх, уменьшают и увеличивают радиус создаваемого круга соответственно!
- При наведении на круг, он подсвечивается красным цветом
![image](https://user-images.githubusercontent.com/93863311/156940043-f8ec7362-2c18-4556-9ec4-41e952d00f70.png)

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

07.03.22

Созданн класс GameEngine туда перенесен соновной код который находился в main

Упрощение main.cpp путем работы с классом
```
#include <SFML/Graphics.hpp>
#include "GameEngine.h"

int main()
{
	GameEngine engine;

	engine.start();
	
	return 0;
}
```
// это весь код main.cpp

// провел работу с таймером который уменьшает количество операций в программе
```
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
```
// это защищает нас от траты всех ресурсов ПК на ненужные иттерации

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

08.03.22

 - Добавленны подсказки управления

![image](https://user-images.githubusercontent.com/93863311/157324077-d7bd5f6a-a5f6-41fe-8929-42a36a4b2948.png)
![image](https://user-images.githubusercontent.com/93863311/157324110-8cb1f1fc-1344-40c8-96ea-f15b374e3d99.png)
 - Теперь можно рисовать не только круги, но и квадраты 
![image](https://user-images.githubusercontent.com/93863311/157323866-b2414f61-8fa2-4431-817d-236711d46f77.png)

  
