#ifndef LUXURYLEVEL_H
#define LUXURYLEVEL_H

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class LuxuryLevel {
private:
	bool m_bbq;
	bool m_surroundSystem;
	bool m_breakfastService;
	bool m_cleaningService;
	string m_accomodationKind;
public:
	LuxuryLevel(
		const bool bbq,
		const bool surround_system,
		const bool breakfast_service,
		const bool cleaning_service,
		const string accomodation_kind
	);
	~LuxuryLevel();

	const bool& getBbq() const;
	const bool& getSurroundSystem() const;
	const bool& getBreakfastService() const;
	const bool& getCleaningService() const;
	const string& getAccomodationKind() const;

	void setBbq(const bool& bbq);
	void setSurroundSystem(const bool& surrond_system);
	void setBreakfastService(const bool& breakfast_service);
	void setCleaningService(const bool& cleaning_service);
	void setAccomodationKind(const string& accomodation_kind);

	const string toString() const;
};


#endif // !LUXURYLEVEL_H
