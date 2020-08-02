#include "StarDestroyer.h"

StarDestroyer::StarDestroyer(std::string Name, int maxcrewnum, int mincrewnum, int actcrewnum, int maxlasernum, int minlasernum, int actlasernum)
	: name(Name), maxcrew(maxcrewnum), mincrew(mincrewnum), actcrew(actcrewnum), maxlaser(maxlasernum), minlaser(minlasernum), actlaser(actlasernum)
{};


void StarDestroyer::addCrew(int number)
{
	actcrew += number;
}

void StarDestroyer::removeCrew(int number)
{
	actcrew -= number;
}

unsigned int StarDestroyer::getCrew() const
{
	return actcrew;
}

string StarDestroyer::getName() const
{
	return name;
}

void StarDestroyer::addCrew(const unsigned int crewnumber)
{
	actcrew += crewnumber;
}

void StarDestroyer::removeCrew(const unsigned int crewnumber)
{
	actcrew -= crewnumber;
}

bool StarDestroyer::checkOperational() const
{
	if (actcrew>=mincrew)
	{
		return true;
	}
	else
	{
		return false;
	}
}

unsigned int StarDestroyer::getMaxCrew() const
{
	return maxcrew;
}

unsigned int StarDestroyer::getMinCrew() const
{
	return mincrew;
}

bool StarDestroyer::operator==(StarDestroyer& other)
{
	return getName() == this->getName();
}

std::ostream& operator<<(std::ostream& out, const StarDestroyer& stdest)
{
	out << "Name:" << stdest.getName() << " Crew:" << stdest.getCrew() << " Minimum Crew:" << stdest.getMinCrew() << " Max. legenyseg:" << stdest.getMaxCrew();
	return out;
}