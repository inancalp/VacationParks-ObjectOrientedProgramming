
#include "Customer.h"
Customer::Customer
(
	string& name,
	string& address,
	string& email
)
	: m_name(name), m_address(address), m_email(email)
{
	cout << "Customer::Constructor ->> " << this->getName() << " created." << endl;
}

Customer::~Customer()
{
	for (size_t i{ 0 }; i < this->getBookings().size(); i++)
	{
		delete this->getBookings()[i];
	}
	cout << "Customer::Destructor ->> " << this->getEmail() << " deleted." << endl;
}


void Customer::setName(const string& name)
{
	this->m_name = name;
}

void Customer::setAddress(const string& address)
{
	this->m_address = address;
}


void Customer::setEmail(const string& email)
{
	this->m_email = email;
}

void Customer::setBooking(Booking* booking)
{
	this->m_bookings.push_back(booking);
}


const string& Customer::getName() const
{
	return this->m_name;
}

const string& Customer::getAddress() const
{
	return this->m_address;
}

const string& Customer::getEmail() const
{
	return this->m_email;
}

const vector<Booking*>& Customer::getBookings() const
{
	return this->m_bookings;
}


const string Customer::toString() const
{
	ostringstream output;
	output << "\tCustomer Name: " << this->getName() << endl;
	output << "\tCustomer ID: " << this->getAddress() << endl;
	output << "\tCustomer E-mail: " << this->getEmail() << endl;
	output << "\tCustomer Bookings:" << endl;
	
	if (!this->getBookings().size())
	{
		output << "\t->> There are no bookings yet for " << this->getName() << "." << endl;
	}

	for (size_t i{ 0 }; i < this->getBookings().size(); i++)
	{
		output << "\t" << this->getBookings()[i]->getId() << endl;
	}
	return output.str();
}


