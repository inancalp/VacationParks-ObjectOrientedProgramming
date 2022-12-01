#ifndef HOTELROOM_H
#define HOTELROOM_H

#include "Accomodation.h"

class HotelRoom :
    public Accomodation
{
private:
    int Floor = -1;
    string Location = "N/A";
    int NbrBeds = -1;
    bool ChildrenBed = false;

public:
    HotelRoom(const int id, const int nbr_people, const int size, const bool bathroom_with_bath, const string luxury_level, const int floor, const string location, const int nbr_beds, const bool child_bed);
    ~HotelRoom();

    const int& getFloor() const;
    const string& getLocation() const;
    const int& getNbrBeds() const;
    const bool& getChildrenBed() const;

    void setFloor(const int floor);
    void setLocation(const string location);
    void setNbrBeds(const int nbr_beds);
    void setChildrenBed(const bool children_bed);

    const string toString() const override;
};

#endif // HOTELROOM_H
