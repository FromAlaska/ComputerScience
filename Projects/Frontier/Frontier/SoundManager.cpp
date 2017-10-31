//
//  SoundManager.cpp
//  Frontier
//
//  Created by Jim Samson on 10/17/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "SoundManager.hpp"

void SoundManager::loadBuffer(int waveInt)
{
	//_raw[SAMPLES];

	int iterator = 0;
	int waveForm = 25;

	for(auto index = _wave.begin(); index != _wave.end(); ++index)
	{
		if(!_buffer[iterator].loadFromSamples(squareWaveGenerator(waveInt), SAMPLES, 1, SAMPLE_RATE))
		{std::cout << "cannot load buffer" << std::endl;}
		
		_soundSf[iterator].setBuffer(_buffer[iterator]);

		waveForm += 5;
		++iterator;
	}
}

void SoundManager::sineWave()
{
	const double increment = 440./44100;
	double x = 0;

	for (unsigned i = 0; i < SAMPLES; i++)
	{
		//_raw[i] = AMPLITUDE/2 * sin(x*sin(x/20));
		_raw[i] = AMPLITUDE * sin(x*2*M_PI);
		//_raw[i] = AMPLITUDE/2 * sin(x*(M_PI*2)*sin(x/1000));
		//_raw[i] = AMPLITUDE * sin(((2*M_PI)*x*(5/4)));
		x += increment;

		if(i > 5000)
		{
			//_raw[i] += _raw[i-5000]/2;
		}
	}
	
	if(!_bufferSineWave.loadFromSamples(_raw, SAMPLES, 1, SAMPLE_RATE))
	{std::cout << "cannot load raw sine input" << std::endl;}

	_soundSine.setBuffer(_bufferSineWave);
}

void SoundManager::play(string && character)
{

	if(character == "c")
	{
		_soundSf[0].play();
	}

	if(character == "d")
	{
		_soundSf[1].play();
	}

	if(character == "e")
	{
		_soundSf[2].play();
	}

	if(character == "f")
	{
		_soundSf[3].play();
	}

	if(character == "g")
	{
		_soundSf[4].play();
	}

	if(character == "a")
	{
		_soundSf[5].play();
	}

	if(character == "b")
	{
		_soundSf[6].play();
	}

	if(character == "k")
	{
		_soundSine.play();
	}
}
