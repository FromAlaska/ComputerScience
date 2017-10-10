//
//  MusicManager.cpp
//  Frontier
//
//  Created by Jim Samson on 10/5/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "MusicManager.hpp"

void Sound::loadMusicFile(string & musicName)
{
	if(!_music.openFromFile(resourcePath() + musicName))
	{ cout << "Cannot load music file" << endl; }
}

void Sound::playMusic()
{
}
