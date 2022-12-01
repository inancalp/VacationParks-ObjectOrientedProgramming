#ifndef ACCOMODATION_H
#define ACCOMODATION_H

using namespace std;
#include <iostream>
#include <string>
#include <sstream>

class Accomodations
{

private:
	int m_id;
	int m_nbrPeople;
	int m_size;
	bool m_bathroomWithBath;
	string m_luxuryLevel; // LuxuryLevel type will change later.

public:

	Accomodations
	(
		const int id,
		const int nbr_people,
		const int size,
		const bool bathroom_with_bath,
		const string luxury_level //change later
	);

	virtual ~Accomodations(); // virtual as desing convention: otherwise memory leak may happen.

	const int& getId() const;
	const int& getNbrPeople() const;
	const int& getSize() const;
	const bool& getBathroomWithBath() const;
	const string& getLuxuryLevel() const;

	void setId(const int& id);
	void setNbrPeople(const int& nbr_people);
	void setSize(const int& size);
	void setBathroomWithBath(const bool& bathroom_with_bath);
	void setLuxuryLevel(const string& luxury_level);

	virtual const string toString() const;
};



#endif //ACCOMODATION_H