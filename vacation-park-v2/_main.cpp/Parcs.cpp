#include "Parcs.h"


Parcs::Parcs(string name, string address) : m_name(name), m_address(address) {
	cout << "Parcs::Constructor ->> " << this->getName() << " created." << endl;
}
Parcs::~Parcs() {
	for (size_t i{ 0 }; i < this->getAccomodations().size(); i++)
	{
		delete this->getAccomodations()[i];
	}
	cout << "Parcs::Destructor ->> " << this->getName() << " deleted." << endl;
}

const string& Parcs::getName() const 
{
	return this->m_name;
}
const string& Parcs::getAddress() const
{
	return this->m_address;
}
const vector<string>& Parcs::getParcServices() const
{
	return this->m_parcServices;
}
const vector<Accomodations*>& Parcs::getAccomodations() const
{
	return this->m_accomodations;
}

void Parcs::setName(const string& name)
{
	this->m_name = name;
}
void Parcs::setAddress(const string& address)
{
	this->m_address = address;
}
void Parcs::setParcServices(string parc_services)
{
	this->m_parcServices.push_back(parc_services);
}
void Parcs::setAccomodation(Accomodations* accomodation)
{
	this->m_accomodations.push_back(accomodation);
}

const string Parcs::toString() const
{
	stringstream output;
	output << "--------------" << endl;
	output << "Parcs::getName() ->> " << this->getName() << endl;
	output << "Parcs::getAddress() ->> " << this->getAddress() << endl;
	output << "\nParcs::getParcServices()" << endl;
	for (size_t i{ 0 }; i < this->getParcServices().size(); i++)
	{
		output << "\t" << this->getParcServices()[i] << endl; //change later
	}
	output << "\nParcs::getAccomodations()" << endl;
	for (size_t i{ 0 }; i < this->getAccomodations().size(); i++)
	{
		output << "-> Parcs::getCustomers()[" << i << "]" << endl;
		output << this->getAccomodations()[i]->toString() << endl;
	}
	output << "--------------";
	return output.str();
}