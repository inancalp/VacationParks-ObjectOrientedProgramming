#ifndef CUSTOMER_H
#define CUSTOMER_H

//#include "Booking.h"
using namespace std;
#include <iostream>
#include <string>
#include <sstream>

class Customer {
private:
	string m_name;
	string m_address;
	string m_email;
public:
	Customer(string name, string address, string email);
	~Customer();
	void setName(const string& name);
	void setAddress(const string& address);
	void setEmail(const string& email);
	const string& getName() const;
	const string& getAddress() const;
	const string& getEmail() const;
	const string toString() const;
};

#endif //CUSTOMER_H

