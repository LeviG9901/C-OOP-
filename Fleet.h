#pragma once
#include "StarDestroyer.h"
#include <vector>
#include <string>
#include <iostream>
#include "Imperial.h"
#include "Executor.h"

class Fleet
{
protected:
	std::vector<StarDestroyer*> stardestroyers;
	int reservecrew = 0;
public:
	void addStarDestroyer(StarDestroyer* stardest);
	StarDestroyer* getStarDestroyer(std::string Name);
	int getQuantity();
	void addReserveCrew(int number);
	int getReserveCrew();
	void addCrew(std::string name, int number);
	void addCrew(StarDestroyer* nev, int number);
	void addToReserve(std::string name, int number);
	int getPersonnel();
	StarDestroyer* checkImmobility();
	bool addCrewChecked(StarDestroyer* name, int number);
	bool addToReserveChecked(StarDestroyer* name, int number);
	bool removeReserveChecked(int number);
	bool addStarDestroyerChecked(StarDestroyer* stdest);
	StarDestroyer* getStarDestroyerByNum(int num);
	//std::vector<StarDestroyer*>GetStarDestroyers();
};
std::ostream& operator<<(std::ostream&, Fleet&);