#include <SFML/Graphics.hpp>
#include "settings.h"
#include "road.h"

using namespace sf;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, Style::Titlebar | Style::Close);
	window.setPosition(Vector2i{(1920 - (int)WINDOW_WIDTH) / 2, 0 });
	window.setFramerateLimit(FPS);

	RoadLayer grass;
	roadLayerInit(grass, GRASS_POS , "grass.jpg");


	RoadLayer send;
	roadLayerInit(send, SEND_POS, "send.jpg");

	RoadLayer road;
	roadLayerInit(road, ROAD_POS , "road.jpg");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		// Отрисовка окна 
		window.clear();
		window.draw(grass.sprite);
		window.draw(send.sprite);
		window.draw(road.sprite);
		//roadLayerDraw(window, grass, send, road);
		window.display();
	}

	return 0;
}