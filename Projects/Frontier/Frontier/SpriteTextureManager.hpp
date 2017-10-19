//
//  SpriteTextureManager.hpp
//  Frontier
//
//  Created by Jim Samson on 10/13/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef SpriteTextureManager_hpp
#define SpriteTextureManager_hpp

#include "ResourcePath.hpp"
#include "DisplayWindow.hpp"

#include <stdio.h>
#include <string>
using std::string;
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
using std::cout;
using std::endl;

namespace frontier
{
	class Sprite
	{
	public:
		Sprite()
		{
			int ELEMENT_SIZE = 2;
			_positionSpeed.resize(ELEMENT_SIZE);
		}

		void loadTexture(string &&, int, int, int, int);
		void draw();
		void setPosition(int);

		void loadTexture(std::vector<frontier::Sprite> &, string &&);
		void updateObject(std::vector<frontier::Sprite> &);
		void setPositionObj(std::vector<frontier::Sprite>&,const int &);
		void moveObject(std::vector<frontier::Sprite> &, sf::Time &, const int &);
		void drawObject(std::vector<frontier::Sprite> &);

		sf::Sprite _spriteObject;
		sf::Texture _textureObject;

		const int X_POSITION = 272;
		const int Y_POSITION = 160;

	private:
		std::vector<sf::Vector2f> _positionSpeed;
	};
}
#endif /* SpriteTextureManager_hpp */
