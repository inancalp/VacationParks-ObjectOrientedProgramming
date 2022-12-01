
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Booking.h"

class Customer {

private:
	string m_name;
	string m_address;
	string m_email;
	vector<Booking*> m_bookings;

public:

	Customer(string& name, string& address, string& email);

	~Customer();

	void setName(const string& name);

	void setAddress(const string& address);

	void setEmail(const string& email);

	void setBooking(Booking* booking);

	const string& getName() const;

	const string& getAddress() const;

	const string& getEmail() const;

	const vector<Booking*>& getBookings() const;

	const string toString() const; // change toString()

	
};

#endif //CUSTOMER_H

