
#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Booking.h"

class Customer {

private:
	string Name;
	string Address;
	string Email;

public:
	//vector<Booking*> Bookings; // best way to handle?

	Customer(const string& name, const string& address, const string& email);

	~Customer();

	void setName(const string& name);

	void setAddress(const string& address);

	void setEmail(const string& email);

	const string& getName() const;

	const string& getAddress() const;

	const string& getEmail() const;
	
	const string& customerToString() const; // change toString()
};

#endif //CUSTOMER_H

//Customer::Customer
//(
//	const string& name,
//	const string& address,
//	const string& email
//)
//	: Name(name), Address(address), Email(email), Bookings(bookings)
//{
//	cout << "Customer::Constructor ->> " << this->getName() << " created." << endl;
//}