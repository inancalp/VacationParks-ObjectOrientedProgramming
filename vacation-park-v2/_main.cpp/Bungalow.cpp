#include "Bungalow.h"


Bungalow::Bungalow(
    const int id,
    const int nbr_people,
    const int size,
    const bool bathroom_with_bath,
    const bool is_booked,
    LuxuryLevel* luxury_level,
    const int bedrooms
) : Accomodations(id, nbr_people, size, bathroom_with_bath, is_booked, luxury_level), m_bedrooms(bedrooms) {
	cout << "(!) Bungalow::Constructor ->> " << this->getId() << " created." << endl;
}
Bungalow::~Bungalow() {
	cout << "(!) Bungalow::Destructor ->> " << this->getId() << " deleted." << endl;
};

const int& Bungalow::getBedrooms() const {
    return this->m_bedrooms;
}
void Bungalow::setBedrooms(const int bedrooms) {
    this->m_bedrooms = bedrooms;
}


const string Bungalow::toString() const {
    ostringstream output;
    output << "---------------" << endl;
    output << "Bungalow::ID -> " << this->getId() << endl;
    output << "Bungalow::NbrPeople -> " << this->getNbrPeople() << endl;
    output << "Bungalow::Size -> " << this->getSize() << endl;
    output << "Bungalow::BathroomWithBath -> " << this->getBathroomWithBath() << endl;
    output << "Accomodations::IsBooked -> " << ((this->getIsBooked() == true) ? "State: Booked" : "State: Available") << endl;
    output << "(!) Accomodations::LuxuryLevel -> " << endl << this->getLuxuryLevel()->toString() << endl;
    output << "Bungalow::Bedrooms -> " << this->getBedrooms() << endl;
    output << "---------------" << endl;

    return output.str();
}