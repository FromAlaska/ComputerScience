// Main.cpp
// Jim Samson
// September 15, 2017
//
// This starts a game loop
// It can be used to start the game of the game

#include "ResourcePath.hpp"
#include "GameLoop.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	Game game;
	game.gameLoop(); // Starts the game loop

    return EXIT_SUCCESS;
}
void printChar(char yes)
{
	std::cout << yes << std::endl;
}
