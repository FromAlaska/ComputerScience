//
//  RectangleSprite.hpp
//  Frontier
//
//  Created by Jim Samson on 10/16/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef RectangleSprite_hpp
#define RectangleSprite_hpp

#include "ParentOfSprites.hpp"

#include <stdio.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
using std::string;

class Rectangle : Entity
{
public:
	Rectangle();

	void loadTexture(string &&);

	std::vector<sf::RectangleShape> _rectangle;
	sf::Sprite _spriteRectangle;
	sf::Texture _rectangleTexture;
private:
};

#endif /* RectangleSprite_hpp */
