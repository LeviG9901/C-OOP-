#pragma once
#include "StarDestroyer.h"

class Imperial : public StarDestroyer
{
private:
	const double speed = 1.0;
public:
	Imperial(std::string ImpName, int crewnum, int lasernum);
	double move();
	int firepower();
};