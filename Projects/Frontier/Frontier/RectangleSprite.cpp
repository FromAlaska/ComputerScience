//
//  RectangleSprite.cpp
//  Frontier
//
//  Created by Jim Samson on 10/16/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "RectangleSprite.hpp"

Rectangle::Rectangle()
{
	_rectangle.resize(3);
}

void Rectangle::loadTexture(string && texture)
{
	if (!_rectangleTexture.loadFromFile(texture))
	{}

	_spriteRectangle.setTexture(_rectangleTexture);
}
