#ifndef ACCOMODATION_H
#define ACCOMODATION_H

#include "LuxuryLevel.h"

class Accomodations
{
private:
	int m_id;
	int m_nbrPeople;
	int m_size;
	bool m_bathroomWithBath;
	bool m_isBooked;
	LuxuryLevel* m_luxuryLevel; 

public:
	Accomodations
	(
		const int id,
		const int nbr_people,
		const int size,
		const bool bathroom_with_bath,
		const bool is_booked,
		LuxuryLevel* luxury_level 
	);

	virtual ~Accomodations(); // virtual

	const int& getId() const;
	const int& getNbrPeople() const;
	const int& getSize() const;
	const bool& getBathroomWithBath() const;
	const bool& getIsBooked() const;
	const LuxuryLevel* getLuxuryLevel() const;

	void setId(const int& id);
	void setNbrPeople(const int& nbr_people);
	void setSize(const int& size);
	void setBathroomWithBath(const bool& bathroom_with_bath);
	void setIsBooked(const bool& is_booked);
	void setLuxuryLevel(LuxuryLevel* luxury_level); // ??

	virtual const string toString() const = 0;
};



#endif //ACCOMODATION_H