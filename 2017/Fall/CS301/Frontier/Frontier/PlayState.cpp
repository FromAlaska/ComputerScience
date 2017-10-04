//
//  PlayState.cpp
//  Frontier
//
//  Created by Jim Samson on 9/9/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "PlayState.hpp"
#include "MainLoop.hpp"
#include "DisplayWindow.hpp"
#include "ParentState.hpp"

#include <memory>
#include <iostream>
#include <algorithm>

namespace State
{

	PlayingState::PlayingState(Game& game) : ParentState(game)
	{

		if (!_mainMenuTexture.loadFromFile("white-brick-wall.jpg"))
		{
			std::cout << "cannot find image" << std::endl; //Sprite
		}

		Display::setView(640,360,1280,720);

		//This is the main menu logo
		//		loadFont();
		//		_text.setFont(_font);
		//		_text.setCharacterSize(60);
		//		_text.setFillColor(sf::Color::Blue);
		//		_text.setString("Push Blox");
		//		_text.setPosition(Display::WIDTH/2 - 147,10);

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
		_mainMenuBackground.setTexture(_mainMenuTexture);
		_music.play();
	}
}
