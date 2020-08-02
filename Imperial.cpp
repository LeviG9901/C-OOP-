#include "Imperial.h"

Imperial::Imperial(std::string ImpName, int crewnum, int lasernum):StarDestroyer(ImpName, 45000, 29000, crewnum, 80, 40, lasernum)
{

};

double Imperial::move()
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

int Imperial::firepower()
{
	if (actcrew >= mincrew && actcrew <= maxcrew)
	{
		return 100*actlaser;
	}
	else
	{
		return 0;
	}
}