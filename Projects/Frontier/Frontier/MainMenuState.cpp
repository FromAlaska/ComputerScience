//
//  MinMenuState.cpp
//  Frontier
//
//  Created by Jim Samson on 9/8/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "MainMenuState.hpp"

namespace State
{
	MainMenuState::MainMenuState(Game& game) : GameState(game)
	{
		int ELEMENT_SIZE = 2;
		_mainMountainsBackground.resize(ELEMENT_SIZE);
		_mainTreesBackground.resize(ELEMENT_SIZE);
		_mainFarMountainsBackground.resize(ELEMENT_SIZE);
		_mainFarTreesBackground.resize(ELEMENT_SIZE);

		// Loads the texture
		_mainSunsetBackground.loadTexture("parallax-mountain-bg.png", 1, 1, 0, 0);
		_mainMountains.loadTexture(_mainMountainsBackground, "parallax-mountain-mountains.png");
		_mainTrees.loadTexture(_mainTreesBackground,"parallax-mountain-foreground-trees.png");
		_mainFarMountains.loadTexture(_mainFarMountainsBackground, "parallax-mountain-mountain-far.png");
		_mainFarTrees.loadTexture(_mainFarTreesBackground, "parallax-mountain-trees.png");

		// Opens the music file
		_sound.playMusicFile("MainMenu.wav");

		// Sets text to screen
		_titleText.loadFont("Times.dfont");
		_titleText.setPosition(272/2 - 120/3, 0);
		_titleText.setText("Frontier",120);

		_enterToStart.loadFont("Times.dfont");
		_enterToStart.setPosition(272/2-120/2.5, 26);
		_enterToStart.setText("Press Enter to Start", 60);

	}

	// This gets keyboard input
	void MainMenuState::input(sf::Time dt)
	{
		Display::setView(272/2, 160/2, 272, 160);
		//Display::setView(0,0,Display::Width,Display::Height);

		const int VELOCITY = 45;

		const int MOUNTAINS_SPEED = VELOCITY/3;
		const int FAR_MOUNTAINS_SPEED = VELOCITY/4;
		const int TREES_SPEED = VELOCITY;
		const int FAR_TREES_SPEED = VELOCITY/2;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			_game->pushState(std::make_unique<State::PlayingState>(*_game));
			_sound.stopMusic();
		}

		_mainMountains.moveObject(_mainMountainsBackground,dt,MOUNTAINS_SPEED);
		_mainTrees.moveObject(_mainTreesBackground,dt,TREES_SPEED);
		_mainFarMountains.moveObject(_mainFarMountainsBackground,dt,FAR_MOUNTAINS_SPEED);
		_mainFarTrees.moveObject(_mainFarTreesBackground,dt,FAR_TREES_SPEED);
	}

	//This updates the window for the objects
	void MainMenuState::update(double dt)
	{
		_mainMountains.updateObject(_mainMountainsBackground);
		_mainTrees.updateObject(_mainTreesBackground);
		_mainFarMountains.updateObject(_mainFarMountainsBackground);
		_mainFarTrees.updateObject(_mainFarTreesBackground);
	}

	//This draws to the screen
	void MainMenuState::draw()
	{
		_mainSunsetBackground.draw();
		_mainFarMountains.drawObject(_mainFarMountainsBackground);
		_mainMountains.drawObject(_mainMountainsBackground);
		_mainFarTrees.drawObject(_mainFarTreesBackground);
		_mainTrees.drawObject(_mainTreesBackground);
		
		_titleText.draw();
		_enterToStart.draw();

	}
}
