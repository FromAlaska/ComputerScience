//
//  PlayState.hpp
//  Frontier
//
//  Created by Jim Samson on 9/9/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef PlayState_hpp
#define PlayState_hpp

#include "ParentState.hpp"

#include <stdio.h>
#include <iostream>
#include <memory>
#include <cstdint>

namespace State
{
	class PlayingState : public State::GameState
	{
	public:
		PlayingState(Game& game);

		void input(sf::Time dt);
		void update(double dt);
		void draw();
		sf::Texture _mainMenuTexture;
	private:
		sf::Sprite _mainMenuBackground;
		SoundManager _sound;
	};
}

#endif /* PlayState_hpp */
