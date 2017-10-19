//
//  MainMenuState.hpp
//  Frontier
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef MainMenuState_hpp
#define MainMenuState_hpp

#include "ParentState.hpp"
#include "ParentOfSprites.hpp"
#include "MusicManager.hpp"
#include "RectangleSprite.hpp"
#include "GameLoop.hpp"
#include "DisplayWindow.hpp"
#include "PlayState.hpp"
#include "TextManager.hpp"

#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <memory>

#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System/Vector2.hpp>

namespace State
{
	class MainMenuState : public GameState
	{
	public:
		MainMenuState(Game& game);

		void input(sf::Time dt);
		void update(double dt);
		void draw();

		sf::Texture _mainMenuTexture;

	private:

		Sound _sound;

		frontier::Sprite _mainSunsetBackground;

		std::vector<frontier::Sprite> _mainMountainsBackground;
		std::vector<frontier::Sprite> _mainTreesBackground;
		std::vector<frontier::Sprite> _mainFarMountainsBackground;
		std::vector<frontier::Sprite> _mainFarTreesBackground;

		frontier::Sprite _mainMountains;
		frontier::Sprite _mainTrees;
		frontier::Sprite _mainFarMountains;
		frontier::Sprite _mainFarTrees;

		Text _titleText;
		Text _enterToStart;
	};
}

#endif /* MainMenuState_hpp */
