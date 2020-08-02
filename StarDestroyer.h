#pragma once

#include <string>
#include <iostream>
using namespace std;

class StarDestroyer
{
protected:
	string name; //Name of the StarDestroyer
	const int maxcrew; //Maximum Crew Number
	const int mincrew; //Minimum Crew Number
	int actcrew; //Actual Crew Number
	const int maxlaser; //Maximum Laser Number
	const int minlaser; //Minimum Laser Number
	int actlaser; //Actual Laser Number
public:
	StarDestroyer(string Name, int maxcrewnum, int mincrewnum, int actcrewnum, int maxlasernum, int minlasernum, int actlasernum);
	void addCrew(int number);
	void removeCrew(int number);
	unsigned int getCrew() const;
	string getName() const;
	void addCrew(const unsigned int crewnumber);
	void removeCrew(const unsigned int crewnumber);
	bool checkOperational() const;
	unsigned int getMaxCrew() const;
	unsigned int getMinCrew() const;
	bool operator==(StarDestroyer& other);
};
std::ostream& operator<<(std::ostream&, const StarDestroyer&);