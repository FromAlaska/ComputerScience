//
//  display.hpp
//  Frontier
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef display_hpp
#define display_hpp

#include <stdio.h>

#include<SFML/Graphics.hpp>

//Namespace Display
namespace Display
{
	void init();
	void clear(sf::Color color);
	void display();
	void draw(const sf::Drawable& drawable);

	bool isOpen();
	void checkWindowEvents();

	void setView(int centerX, int centerY, int sizeX, int sizeY);
	void changeView(float w, float h);

	void closeWindow();

	const int HEIGHT = 720;
	const int WIDTH = 1280;

	std::unique_ptr<sf::RenderWindow> window;
	std::unique_ptr<sf::View> view;
}

#endif /* display_hpp */
