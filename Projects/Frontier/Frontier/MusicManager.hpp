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

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio.hpp>

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

class Sound
{
public:
	void loadMusicFile(string&);
	void playMusic();

private:
	sf::Music _music;
	sf::Music *_musicPtr;
};

#endif /* MusicManager_hpp */
