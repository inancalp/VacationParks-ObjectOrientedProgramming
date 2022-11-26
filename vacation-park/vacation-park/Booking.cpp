#include "Booking.h"

Booking::Booking(
	const int& id,
	const Customer& customer,
	const vector<int>& accomodations, // change it to an Accomodation object ??
	const bool& activity_pass,
	const bool& sports_pass,
	const bool& bicycle_rent,
	const bool& swimming_pass
) : Id(id),
	_Customer(customer),
	Accomodations(accomodations),
	activityPass(activity_pass),
	sportsPass(sports_pass),
	bicycleRent(bicycle_rent),
	swimmingPass(swimming_pass) {}


void Booking::setId(const int& id)
{
	this->Id = id;
}
void Booking::setCustomer(const Customer& customer)
{
	this->_Customer = customer;
}
void Booking::setAccomodations(const vector<int>& accomodations)
{
	this->Accomodations = accomodations;
}
void Booking::setActivityPass(const bool& activity_pass)
{
	this->activityPass = activity_pass;
}
void Booking::setSportPass(const bool& sport_pass)
{
	this->sportsPass = sport_pass;
}
void Booking::setBicycleRent(const bool& bicycle_rent)
{
	this->bicycleRent = bicycle_rent;
}
void Booking::setSwimmingPass(const bool& swimming_pass)
{
	this->swimmingPass = swimming_pass;
}




const int& Booking::getId() const
{
	return this->Id;
}
const Customer& Booking::getCustomer() const
{
	return this->_Customer;
}
const vector<int>& Booking::getAccomodations() const
{
	return this->Accomodations;
}

const bool& Booking::getActivityPass() const
{
	return this->activityPass;
}
const bool& Booking::getSportPass() const
{
	return this->sportsPass;
}
const bool& Booking::getBicycleRent() const
{
	return this->bicycleRent;
}
const bool& Booking::getSwimmingPass() const
{
	return this->swimmingPass;
}