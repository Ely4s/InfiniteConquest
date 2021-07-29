//
// Created by Elyas EL IDRISSI on 08/03/2021.
//

#include "Random.h"
#include <random>

int Random::intBetween(int min, int max)
{
	if (Random::isInit) {Random::isInit = true; srand((unsigned int)time(NULL));}
	return (max == min || min > max) ? 0 : (rand() % (max - min + 1)) + min;
}

