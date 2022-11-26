
#ifndef BOOKING_H
#define BOOKING_H

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"

class Booking {

private:
	int Id = -1;
	Customer _Customer;
	vector<int> Accomodations{};
	bool activityPass = false;
	bool sportsPass = false;
	bool bicycleRent = false;
	bool swimmingPass = false;

public:
	Booking(
		const int& id,
		const Customer& customer,
		const vector<int>& accomodations, //
		const bool& activity_pass,
		const bool& sports_pass,
		const bool& bicycle_rent,
		const bool& swimming_pass
	);

	void setId(const int& id);
	void setCustomer(const Customer& customer);
	void setAccomodations(const vector<int>& accomodations);
	void setActivityPass(const bool& activity_pass);
	void setSportPass(const bool& sport_pass);
	void setBicycleRent(const bool& bicycle_rent);
	void setSwimmingPass(const bool& swimming_pass);

	const int& getId() const;
	const Customer& getCustomer() const;
	const vector<int>& getAccomodations() const;
	const bool& getActivityPass() const;
	const bool& getSportPass() const;
	const bool& getBicycleRent() const;
	const bool& getSwimmingPass() const;
};

#endif //BOOKING_H

