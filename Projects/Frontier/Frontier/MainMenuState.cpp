//
//  MinMenuState.cpp
//  Frontier
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "MainMenuState.hpp"
#include "GameLoop.hpp"
#include "DisplayWindow.hpp"
#include "PlayState.hpp"

#include <memory>
#include <iostream>
#include <algorithm>

namespace State
{

	MainMenuState::MainMenuState(Game& game) : GameState(game)
	{
		// Sets the view of the window display
		Display::setView(640,360,1280,720);

		// Loads data from texture
		if(!_backgroundSunset.create(Display::WIDTH,Display::HEIGHT))
		{ std::cout << "Texture cannot be created." << std::endl; }

		// Sets the texture into a sprite
		if (!_backgroundSunset.loadFromFile(resourcePath() + "parallax-mountain-bg.png"))
		{ std::cout << "cannot find image" << std::endl; }

		_mainSunsetBackground.setTexture(_backgroundSunset);
		_mainSunsetBackground.setScale(5,5);

		// Opens the music file
		if(!_music.openFromFile(resourcePath() + "MainMenu.wav"))
		{}

		_musicPtr = &_music;

	}

	// This gets keyboard input
	void MainMenuState::input(sf::Time dt)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			_musicPtr->stop();
			_game->pushState(std::make_unique<State::PlayingState>(*_game));
		}
	}

	//This updates the window for the objects
	void MainMenuState::update(double dt)
	{

	}

	//This draws to the screen
	void MainMenuState::draw()
	{
		Display::draw(_mainSunsetBackground);
	}
}
