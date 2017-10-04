// Main.cpp
// Jim Samson
// September 15, 2017
//
// This starts a game loop
// It can be used to start the game of the game

#include "ResourcePath.hpp"
#include "MainLoop.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	Game game;
	game.gameLoop(); // Starts the game loop

    return EXIT_SUCCESS;
}
