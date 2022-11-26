
#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Customer {

private:
	int Id = -1;
	string Name = "N/A";
	string Email = "N/A";
	vector<int> Bookings{};

public:
	Customer(const int& id,
		const string& name,
		const string& email,
		const vector<int>& bookings
	);

	Customer();

	void setId(const int& id);

	void setName(const string& name);

	void setEmail(const string& email);

	void setBookings(const vector<int>& bookings);

	void addBooking(const int& booking);

	const int& getId() const;
	const string& getName() const;
	const string& getEmail() const;
	const vector<int>& getBookings() const;
	

	const string showBookings() const;
	const void showCustomerInfo() const;
};

#endif //CUSTOMER_H

