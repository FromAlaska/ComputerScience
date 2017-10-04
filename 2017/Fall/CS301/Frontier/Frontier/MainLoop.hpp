//
//  game.hpp
//  Frontier
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include "ParentState.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory.h>
#include <iostream>
#include <stack>

// Class Game
// This is the Game Loop. This class is used to start a stack which holds the game loop
// You can switch between game loops with a unique ptr.
class Game
{
public:
	Game();

	void gameLoop();
	void pushState(std::unique_ptr<State::ParentState> state);
	void popState();
	void changeState(std::unique_ptr<State::ParentState> state);

private:
	std::stack<std::unique_ptr<State::ParentState>> _states;
	sf::Texture _backgroundTexture;
	sf::Sprite _spriteTexture;
	};

#endif /* game_hpp */
