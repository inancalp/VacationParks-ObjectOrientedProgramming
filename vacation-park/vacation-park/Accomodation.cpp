#include "Accomodation.h"

// LUXURY_LEVEL (!) change to class later
Accomodation::Accomodation
(const int id, const int nbr_people, const int size, const bool bathroom_with_bath, const string luxury_level)
	: Id(id), NbrPeople(nbr_people), Size(size), BathroomWithBath(bathroom_with_bath), LuxuryLevel(luxury_level)
{
	cout << "(!) Accomodation::Constructor WITH Parameters" << endl;
}

Accomodation::Accomodation() {
	cout << "(!) Accomodation::Constructor WITHOUT Parameters" << endl;
}

Accomodation::~Accomodation() {
	cout << "(!) Accomodation::Destructor" << endl;
};

const int& Accomodation::getId() const
{
	return this->Id;
}


const int& Accomodation::getNbrPeople() const
{
	return this->NbrPeople;
}


const int& Accomodation::getSize() const
{
	return this->Size;
}


const bool& Accomodation::getBathroomWithBath() const
{
	return this->BathroomWithBath;
}


const string& Accomodation::getLuxuryLevel() const
{
	return this->LuxuryLevel;
}


void Accomodation::setId(const int& id)
{
	this->Id = id;
}


void Accomodation::setNbrPeople(const int& nbr_people)
{
	this->NbrPeople = nbr_people;
}


void Accomodation::setSize(const int& size)
{
	this->Size = size;
}


void Accomodation::setBathroomWithBath(const bool& bathroom_with_bath)
{
	this->BathroomWithBath = bathroom_with_bath;
}


void Accomodation::setLuxuryLevel(const string& luxury_level)
{
	this->LuxuryLevel = luxury_level;
}

const string Accomodation::toString() const{
	ostringstream output;
	output << " Accomodation::ID -> " << this->getId() << endl;
	output << " Accomodation::NbrPeople -> " << this->getNbrPeople() << endl;
	output << " Accomodation::Size -> " << this->getSize() << endl;
	output << " Accomodation::BathroomWithBath -> " << this->getBathroomWithBath() << endl;
	output << " Accomodation::LuxuryLevel -> " << this->getLuxuryLevel();

	return output.str();
}