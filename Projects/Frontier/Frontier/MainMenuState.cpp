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

		if (!_mainMenuTexture.loadFromFile("white-brick-wall.jpg"))
		{
			std::cout << "cannot find image" << std::endl; //Sprite
		}
		_mainMenuBackground.setTexture(_mainMenuTexture);

		Display::setView(640,360,1280,720);

		//This is the main menu logo
//		loadFont();
//		_text.setFont(_font);
//		_text.setCharacterSize(60);
//		_text.setFillColor(sf::Color::Blue);
//		_text.setString("Push Blox");
//		_text.setPosition(Display::WIDTH/2 - 147,10);
		_menuRect.setSize(sf::Vector2f(305, 165));
		_menuRect.setFillColor(sf::Color::White);
		_menuRect.setPosition(Display::WIDTH/2 - 157, 25);

	}

	//This gets keyboard input
	void MainMenuState::input(sf::Time dt)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			_game->pushState(std::make_unique<State::PlayingState>(*_game));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			_game->popState();
		}
	}

	//This updates the window for the objects
	void MainMenuState::update(double dt)
	{

	}

	//This draws to the screen
	void MainMenuState::draw()
	{
		Display::draw(_menuRect);
	}
}
