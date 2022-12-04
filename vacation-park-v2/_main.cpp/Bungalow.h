
#ifndef BUNGALOW_H
#define BUNGALOW_H

#include "Accomodations.h"

class Bungalow :
    public Accomodations
{
private:
    int m_bedrooms;
public:
    Bungalow
    (
        const int id,
        const int nbr_people,
        const int size,
        const bool bathroom_with_bath,
        const bool is_booked,
        LuxuryLevel* luxury_level,
        const int bedrooms
    );

    ~Bungalow();

    const int& getBedrooms() const;
    void setBedrooms(const int bedrooms);

    const string toString() const override;
};

#endif // BUNGALOW_H