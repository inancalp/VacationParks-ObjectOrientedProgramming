#include "Booking.h"
Booking::Booking
(
	const int& id,
	Customer* customer,
	vector<Accomodations*> accomodations,
	const bool& activity_pass,
	const bool& sports_pass,
	const bool& bicycle_rent,
	const bool& swimming_pass
) : 
	m_id(id),
	m_customer(customer),
	m_accomodations(accomodations),
	m_activityPass(activity_pass),
	m_sportsPass(sports_pass),
	m_bicycleRent(bicycle_rent),
	m_swimmingPass(swimming_pass)
{
	cout << "(?) Booking::Constructor ->> " << "Booking with id[" << this->getId() << "] created." << endl;
}

Booking::~Booking()
{
	cout << "(!) Booking::Destructor ->> Booking with id[" << this->getId() << "] deleted." << endl;
}

void Booking::setId(const int& id)
{
	this->m_id = id;
}


void Booking::setCustomer(Customer* customer) 
{
	this->m_customer = customer;
}

void Booking::setAccomodations(vector<Accomodations*>& accomodations)
{
	this->m_accomodations = accomodations;
}
void Booking::setActivityPass(const bool& activity_pass)
{
	this->m_activityPass = activity_pass;
}
void Booking::setSportPass(const bool& sport_pass)
{
	this->m_sportsPass = sport_pass;
}
void Booking::setBicycleRent(const bool& bicycle_rent)
{
	this->m_bicycleRent = bicycle_rent;
}
void Booking::setSwimmingPass(const bool& swimming_pass)
{
	this->m_swimmingPass = swimming_pass;
}




const int& Booking::getId() const
{
	return this->m_id;
}

Customer* Booking::getCustomer() const
{
	return this->m_customer;
}

vector<Accomodations*>& Booking::getAccomodations()
{
	return this->m_accomodations;
}

const bool& Booking::getActivityPass() const
{
	return this->m_activityPass;
}
const bool& Booking::getSportPass() const
{
	return this->m_sportsPass;
}
const bool& Booking::getBicycleRent() const
{
	return this->m_bicycleRent;
}
const bool& Booking::getSwimmingPass() const
{
	return this->m_swimmingPass;
}

string Booking::toString()
{
	ostringstream output;
	output << "\t Booking::getId() ->> " << this->getId() << endl;
	output << "\t Booking::CustomerInfo ->> " << endl <<
		this->getCustomer()->toString() << endl;
	output << "\t Booking::getActivityPass() ->> " << boolalpha << this->getActivityPass() << endl;
	output << "\t Booking::getSportPass() ->> " << boolalpha << this->getSportPass() << endl;
	output << "\t Booking::getBicycleRent() ->> " << boolalpha << this->getBicycleRent() << endl;
	output << "\t Booking::getSwimmingPass() ->> " << boolalpha << this->getSwimmingPass() << endl;
	output << "\t Booking::getAccomodations() ->> " << endl << endl;
	for (size_t i{ 0 }; i < this->getAccomodations().size(); i++)
	{	
		output << "\t ->>";
		output << this->getAccomodations()[i]->toString();
	}
	return output.str();
}