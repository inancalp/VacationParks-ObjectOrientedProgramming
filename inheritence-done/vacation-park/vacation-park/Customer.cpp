#include "Customer.h"


Customer::Customer
(
	const int& id,
	const string& name,
	const string& email,
	const vector<int>& bookings
):Id(id), Name(name), Email(email), Bookings(bookings) {}

Customer::Customer() {}

void Customer::setId(const int& id)
{
	this->Id = id;
}


void Customer::setName(const string& name)
{
	this->Name = name;
}

void Customer::setEmail(const string& email)
{
	this->Email = email;
}

void Customer::setBookings(const vector<int>& bookings)
{
	this->Bookings = bookings;
}

const int& Customer::getId() const
{
	return this->Id;
}

const string& Customer::getName() const
{
	return this->Name;
}

const string& Customer::getEmail() const
{
	return this->Email;
}

const vector<int>& Customer::getBookings() const
{
	return this->Bookings;
}

const string Customer::showBookings() const
{
	int i;
	ostringstream output;

	output << "[ ";
	for (i = 0; i < this->Bookings.size(); i++) 
	{
		output << this->Bookings[i];
		if (i != this->Bookings.size() - 1)
		{
			output << ", ";
		}
	}
	output << " ]";

	return output.str();
}

void Customer::addBooking(const int& booking)
{
	// addAccomodation functionality comes here, with a limit of 3. -> static variable ??
	cout << endl << "New booking has been made for Customer: " << this->getName() << endl << "-> Booking ID : " << booking << endl;
	this->Bookings.push_back(booking); // (?) this->getBookings().push_back(booking);
}


const void Customer::showCustomerInfo() const
{
	cout << "\t\t\t\t|--------------                   \n";
	cout << "\t\t\t\t|                                 \n";
	cout << "\t\t\t\t| Customer ID: " << this->getId() << endl;
	cout << "\t\t\t\t| Customer Name: " << this->getName() << endl;
	cout << "\t\t\t\t| Customer E-mail: " << this->getEmail() << endl;
	cout << "\t\t\t\t| Customer Bookings: " << this->showBookings() << endl;
	cout << "\t\t\t\t|                                 \n";
	cout << "\t\t\t\t|--------------                   \n";
}


