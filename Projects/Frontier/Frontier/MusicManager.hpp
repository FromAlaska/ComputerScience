//
//  MusicManager.hpp
//  Frontier
//
//  Created by Jim Samson on 10/5/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef MusicManager_hpp
#define MusicManager_hpp

#include "ResourcePath.hpp"

#include <vector>
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <random>
#include <time.h>

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio.hpp>

class Sound
{
public:

	Sound()
	{
		string _mainMenu = "MainMenu.wav";
		string _simpleMusic = "Simple.wav";
		string _beepBoop = "beepBoop.wav";
		string _interesting = "interesting.wav";

		srand(time(NULL));

		int random = rand() % 4 + 1;

		switch(random)
		{
			case 1:
				playthis = _mainMenu;
				break;
			case 2:
				playthis = _simpleMusic;
				break;
			case 3:
				playthis = _beepBoop;
				break;
			case 4:
				playthis = _interesting;
				break;
			default:
				playthis = _mainMenu;
		}
	}

	void playMusicFile(const string&&);
	void stopMusic();

private:
	sf::Music _music;
	std::vector<string> _randomMusic;

	string playthis;
};

#endif /* MusicManager_hpp */
