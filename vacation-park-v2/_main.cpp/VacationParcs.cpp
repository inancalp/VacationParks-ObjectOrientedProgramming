#include "VacationParcs.h"


VacationParcs::VacationParcs(string name, string address, string vat) : m_name(name), m_address(address), m_vat(vat)
{
	cout << "VacationParcs::Constructor ->> " << this->getName() << " created." << endl;
}
VacationParcs::~VacationParcs()
{
	for (size_t i{ 0 }; i < this->getParcs().size(); i++)
	{
		delete this->getParcs()[i];
	}
	for (size_t i{ 0 }; i < this->getCustomers().size(); i++)
	{
		delete this->getCustomers()[i];
	}
	cout << "VacationParcs::Destructor ->> " << this->getName() << " deleted." << endl;
}



const string& VacationParcs::getName() const
{
	return this->m_name;
}
const string& VacationParcs::getAddress() const
{
	return this->m_address;
}
const string& VacationParcs::getVat() const
{
	return this->m_vat;
}


vector<Parcs*>& VacationParcs::getParcs() //(?) deleted const's
{
	return this->m_parcs;
}
vector<Customer*>& VacationParcs::getCustomers() //same above
{
	return this->m_customers;
}


void VacationParcs::setName(const string& name)
{
	this->m_name = name;
}
void VacationParcs::setAddress(const string& address)
{
	this->m_address = address;
}
void VacationParcs::setVat(const string& vat)
{
	this->m_vat = vat;
}


void VacationParcs::setParc(Parcs* parc)
{
	this->m_parcs.push_back(parc);
}
void VacationParcs::setCustomer(Customer* customer)
{
	this->m_customers.push_back(customer);
}



string VacationParcs::toString() //deleted both consts, else this->getParcs problem (??)
{
	ostringstream output;
	output << "--------------" << endl;
	output << "VacationParcs::getName() ->> " << this->getName() << endl;
	output << "VacationParcs::getAddress() ->> " << this->getAddress() << endl;
	output << "VacationParcs::getVat() ->> " << this->getVat() << endl;
	output << "\nVacationParcs::getParcs()" << endl;
	for (size_t i{ 0 }; i < this->getParcs().size(); i++)
	{
		output << "\t" << this->getParcs()[i] << endl;
	}
	output << "\nVacationParcs::getCustomers()" << endl;
	for (size_t i{ 0 }; i < this->getCustomers().size(); i++)
	{
		output << "-> VacationParcs::getCustomers()[" << i << "]" << endl;
		output << this->getCustomers()[i]->toString() << endl;
	}
	output << "--------------";
	return output.str();
}


