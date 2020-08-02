// You choose which level you want with (0 and 1)
#define LEVEL_2 1
#define LEVEL_3 1
#define LEVEL_4 1
#define LEVEL_5 1

// It is neccessary to be turned off if you are doing developements
#define CHECK 1

// Libraries used by tests
#include <iostream>
#include <cassert>
#include "StarDestroyer.h"
#include "Imperial.h"
#include "Executor.h"
#include "Fleet.h"
int main()
{
	std::cout << "VIZSGA 2020-01-14\n";

#if LEVEL_2
	std::cout << "------- LEVEL 2 -----------\n";
	// Making StarDestroyers
	Imperial* vehement = new Imperial("Vehement", 37000, 80);
	Imperial* exactor = new Imperial("Exactor", 32000, 70);
	Imperial* devastator = new Imperial("Devastator", 28000, 35);
	Executor* executor = new Executor("Executor", 290000, 2500, 250);
#if CHECK
	// Checking Star Destroyers
	std::cout << "Vehement crew: " << vehement->getCrew() << ",\t Expected: 37 000\n";
	assert(vehement->getCrew() == 37000);
	std::cout << "Executor crew: " << exactor->getCrew() << ",\t Expected: 32 000\n";
	assert(exactor->getCrew() == 32000);
	std::cout << "Devastator crew: " << devastator->getCrew() << ",\t Expected: 28 000\n";
	assert(devastator->getCrew() == 28000);
	std::cout << "Executor crew: " << executor->getCrew() << ",\t Expected: 290 000\n";
	assert(executor->getCrew() == 290000);
	// Adding Crew (Vehement)
	vehement->addCrew(1000);
	std::cout << "Vehement crew (+1000): " << vehement->getCrew() << ",\t Expected: 38000\n";
	assert(vehement->getCrew() == 38000);
	vehement->removeCrew(1000);
	std::cout << "Vehement crew (-1000): " << vehement->getCrew() << ",\t Expected: 37000\n";
	assert(vehement->getCrew() == 37000);
	// Adding Crew (Executor)
	executor->addCrew(1000);
	std::cout << "Executor crew (+1000): " << executor->getCrew() << ",\t Expected: 291 000\n";
	assert(executor->getCrew() == 291000);
	executor->removeCrew(1000);
	std::cout << "Executor crew (-1000): " << executor->getCrew() << ",\t Expected: 290 000\n";
	assert(executor->getCrew() == 290000);
	// Checking Movement
	std::cout << "Vehement warp-speed: " << vehement->move() << ", Expected: 1.0\n";
	assert(vehement->move() == 1.0);
	std::cout << "Exactor warp-speed: " << vehement->move() << ", Expected: 1.0\n";
	assert(exactor->move() == 1.0);
	std::cout << "Devastator warp-speed: " << vehement->move() << ", Expected: 0.0\n";
	assert(devastator->move() == 0.0);
	std::cout << "Executor warp-speed: " << vehement->move() << ", Expected: 1.5\n";
	assert(executor->move() == 1.5);
	// Checking Fire Power
	assert(vehement->firepower() == 100 * 80);
	assert(exactor->firepower() == 100 * 70);
	assert(devastator->firepower() == 0);
	assert(executor->firepower() == 150 * 2500 + 250 * 1000);
	// Checking Assist Methods
	assert(vehement->getMinCrew() == 29000);
	assert(vehement->getMaxCrew() == 45000);
	assert(executor->getMinCrew() == 50000);
	assert(executor->getMaxCrew() == 350000);
	// Check if Operational
	std::cout << "Vehement operational: " << vehement->checkOperational() << ",\t Elvart: 1\n";
	assert(vehement->checkOperational());
	std::cout << "Exactor operational: " << exactor->checkOperational() << ",\t Elvart: 1\n";
	assert(exactor->checkOperational());
	std::cout << "Devastator operational: " << devastator->checkOperational() << ",\t Elvart: 0\n";
	assert(!devastator->checkOperational());
	std::cout << "Executor operational: " << executor->checkOperational() << ",\t Elvart: 1\n";
	assert(executor->checkOperational());
#endif
	// Making Fleet
	Fleet fleet;
#if CHECK
	assert(fleet.getReserveCrew() == 0);
#endif
	// Adding StarDestroyers
	fleet.addStarDestroyer(vehement);
	fleet.addStarDestroyer(exactor);
	fleet.addStarDestroyer(devastator);
	fleet.addStarDestroyer(executor);
	// Reading out StarDestroyers
#if CHECK
	assert(fleet.getStarDestroyer("Vehement") != nullptr);
	assert(fleet.getStarDestroyer("Executor") != nullptr);
	assert(fleet.getStarDestroyer("Exactor") != nullptr);
	assert(fleet.getStarDestroyer("Devastator") != nullptr);
	assert(fleet.getStarDestroyer("Millenium Falcon") == nullptr);
	assert(fleet.getStarDestroyer("Vindicator") == nullptr);
#endif
	// Add Reserve Crew to Fleet
	fleet.addReserveCrew(20000);
#if CHECK
	std::cout << "The given Reserce Crew to this Fleet: " << fleet.getReserveCrew() << ", Expected: 20 000\n";
	assert(fleet.getReserveCrew() == 20000);
#endif
	// Check Fleet
#if CHECK
	std::cout << "Ships in the Fleet: " << fleet.getQuantity() << ", Expected: 4\n";
	assert(fleet.getQuantity() == 4);
	std::cout << "\n";
#endif

	std::cout << "Vehement crew (-1000): " << vehement->getCrew() << ",\t Expected: 37000\n";

#if LEVEL_3	
	std::cout << "-------   LEVEL 3 -----------\n";
	fleet.addCrew("Executor", 10000);
	std::cout << "Vehement crew (-1000): " << vehement->getCrew() << ",\t Expected: 37000\n";
	fleet.addCrew(vehement, 1000);
#if CHECK
	std::cout << "Vehement adding crew from reserve: (+1000): " << vehement->getCrew() << ", Expected: 38 000\n";
	assert(vehement->getCrew() == 38000);
	std::cout << "Executor adding crew from reserve: (+10000): " << executor->getCrew() << ", Expected: 300 000\n";
	assert(executor->getCrew() == 300000);
	std::cout << "Remained reserve crew " << fleet.getReserveCrew() << ", 9 000\n";
	assert(fleet.getReserveCrew() == 9000);
#endif
	fleet.addToReserve("Executor", 10000);
#if CHECK
	// After added to reserve
	std::cout << "Adding crew to reserve from executor (-10000): " << executor->getCrew() << ", Expected: 290 000\n";
	assert(executor->getCrew() == 290000);
	assert(fleet.getReserveCrew() == 19000);
#endif
	// Checking the neccessary crew
	std::cout << "The neccessary crew supply to fleet: " << fleet.getPersonnel() << ", Expected: 407 000\n";
#if CHECK
	assert(fleet.getPersonnel() == 407000);
#endif
	std::cout << "\n";
#endif // LEVEL_3


#if LEVEL_4
	std::cout << "-------   LEVEL 4 -----------\n";
	// Check if the fleet can operating
	std::cout << "The fleet is not operating, because this ship doesn't have the neccessary crew: " << fleet.checkImmobility()->getName() << '\n';
#if CHECK
	assert(fleet.checkImmobility() != nullptr);
	assert(fleet.checkImmobility() == devastator);
#endif
	// Error search checking
	std::cout << "Checking if the processes are sufficient: " << '\n';
	bool success;

	success = fleet.addCrewChecked(vehement, 15000);
	assert(!success); // Too much crew

	success = fleet.addCrewChecked(executor, 25000);
	assert(!success); // Not enough reservecrew

	success = fleet.addToReserveChecked(executor, 250000);
	assert(!success); // The crew would be less then minimal

	success = fleet.removeReserveChecked(90000);
	assert(!success); // Not enough reservecrew

	// After the test of methodes give crew one of the working ship
	// Check if the fleet can be operated
	std::cout << "Give Devastator the exact needed crew: (+2000)\n";
	success = fleet.addCrewChecked(devastator, 2000);
	assert(success);
	std::cout << "Devastator crew: " << devastator->getCrew() << ", Expected: 30 000\n";
	assert(devastator->getCrew() == 30000);
#if CHECK
	assert(fleet.checkImmobility() == nullptr);

	std::cout << "The Fleet works, every ship can be operated!" << '\n';
	std::cout << "\n";
#endif
#endif // LEVEL_4


#if LEVEL_5
	std::cout << "-------   LEVEL 5 -----------\n";
	Imperial* vehement2 = new Imperial("Vehement", 2000, 80);
	assert(*vehement == *vehement2);
	fleet.addStarDestroyerChecked(vehement2);
#if CHECK
	std::cout << "Shipnumber of the fleet: " << fleet.getQuantity() << ", Expected: 4\n";
	assert(fleet.getQuantity() == 4);
	std::cout << "Vehement crew (+2000): " << vehement->getCrew() << ", Expected: 40000 \n";
	assert(vehement->getCrew() == 40000);
#endif
	std::cout << *vehement << '\n';
	std::cout << *executor << '\n';
	std::cout << fleet;
	std::cout << "\n";
	delete vehement2;
#endif // LEVEL_5


	delete vehement;
	delete exactor;
	delete devastator;
	delete executor;

#endif // LEVEL_2
	return 0;
}