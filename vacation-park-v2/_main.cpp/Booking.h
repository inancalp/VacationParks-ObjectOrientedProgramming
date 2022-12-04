
#ifndef BOOKING_H
#define BOOKING_H
#include "Accomodations.h"
#include "Customer.h"
class Booking 
{
private:
	int m_id;
	Customer* m_customer;
	vector<Accomodations*> m_accomodations;
	bool m_activityPass;
	bool m_sportsPass;
	bool m_bicycleRent;
	bool m_swimmingPass;

public: // (?) const for every param
	Booking(
		const int& id,
		Customer* customer,
		vector<Accomodations*> accomodations,
		const bool& activity_pass,
		const bool& sports_pass,
		const bool& bicycle_rent,
		const bool& swimming_pass
	);
	~Booking();

	void setId(const int& id);
	void setCustomer(Customer* customer);
	void setAccomodations(vector<Accomodations*>& accomodations);
	void setActivityPass(const bool& activity_pass);
	void setSportPass(const bool& sport_pass);
	void setBicycleRent(const bool& bicycle_rent);
	void setSwimmingPass(const bool& swimming_pass);

	const int& getId() const;
	Customer* getCustomer() const;
	vector<Accomodations*>& getAccomodations();
	const bool& getActivityPass() const;
	const bool& getSportPass() const;
	const bool& getBicycleRent() const;
	const bool& getSwimmingPass() const;

	string toString();

};

#endif //BOOKING_H

