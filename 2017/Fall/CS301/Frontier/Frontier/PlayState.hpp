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

#include <SFML/Audio.hpp>

namespace State
{
	class PlayingState : public State::ParentState
	{
	public:
		PlayingState(Game& game);

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

#endif /* PlayState_hpp */
