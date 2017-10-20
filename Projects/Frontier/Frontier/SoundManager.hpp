//
//  SoundManager.hpp
//  Frontier
//
//  Created by Jim Samson on 10/17/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef SoundManager_hpp
#define SoundManager_hpp

#include "ResourcePath.hpp"

#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <cmath>
#include <string>
using std::string;

#include <SFML/Audio.hpp>

extern "C" short * squareWaveGenerator(int);
extern "C" short * cWaveGenerator();

class SoundManager
{
public:
	SoundManager()
	{
		_soundSf.resize(7);
		_buffer.resize(7);
		_wave.resize(7);

		sineWave();
	}
	void loadBuffer(int);
	void play(string &&);
	void sineWave();

	const unsigned SAMPLES = 44100;
	const unsigned SAMPLE_RATE = 44100;
	const unsigned AMPLITUDE = 30000;
	
	std::vector<sf::SoundBuffer> _buffer;
	std::vector<sf::Sound> _soundSf;
	std::vector<short> _wave;

	sf::SoundBuffer _bufferSineWave;
	sf::Sound _soundSine;

private:
	
	int16_t _raw[44100];
};

#endif /* SoundManager_hpp */
