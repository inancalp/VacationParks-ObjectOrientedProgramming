#include "HotelRoom.h"

HotelRoom::HotelRoom() : Accomodation() {
    cout << "(!) HotelRoom::Constructor, Accomodation inc." << endl;
}
HotelRoom::~HotelRoom() {
    cout << "(!) HotelRoom::Destructor" << endl;
}

const int& HotelRoom::getFloor() const {
    return this->Floor;
}
const string& HotelRoom::getLocation() const {
    return this->Location;
}
const int& HotelRoom::getNbrBeds() const {
    return this->NbrBeds;
}
const bool& HotelRoom::getChildrenBed() const {
    return this->ChildrenBed;
}

void HotelRoom::setFloor(const int floor) {
    this->Floor = floor;
}
void HotelRoom::setLocation(const string location) {
    this->Location = location;
}
void HotelRoom::setNbrBeds(const int nbr_beds) {
    this->NbrBeds = nbr_beds;
}
void HotelRoom::setChildrenBed(const bool children_bed) {
    this->ChildrenBed = children_bed;
}

const string HotelRoom::toString() const{

    ostringstream output;
    output << " HotelRoom::ID -> " << this->getId() << endl;
    output << " HotelRoom::NbrPeople -> " << this->getNbrPeople() << endl;
    output << " HotelRoom::Size -> " << this->getSize() << endl;
    output << " HotelRoom::BathroomWithBath -> " << this->getBathroomWithBath() << endl;
    output << " HotelRoom::LuxuryLevel -> " << this->getLuxuryLevel() << endl;
    output << " HotelRoom::Floor -> " << this->getFloor() << endl;
    output << " HotelRoom::Location -> " << this->getLocation() << endl;
    output << " HotelRoom::NbrBeds -> " << this->getNbrBeds() << endl;
    output << " HotelRoom::ChildrenBed -> " << this->getChildrenBed();

    return output.str();
} 
