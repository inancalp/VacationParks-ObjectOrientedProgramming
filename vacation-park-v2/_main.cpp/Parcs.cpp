#include "Parcs.h"


Parcs::Parcs(string name, string address, ParcServices* parc_services) : m_name(name), m_address(address), m_parcServices(parc_services) {
	cout << "Parcs::Constructor ->> " << this->getName() << " created." << endl;
}
Parcs::~Parcs() {
	//delete accomodations
	for (size_t i{ 0 }; i < this->getAccomodations().size(); i++)
	{
		delete this->getAccomodations()[i];
	}

	//delete services object
	delete this->getParcServices();

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
ParcServices* Parcs::getParcServices() const
{
	return this->m_parcServices;
}
vector<Accomodations*>& Parcs::getAccomodations()
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
void Parcs::setParcServices(ParcServices* parc_services)
{
	this->m_parcServices = parc_services;
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
	output << "Parcs::getParcServices() -> " << endl << this->getParcServices()->toString() << endl;
	//output << "Parcs::getAccomodations()" << endl;
	//for (size_t i{ 0 }; i < this->getAccomodations().size(); i++)
	//{
	//	output << "-> Parcs::getCustomers()[" << i << "]" << endl;
	//	output << this->getAccomodations()[i]->toString() << endl;
	//}
	output << "--------------";
	return output.str();
}