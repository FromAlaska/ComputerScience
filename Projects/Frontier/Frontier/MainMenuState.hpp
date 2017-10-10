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

#include <stdio.h>
#include <iostream>
#include <memory>

#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>

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

		~MainMenuState()
		{
			delete _musicPtr;
		}

	private:

		sf::Sprite _mainSunsetBackground;
		sf::Sprite _mainTreesBackground;
		sf::Sprite _mainMountainsBackground;
		sf::Sprite _mainFarMountainsBackground;
		sf::Sprite _mainFarTreesBackground;

		sf::RectangleShape _menuBorderRect;
		sf::RectangleShape _menuRect;
		sf::Text _hostGameText;
		sf::Text _clientGameText;
		sf::Text _settingsText;
		sf::Text _aboutText;


		sf::Music _music;
		sf::Music *_musicPtr;
		sf::Texture _backgroundSunset;
		sf::Texture _backgroundTrees;
		sf::Texture _backgroundMountains;
		sf::Texture _backgroundFarMountain;
		sf::Texture _backgroundFarTrees;
	};
}

#endif /* MainMenuState_hpp */
