#include "Accomodations.h"

// LUXURY_LEVEL (!) change to class later
Accomodations::Accomodations
(
	const int id,
	const int nbr_people,
	const int size,
	const bool bathroom_with_bath,
	const string luxury_level
)
	: m_id(id), m_nbrPeople(nbr_people), m_size(size), m_bathroomWithBath(bathroom_with_bath), m_luxuryLevel(luxury_level)
{
	cout << "(!) Accomodations::Constructor ->> Accomodation with id[" << this->getId() << "] created." << endl;
}

Accomodations::~Accomodations() {
	cout << "(!) Accomodations::Destructor ->> Accomodation with id[" << this->getId() << "] deleted." << endl;
};

const int& Accomodations::getId() const
{
	return this->m_id;
}


const int& Accomodations::getNbrPeople() const
{
	return this->m_nbrPeople;
}


const int& Accomodations::getSize() const
{
	return this->m_size;
}


const bool& Accomodations::getBathroomWithBath() const
{
	return this->m_bathroomWithBath;
}


const string& Accomodations::getLuxuryLevel() const
{
	return this->m_luxuryLevel;
}


void Accomodations::setId(const int& id)
{
	this->m_id = id;
}


void Accomodations::setNbrPeople(const int& nbr_people)
{
	this->m_nbrPeople = nbr_people;
}


void Accomodations::setSize(const int& size)
{
	this->m_size = size;
}


void Accomodations::setBathroomWithBath(const bool& bathroom_with_bath)
{
	this->m_bathroomWithBath = bathroom_with_bath;
}


void Accomodations::setLuxuryLevel(const string& luxury_level)
{
	this->m_luxuryLevel = luxury_level;
}

const string Accomodations::toString() const {
	ostringstream output;
	output << " Accomodations::ID -> " << this->getId() << endl;
	output << " Accomodations::NbrPeople -> " << this->getNbrPeople() << endl;
	output << " Accomodations::Size -> " << this->getSize() << endl;
	output << " Accomodations::BathroomWithBath -> " << boolalpha << this->getBathroomWithBath() << endl;
	output << " Accomodations::LuxuryLevel -> " << this->getLuxuryLevel();

	return output.str();
}