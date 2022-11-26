#ifndef VACATION_PARK_H
#define VACATION_PARK_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Accomodation.h"
using namespace std;

class VacationParcs {

private:
	string Name;
	string Address;
	string Vat;
	vector<int> Parks{};
	vector<int> Customers{};
	vector<int> Bookings{}; // (?) should be deleted.
	
public:
	vector<Accomodation*> Accomodations{}; // (alpha state object vector)
	// (?) what's the proper way to construct this class?
	VacationParcs(string, string, string);
	~VacationParcs();
	void addCustomer(const int& customer_id); // (!) should be gone to library
	const void getCustomers() const;

	void setName(const string name);
	void setAddress(const string address);
	void setVat(const string vat);

	const string& getName() const;
	const string& getAddress() const;
	const string& getVat() const;

	const string toString() const;

	const string getAccomodations() const;
};

#endif