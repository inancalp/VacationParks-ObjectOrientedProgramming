#include "Accomodations.h"

// LUXURY_LEVEL (!) change to class later
Accomodations::Accomodations
(const int id, const int nbr_people, const int size, const bool bathroom_with_bath, const string luxury_level)
	: Id(id), NbrPeople(nbr_people), Size(size), BathroomWithBath(bathroom_with_bath), LuxuryLevel(luxury_level)
{
	cout << "(!) Accomodations::Constructor WITH Parameters" << endl;
}

Accomodations::Accomodations() {
	cout << "(!) Accomodations::Constructor WITHOUT Parameters" << endl;
}

Accomodations::~Accomodations() {
	cout << "(!) Accomodations::Destructor" << endl;
};

const int& Accomodations::getId() const
{
	return this->Id;
}


const int& Accomodations::getNbrPeople() const
{
	return this->NbrPeople;
}


const int& Accomodations::getSize() const
{
	return this->Size;
}


const bool& Accomodations::getBathroomWithBath() const
{
	return this->BathroomWithBath;
}


const string& Accomodations::getLuxuryLevel() const
{
	return this->LuxuryLevel;
}


void Accomodations::setId(const int& id)
{
	this->Id = id;
}


void Accomodations::setNbrPeople(const int& nbr_people)
{
	this->NbrPeople = nbr_people;
}


void Accomodations::setSize(const int& size)
{
	this->Size = size;
}


void Accomodations::setBathroomWithBath(const bool& bathroom_with_bath)
{
	this->BathroomWithBath = bathroom_with_bath;
}


void Accomodations::setLuxuryLevel(const string& luxury_level)
{
	this->LuxuryLevel = luxury_level;
}

const string Accomodations::toString() const {
	ostringstream output;
	output << " Accomodations::ID -> " << this->getId() << endl;
	output << " Accomodations::NbrPeople -> " << this->getNbrPeople() << endl;
	output << " Accomodations::Size -> " << this->getSize() << endl;
	output << " Accomodations::BathroomWithBath -> " << this->getBathroomWithBath() << endl;
	output << " Accomodations::LuxuryLevel -> " << this->getLuxuryLevel();

	return output.str();
}