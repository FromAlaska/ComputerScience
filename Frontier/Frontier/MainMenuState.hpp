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

		sf::Sprite _mainMenuBackground;
		sf::RectangleShape _menuBorderRect;
		sf::RectangleShape _menuRect;
		sf::Text _hostGameText;
		sf::Text _clientGameText;
		sf::Text _settingsText;
		sf::Text _aboutText;
		sf::Music _music;
	};
}

#endif /* MainMenuState_hpp */
