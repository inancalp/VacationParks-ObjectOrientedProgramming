#include "HotelRoom.h"

HotelRoom::HotelRoom(
    const int id,
    const int nbr_people,
    const int size,
    const bool bathroom_with_bath,
    const string luxury_level, 
    const int floor,
    const string location,
    const int nbr_beds,
    const bool children_bed
) : Accomodations(id, nbr_people, size, bathroom_with_bath, luxury_level), m_floor(floor), m_location(location), m_nbrBeds(nbr_beds), m_childrenBed(children_bed) {
    cout << "(!) HotelRoom::Constructor" << endl;
}

HotelRoom::~HotelRoom() {
    cout << "(!) HotelRoom::Destructor" << endl;
}

const int& HotelRoom::getFloor() const {
    return this->m_floor;
}
const string& HotelRoom::getLocation() const {
    return this->m_location;
}
const int& HotelRoom::getNbrBeds() const {
    return this->m_nbrBeds;
}
const bool& HotelRoom::getChildrenBed() const {
    return this->m_childrenBed;
}

void HotelRoom::setFloor(const int floor) {
    this->m_floor = floor;
}
void HotelRoom::setLocation(const string location) {
    this->m_location = location;
}
void HotelRoom::setNbrBeds(const int nbr_beds) {
    this->m_nbrBeds = nbr_beds;
}
void HotelRoom::setChildrenBed(const bool children_bed) {
    this->m_childrenBed = children_bed;
}

const string HotelRoom::toString() const {

    ostringstream output;
    output << " HotelRoom::ID -> " << this->getId() << endl;
    output << " HotelRoom::NbrPeople -> " << this->getNbrPeople() << endl;
    output << " HotelRoom::Size -> " << this->getSize() << endl;
    output << " HotelRoom::BathroomWithBath -> " << this->getBathroomWithBath() << endl;
    output << " HotelRoom::LuxuryLevel -> " << this->getLuxuryLevel() << endl;
    output << " HotelRoom::Floor -> " << this->getFloor() << endl;
    output << " HotelRoom::Location -> " << this->getLocation() << endl;
    output << " HotelRoom::NbrBeds -> " << this->getNbrBeds() << endl;
    output << " HotelRoom::ChildrenBed -> " << boolalpha << this->getChildrenBed();

    return output.str();
}
