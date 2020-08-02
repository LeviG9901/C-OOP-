#include "Fleet.h"

void Fleet::addStarDestroyer(StarDestroyer* stardest)
{
	stardestroyers.push_back(stardest);
}

StarDestroyer * Fleet::getStarDestroyer(std::string Name)
{
	for (int i = 0; i < stardestroyers.size();i++)
	{
		if (stardestroyers[i] -> getName() == Name)
		{
			return stardestroyers[i];
		}
	}
	return nullptr;
}

int Fleet::getQuantity()
{
	return stardestroyers.size();
}

void Fleet::addReserveCrew(int number)
{
	reservecrew += number;
}

int Fleet::getReserveCrew()
{
	return reservecrew;
}

void Fleet::addCrew(std::string name,int number)
{
	for (int i = 0; i < stardestroyers.size(); i++)
	{
		if (stardestroyers[i] -> getName() == name)
		{
			stardestroyers[i]->addCrew(number);
			reservecrew -= number;
		}
	}
}

void Fleet::addCrew(StarDestroyer* name, int number)
{
	for (int i = 0; i < stardestroyers.size(); i++)
	{
		if (stardestroyers[i]->getName() == name->getName())
		{
			stardestroyers[i]->addCrew(number);
			reservecrew -= number;
		}
	}
}

void Fleet::addToReserve(std::string name, int number)
{
	for (int i = 0; i < stardestroyers.size(); i++)
	{
		if (stardestroyers[i]->getName() == name)
		{
			stardestroyers[i]->removeCrew(number);
			reservecrew += number;
		}
	}
}

int Fleet::getPersonnel()
{
	int sum = 0;
	for (int i = 0; i < stardestroyers.size(); i++)
	{
		sum += stardestroyers[i]->getCrew();
	}
	sum += reservecrew;
	return sum;
}

StarDestroyer* Fleet::checkImmobility()
{
	for (int i = 0; i < stardestroyers.size(); i++)
	{
		if (!stardestroyers[i]->checkOperational())
		{
			return stardestroyers[i];
		}
		
	}
	return nullptr;
}

bool Fleet::addCrewChecked(StarDestroyer* name, int number)
{
	for (int i = 0; i < stardestroyers.size(); i++)
	{
		if (stardestroyers[i]->getName() == name->getName() && ( ((stardestroyers[i]->getCrew()+number) <= (name->getMaxCrew())) && (getReserveCrew()-number > 0) ))
		{
			stardestroyers[i]->addCrew(number);
			reservecrew -= number;
			return true;
		}
	}
	return false;
}

bool Fleet::addToReserveChecked(StarDestroyer* name, int number)
{
	for (int i = 0; i < stardestroyers.size(); i++)
	{
		if (stardestroyers[i]->getName() == name->getName() && (((name->getCrew()-number) >= (name->getMinCrew()))))
		{
			stardestroyers[i]->removeCrew(number);
			reservecrew += number;
			return true;
		}
	}
	return false;
}

bool Fleet::removeReserveChecked(int number)
{
	if ((getReserveCrew()-number)>=0)
	{
		reservecrew -= number;
		return true;
	}
	return false;
}

bool Fleet::addStarDestroyerChecked(StarDestroyer* stdest)
{
	for (int i = 0; i < stardestroyers.size(); i++)
	{
		if (*stardestroyers[i] == *stdest)
		{
			stardestroyers[i]->addCrew(stdest->getCrew());
			return true;
		}
	}
	stardestroyers.push_back(stdest);
}

StarDestroyer* Fleet::getStarDestroyerByNum(int num)
{
	return stardestroyers[num];
};

std::ostream& operator<<(std::ostream& out, Fleet& fl)
{
	out << "Fleet: \n";
	for (int i = 0; i < fl.getQuantity(); i++) {
		out << *(fl.getStarDestroyerByNum(i)) << "\n";
	}
	return out;
}