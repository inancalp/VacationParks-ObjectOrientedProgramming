
#ifndef BOOKING_H
#define BOOKING_H


using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Booking 
{
private:
	int m_id;
	vector<string> m_accomodations;
	bool m_activityPass;
	bool m_sportsPass;
	bool m_bicycleRent;
	bool m_swimmingPass;

public:
	Booking(
		const int& id,
		const vector<string>& accomodations,
		const bool& activity_pass,
		const bool& sports_pass,
		const bool& bicycle_rent,
		const bool& swimming_pass
	);
	~Booking();

	void setId(const int& id);
	void setAccomodations(const vector<string>& accomodations);
	void setActivityPass(const bool& activity_pass);
	void setSportPass(const bool& sport_pass);
	void setBicycleRent(const bool& bicycle_rent);
	void setSwimmingPass(const bool& swimming_pass);

	const int& getId() const;
	const vector<string>& getAccomodations() const;
	const bool& getActivityPass() const;
	const bool& getSportPass() const;
	const bool& getBicycleRent() const;
	const bool& getSwimmingPass() const;

	const string toString() const;

};

#endif //BOOKING_H

