//
//  display.cpp
//  Frontier
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "DisplayWindow.hpp"

#include <memory>

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

namespace Display
{
	void init()
	{
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "PushBlox",sf::Style::Default);
		view = std::make_unique<sf::View>(sf::FloatRect(0, 0, 1, 1));
	}

	void clear(sf::Color color)
	{
		window->clear(color);
	}

	void display()
	{
		window->display();
	}

	void draw(const sf::Drawable& drawable)
	{
		window->setView(*view);
		window->draw(drawable);
	}

	void checkWindowEvents()
	{
		sf::Event e;

		while (window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window->close();
			}
		}
	}

	bool isOpen()
	{
		return window->isOpen();
	}

	void setView(int centerX, int centerY, int sizeX, int sizeY)
	{
		view->setSize(sizeX, sizeY);
		view->setCenter(centerX, centerY);
	}

	void changeView(float w, float h)
	{
		view->move(w, h);
	}

	void closeWindow()
	{
		window->close();
	}
}
