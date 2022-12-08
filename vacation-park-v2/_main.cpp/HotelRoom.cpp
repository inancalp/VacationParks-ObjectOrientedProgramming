#include "HotelRoom.h"

HotelRoom::HotelRoom(
    const int id,
    const int nbr_people,
    const int size,
    const bool bathroom_with_bath,
    const bool is_booked,
    LuxuryLevel* luxury_level, 
    const int floor,
    const string location,
    const int nbr_beds,
    const bool children_bed
) : Accomodations(id, nbr_people, size, bathroom_with_bath, is_booked, luxury_level), m_floor(floor), m_location(location), m_nbrBeds(nbr_beds), m_childrenBed(children_bed) {
    cout << "(!) HotelRoom::Constructor ->> " << this->getId() << " created." << endl;
}

HotelRoom::~HotelRoom() {
    cout << "(!) HotelRoom::Destructor ->> " << this->getId() << " deleted." << endl;
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
    output << "---------------" << endl;
    output << "HotelRoom::ID -> " << this->getId() << endl;
    output << "HotelRoom::NbrPeople -> " << this->getNbrPeople() << endl;
    output << "HotelRoom::Size -> " << this->getSize() << endl;
    output << "HotelRoom::BathroomWithBath -> " << this->getBathroomWithBath() << endl;

    output << "Accomodations::IsBooked -> " << ((this->getIsBooked() == true) ? "State: Booked" : "State: Available") << endl;
    output << "(!) Accomodations::LuxuryLevel -> " << endl << this->getLuxuryLevel()->toString() << endl;
    output << "HotelRoom::Floor -> " << this->getFloor() << endl;
    output << "HotelRoom::Location -> " << this->getLocation() << endl;
    output << "HotelRoom::NbrBeds -> " << this->getNbrBeds() << endl;
    output << "HotelRoom::ChildrenBed -> " << boolalpha << this->getChildrenBed() << endl;
    output << "---------------" << endl;

    return output.str();
}
