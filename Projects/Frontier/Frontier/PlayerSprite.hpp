//
//  player.hpp
//  Frontier
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include "ParentOfSprites.hpp"
#include <stdio.h>

class Player : public Entity
{
public:
	Player();
	void updateSpritePosition();
	void keyboardInput(sf::Time dt);
	void keyboardInput2(sf::Time dt);
	void drawToWindow();
	void loadTexture();
	sf::Texture playerTexture;

	int getDirection() const;
	int getIsRunning() const;

	int _direction = 1;
	int _counterWalking = 0;
	int _isRunning = 0;
	int _movementSpeed = 1;

	int startPos = 0;

	int _xDirection = 0;
	int _yDirection = 0;
	int _playerState = 0;
	bool _ifPlayer = true;
	bool _ifPlayerIsIt = false;

	int cameraPosX;
	int cameraPosY;

	void setPlayerCam();

	bool _ifIsPlaying;
private:
	int _spritePosition = 32;
};

#endif /* player_hpp */
