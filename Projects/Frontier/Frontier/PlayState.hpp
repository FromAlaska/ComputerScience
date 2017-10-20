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
#include <SFML/System/Thread.hpp>
#include <map>

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

		frontier::Sprite _mainSunsetBackground;
		std::vector<frontier::Sprite> _mainMountainsBackground;
		std::vector<frontier::Sprite> _mainTreesBackground;
		std::vector<frontier::Sprite> _mainFarMountainsBackground;
		std::vector<frontier::Sprite> _mainFarTreesBackground;

		std::vector<frontier::Sprite> _jimRulz;

		frontier::Sprite _mainMountains;
		frontier::Sprite _mainTrees;
		frontier::Sprite _mainFarMountains;
		frontier::Sprite _mainFarTrees;

		frontier::Sprite _jimRulzSprite;

		//Music
		SoundManager _sound;
		bool ifCPressed = false;
		bool ifDPressed = false;
		bool ifEPressed = false;
		bool ifFPressed = false;
		bool ifGPressed = false;
		bool ifAPressed = false;
		bool ifBPressed = false;

		bool ifSWavePressed = false;
	};
}

#endif /* PlayState_hpp */
