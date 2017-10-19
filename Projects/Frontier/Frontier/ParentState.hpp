//
//  gameState.hpp
//  Frontier
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef gameState_hpp
#define gameState_hpp

#include "PlayerSprite.hpp"
#include "MusicManager.hpp"
#include "SpriteTextureManager.hpp"
#include "SoundManager.hpp"

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include <memory>

class Game;

namespace State
{
	class GameState
	{
	public:
		GameState(Game& game);

		virtual void input(sf::Time dt) = 0;
		virtual void update(double dt) = 0;
		virtual void draw() = 0;

		void loadFont();

	protected:
		Game* _game;
		sf::Text _text;
		sf::Font _font;
		
	};
}
#endif /* gameState_hpp */
