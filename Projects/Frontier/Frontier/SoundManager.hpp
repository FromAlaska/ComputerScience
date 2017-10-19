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

#include <SFML/Audio.hpp>

extern "C" short *woopSound();

class SoundManager
{
public:
	SoundManager()
	{
		_ptr = woopSound();

		int16_t _raw[SAMPLES];

		const double increment = 440./44100;
		double x = 0;

		for (unsigned i = 0; i < SAMPLES; i++)
		{
			_raw[i] = AMPLITUDE * sin(x*sin(x/20));
			//_raw[i] = AMPLITUDE/2 * sin(x*(M_PI*2)*sin(x/1000));

			//_raw[i] = AMPLITUDE * sin(((2*M_PI)*x*(5/4)));
			x += increment;

//			if(i > 5000)
//			{
//				//_raw[i] += _raw[i-5000]/2;
//			}
		}

		if(!_buffer.loadFromSamples(_ptr, SAMPLES, 1, SAMPLE_RATE))
		{std::cout << "Could not load buffer" << std::endl;}

		_soundSf.setBuffer(_buffer);
		_soundSf.setLoop(true);
	}

	void loadBuffer();
	void play();

	~SoundManager()
	{
		delete[] _ptr;
	}

	const unsigned SAMPLES = 44100;
	const unsigned SAMPLE_RATE = 44100;
	const unsigned AMPLITUDE = 30000;

private:
	sf::SoundBuffer _buffer;
	sf::Sound _soundSf;

	short *_ptr;
};

#endif /* SoundManager_hpp */
