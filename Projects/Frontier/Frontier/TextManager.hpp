//
//  TextManager.hpp
//  Frontier
//
//  Created by Jim Samson on 10/17/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef TextManager_hpp
#define TextManager_hpp

#include "DisplayWindow.hpp"
#include "ResourcePath.hpp"

#include <stdio.h>
#include <string>
using std::string;
#include <iostream>

#include <SFML/Graphics/Text.hpp>

class Text
{
public:
	void loadFont(string &&);
	void setText(string &&,int);
	void setPosition(int,int);
	void draw();
private:
	sf::Font _font;
	sf::Text _text;
};

#endif /* TextManager_hpp */
