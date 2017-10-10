//
//  PlayState.cpp
//  Frontier
//
//  Created by Jim Samson on 9/9/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "PlayState.hpp"
#include "GameLoop.hpp"
#include "DisplayWindow.hpp"
#include "ParentState.hpp"

#include <memory>
#include <iostream>
#include <algorithm>

namespace State
{

	PlayingState::PlayingState(Game& game) : GameState(game)
	{
		_mainMenuBackground.setTexture(_mainMenuTexture);

		Display::setView(640,360,1280,720);

	}

	//This gets keyboard input
	void PlayingState::input(sf::Time dt)
	{
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			_game->popState();
		}
	}

	//This updates the window for the objects
	void PlayingState::update(double dt)
	{

	}

	//This draws to the screen
	void PlayingState::draw()
	{
	}
}
