//
//  entity.hpp
//  Frontier
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef parentsprites_hpp
#define parentsprites_hpp

#include <stdio.h>

#include<SFML/Graphics.hpp>
/*
 Entity is just a parent for all objects within the game.
 */
class Entity
{
public:
	Entity()
	{}
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
};

#endif /* parentsprite_hpp */
