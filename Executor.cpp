#include "Executor.h"

Executor::Executor(std::string ExeName, int crewnum, int lasernum, int ionnum):StarDestroyer(ExeName, 350000, 50000, crewnum, 2500, 1500, lasernum), maxion(300), minion(200),
action(ionnum)
{};

double Executor::move()
{
	if (actcrew >= mincrew && actcrew <= maxcrew)
	{
		return speed;
	}
	else
	{
		return 0.0;
	}
}

int Executor::firepower()
{
	if (actcrew >= mincrew && actcrew <= maxcrew)
	{
		return 150*actlaser+1000*action;
	}
	else
	{
		return 0;
	}
}