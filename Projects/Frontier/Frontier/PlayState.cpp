//
//  PlayState.cpp
//  Frontier
//
//  Created by Jim Samson on 9/9/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "PlayState.hpp"
#include "GameLoop.hpp"
#include "DisplayWindow.hpp"
#include "ParentState.hpp"

#include <memory>
#include <iostream>
#include <algorithm>

namespace State
{
	PlayingState::PlayingState(Game& game) : GameState(game)
	{

		int ELEMENT_SIZE = 2;
		_mainMountainsBackground.resize(ELEMENT_SIZE);
		_mainTreesBackground.resize(ELEMENT_SIZE);
		_mainFarMountainsBackground.resize(ELEMENT_SIZE);
		_mainFarTreesBackground.resize(ELEMENT_SIZE);
		_jimRulz.resize(ELEMENT_SIZE);

		// Loads the texture
		_mainSunsetBackground.loadTexture("parallax-mountain-bg.png", 1, 1, 0, 0);
		_mainMountains.loadTexture(_mainMountainsBackground, "parallax-mountain-mountains.png");
		_mainTrees.loadTexture(_mainTreesBackground,"parallax-mountain-foreground-trees.png");
		_mainFarMountains.loadTexture(_mainFarMountainsBackground, "parallax-mountain-mountain-far.png");
		_mainFarTrees.loadTexture(_mainFarTreesBackground, "parallax-mountain-trees.png");

		_jimRulzSprite.loadTexture("Logomakr_Jim.png", 1, 1, 0, 0);
	}

	//This gets keyboard input
	void PlayingState::input(sf::Time dt)
	{
		Display::setView(272/2, 160/2, 272, 160);
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			_game->popState();
		}

		// PRESSING Q
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && ifCPressed == false)
		{
			ifCPressed = true;

			_sound.loadBuffer(1);
			_sound.play("c");
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			ifCPressed = false;
		}

		// PRESSING W
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ifDPressed == false)
		{
			ifDPressed = true;

			_sound.loadBuffer(2);
			_sound.play("d");
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			ifDPressed = false;
		}

		// PRESSING E
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && ifEPressed == false)
		{
			ifEPressed = true;

			_sound.loadBuffer(3);
			_sound.play("e");
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			ifEPressed = false;
		}

		// PRESSING R
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && ifFPressed == false)
		{
			ifFPressed = true;

			_sound.loadBuffer(4);
			_sound.play("f");
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			ifFPressed = false;
		}

		// PRESSING T
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::T) && ifGPressed == false)
		{
			ifGPressed = true;

			_sound.loadBuffer(5);
			_sound.play("g");
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			ifGPressed = false;
		}

		// PRESSING Y
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && ifAPressed == false)
		{
			ifAPressed = true;

			_sound.loadBuffer(6);
			_sound.play("a");
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			ifAPressed = false;
		}

		// PRESSING U
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::U) && ifBPressed == false)
		{
			ifBPressed = true;
			
			_sound.loadBuffer(7);
			_sound.play("b");
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			ifBPressed = false;
		}

		// PRESSING I
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && ifSWavePressed == false)
		{
			ifSWavePressed = true;

			_sound.play("k");
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			ifSWavePressed = false;
		}

		const int VELOCITY = 45;

		const int MOUNTAINS_SPEED = VELOCITY/3;
		const int FAR_MOUNTAINS_SPEED = VELOCITY/4;
		const int TREES_SPEED = VELOCITY;
		const int FAR_TREES_SPEED = VELOCITY/2;

		_mainMountains.moveObject(_mainMountainsBackground,dt,MOUNTAINS_SPEED);
		_mainTrees.moveObject(_mainTreesBackground,dt,TREES_SPEED);
		_mainFarMountains.moveObject(_mainFarMountainsBackground,dt,FAR_MOUNTAINS_SPEED);
		_mainFarTrees.moveObject(_mainFarTreesBackground,dt,FAR_TREES_SPEED);
		_mainFarTrees.moveObject(_jimRulz,dt,FAR_TREES_SPEED);
	}

	//This updates the window for the objects
	void PlayingState::update(double dt)
	{
		_mainMountains.updateObject(_mainMountainsBackground);
		_mainTrees.updateObject(_mainTreesBackground);
		_mainFarMountains.updateObject(_mainFarMountainsBackground);
		_mainFarTrees.updateObject(_mainFarTreesBackground);
		_jimRulzSprite.updateObject(_jimRulz);
	}

	//This draws to the screen
	void PlayingState::draw()
	{
		_mainSunsetBackground.draw();
		_mainFarMountains.drawObject(_mainFarMountainsBackground);
		_mainMountains.drawObject(_mainMountainsBackground);
		_mainFarTrees.drawObject(_mainFarTreesBackground);
		_mainTrees.drawObject(_mainTreesBackground);
		_jimRulzSprite.drawObject(_jimRulz);
	}
}
