#ifndef LUXURYLEVEL_H
#define LUXURYLEVEL_H

using namespace std;
#include <string>
#include <iostream>

class LuxuryLevel
{
private:
	bool Bbq = false;
	bool SurroundSystem = false;
	bool BreakfastService = false;
	bool CleaningService = false;
	string AccomodationKind = "N/A";

public:
	LuxuryLevel();
	~LuxuryLevel();

	void setBbq(bool bbq);
	void setSurroundSystem(const bool surround_system); // (?)&
	void setBreakfastService(const bool breakfast_service); // (?)&
	void setCleaningService(const bool cleaning_service); // (?)&
	void setAccomodationKind(const string accomodation_kind); // (?)&

	const bool& getBbq() const;
	const bool& getSurroundSystem() const;
	const bool& getBreakfastService() const;
	const bool& getCleaningService() const;
	const string& getAccomodationKind() const;
};

#endif // LUXURYLEVEL_H
