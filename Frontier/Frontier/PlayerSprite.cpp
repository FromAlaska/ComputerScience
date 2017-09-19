//
//  player.cpp
//  Frontier
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "PlayerSprite.hpp"
#include "DisplayWindow.hpp"

#include <iostream>

//We must define the position in the states
Player::Player()
{
	rect.setSize(sf::Vector2f(60, 65));
	rect.setFillColor(sf::Color::Red);
	sprite.scale(2.0f, 2.0f);
}

//This sets the position of the sprite relative to the rectangle
void Player::updateSpritePosition()
{
	sprite.setPosition(rect.getPosition());
}

void Player::keyboardInput(sf::Time dt)
{
}

//playerOne is from a texture object call
void Player::loadTexture()
{
	if (!playerTexture.loadFromFile("Finally.png"))
	{}

	sprite.setTexture(playerTexture);
}

void Player::drawToWindow()
{
	Display::draw(sprite);
}

int Player::getDirection() const
{
	return _direction;
}

int Player::getIsRunning() const
{
	return _isRunning;
}

void Player::setPlayerCam()
{
	Display::setView(cameraPosX, cameraPosY, 1920, 1080);
}
