//  GameLoop.cpp
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "GameLoop.hpp"
#include "DisplayWindow.hpp"
#include "MainMenuState.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>

//***********************
// Class Game - Game loop
//***********************

Game::Game()
{
	Display::init();
	pushState(std::make_unique<State::MainMenuState>(*this));
}

void Game::gameLoop()
{
	sf::Clock clock;
	sf::Time dt = sf::seconds(0.1);

	// This starts the display window
	while (Display::isOpen())
	{
		Display::checkWindowEvents();
		Display::clear(sf::Color::Black);

		_states.top()->input(dt);
		_states.top()->update(0.0);
		_states.top()->draw();

		Display::display();

		dt = clock.restart();
		sf::sleep(sf::microseconds(1));
	}
}

void Game::pushState(std::unique_ptr<State::GameState > state)
{
	_states.push(std::move(state));
}

void Game::popState()
{
	if(_states.size()<=1)
	{
		std::cout << "No states available" << std::endl;
	}
	else
	{
		_states.pop();
	}
}

void Game::changeState(std::unique_ptr<State::GameState > state)
{
	popState();
	pushState(std::move(state));
}
