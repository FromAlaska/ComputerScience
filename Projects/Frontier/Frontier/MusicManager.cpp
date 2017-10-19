//
//  MusicManager.cpp
//  Frontier
//
//  Created by Jim Samson on 10/5/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "MusicManager.hpp"

void Sound::playMusicFile(const string && musicName)
{
	if(!_music.openFromFile(resourcePath() + playthis))
	{ cout << "Cannot load music file" << endl; }
	
	_music.play();
	_music.setLoop(true);
}
void Sound::stopMusic()
{
	_music.stop();
}
