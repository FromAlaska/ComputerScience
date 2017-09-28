//
//  gameState.cpp
//  Frontier
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "ParentState.hpp"
#include "DisplayWindow.hpp"

namespace State
{
	GameState::GameState(Game& game) : _game(&game)
	{}

	void GameState::loadFont()
	{
		if (!_font.loadFromFile("Arial.ttf"))
		{}
	}
}
