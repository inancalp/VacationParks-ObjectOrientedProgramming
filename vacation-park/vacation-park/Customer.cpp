#include "Customer.h"

Customer::Customer
(
	const string& name,
	const string& address,
	const string& email
)
	: Name(name), Address(address), Email(email)
{
	cout << "Customer::Constructor ->> " << this->getName() << " created." << endl;
}


Customer::~Customer()
{
	cout << "Customer::Destructor ->> " << this->getName() << " deleted." << endl;
}



void Customer::setName(const string& name)
{
	this->Name = name;
}

void Customer::setAddress(const string& address)
{
	this->Address = address;
}


void Customer::setEmail(const string& email)
{
	this->Email = email;
}



const string& Customer::getName() const
{
	return this->Name;
}

const string& Customer::getAddress() const
{
	return this->Address;
}

const string& Customer::getEmail() const
{
	return this->Email;
}





const string& Customer::customerToString() const
{
	ostringstream output;
	output << "(!) Customer::customerToString() (!)" << endl;
	output << "Customer Name: " << this->getName() << endl;
	output << "Customer ID: " << this->getAddress() << endl;
	output << "Customer E-mail: " << this->getEmail() << endl;
	output << "(!) Customer::customerToString() (!)";
	return output.str();
}


