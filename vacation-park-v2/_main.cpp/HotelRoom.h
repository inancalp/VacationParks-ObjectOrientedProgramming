#ifndef HOTELROOM_H
#define HOTELROOM_H

#include "Accomodations.h"

class HotelRoom :
    public Accomodations
{
private:
    int Floor = -1;
    string Location = "N/A";
    int NbrBeds = -1;
    bool ChildrenBed = false;

public:
    HotelRoom();
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
