#ifndef ACCOMODATION_H
#define ACCOMODATION_H

using namespace std;
#include <iostream>
#include <string>
#include <sstream>

class Accomodation
{

private:
	int Id = -1;
	int NbrPeople = -1;
	int Size = -1;
	bool BathroomWithBath = false;
	// LuxuryLevel type will change later.
	string LuxuryLevel = "N/A";

public:

	Accomodation(const int id, const int nbr_people, const int size, const bool bathroom_with_bath, const string luxury_level);
	Accomodation();
	virtual ~Accomodation();

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