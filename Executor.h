#pragma once
#include "StarDestroyer.h"

class Executor : public StarDestroyer
{
private:
	const double speed = 1.5;
	const int maxion;
	const int minion;
	int action;
public:
	Executor(std::string ExeName, int crewnum, int lasernum, int ionnum);
	double move();
	int firepower();
};