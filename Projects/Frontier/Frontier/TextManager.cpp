//
//  TextManager.cpp
//  Frontier
//
//  Created by Jim Samson on 10/17/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "TextManager.hpp"

void Text::loadFont(string && nameOfFile)
{
	if(!_font.loadFromFile(resourcePath() + nameOfFile))
	{ std::cout << "Could not find " << nameOfFile << std::endl;}
	
	_text.setFont(_font);
	_text.setFillColor(sf::Color::Black);
	_text.scale(0.2, 0.2);
}

void Text::setText(string && text, int size)
{
	_text.setString(text);
	_text.setCharacterSize(size);
}

void Text::setPosition(int xpos, int ypos)
{
	_text.setPosition(xpos, ypos);
}

void Text::draw()
{
	Display::draw(_text);
}
