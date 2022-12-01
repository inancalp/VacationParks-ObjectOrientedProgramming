#include <iostream>
#include <string>
#include <sstream>


using namespace std;

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

	Accomodation(const int id, const int nbr_people, const int size, const bool bathroom_with_bath, const string luxury_level)
		: Id(id), NbrPeople(nbr_people), Size(size), BathroomWithBath(bathroom_with_bath), LuxuryLevel(luxury_level)
	{
		cout << "(!) Accomodation::Constructor WITH Parameters" << endl;
	}
	Accomodation() {
		cout << "(!) Accomodation::Constructor WITHOUT Parameters" << endl;
	};
	virtual ~Accomodation() {
		cout << "(!) Accomodation::Destructor" << endl;
	};

	const int& getId() const {
		return this->Id;
	};
	const int& getNbrPeople() const {
		return this->NbrPeople;
	};
	const int& getSize() const {
		return this->Size;
	};
	const bool& getBathroomWithBath() const {
		return this->BathroomWithBath;
	};
	const string& getLuxuryLevel() const {
		return this->LuxuryLevel;
	};

	void setId(const int& id) {
		this->Id = id;
	};
	void setNbrPeople(const int& nbr_people) {
		this->NbrPeople = nbr_people;
	};
	void setSize(const int& size) {
		this->Size = size;
	};
	void setBathroomWithBath(const bool& bathroom_with_bath) {
		this->BathroomWithBath = bathroom_with_bath;
	};
	void setLuxuryLevel(const string& luxury_level) {
		this->LuxuryLevel = luxury_level;
	};

	virtual string toString() {
		ostringstream output;
		output << " Accomodation::ID -> " << this->getId() << endl;
		output << " Accomodation::NbrPeople -> " << this->getNbrPeople() << endl;
		output << " Accomodation::Size -> " << this->getSize() << endl;
		output << " Accomodation::BathroomWithBath -> " << this->getBathroomWithBath() << endl;
		output << " Accomodation::LuxuryLevel -> " << this->getLuxuryLevel() << endl;
		output << "--------------------------" << endl;

		return output.str();
	};
};

class HotelRoom :
	public Accomodation
{
private:
	int Floor = -1;
	string Location = "N/A";
	int NbrBeds = -1;
	bool ChildrenBed = false;

public:
	HotelRoom() : Accomodation() {
		cout << "(!) HotelRoom::Constructor, Accomodation inc." << endl;
	};
	~HotelRoom() {
		cout << "(!) HotelRoom::Destructor" << endl;
	};

	const int& getFloor() const {
		return this->Floor;
	}
	const string& getLocation() const {
		return this->Location;
	}
	const int& getNbrBeds() const {
		return this->NbrBeds;
	}
	const bool& getChildrenBed() const {
		return this->ChildrenBed;
	}

	void setFloor(const int floor) {
		this->Floor = floor;
	}
	void setLocation(const string location) {
		this->Location = location;
	}
	void setNbrBeds(const int nbr_beds) {
		this->NbrBeds = nbr_beds;
	}
	void setChildrenBed(const bool children_bed) {
		this->ChildrenBed = children_bed;
	}

	string toString() {

		ostringstream output;
		output << "HotelRoom::toStringMemberFunction" << endl;
		output << "\n--------------------------\n" << endl;
		output << " HotelRoom::ID -> " << this->getId() << endl;
		output << " HotelRoom::NbrPeople -> " << this->getNbrPeople() << endl;
		output << " HotelRoom::Size -> " << this->getSize() << endl;
		output << " HotelRoom::BathroomWithBath -> " << this->getBathroomWithBath() << endl;
		output << " HotelRoom::LuxuryLevel -> " << this->getLuxuryLevel() << endl;
		output << " HotelRoom::Floor -> " << this->getFloor() << endl;
		output << " HotelRoom::Location -> " << this->getLocation() << endl;
		output << " HotelRoom::NbrBeds -> " << this->getNbrBeds() << endl;
		output << " HotelRoom::ChildrenBed -> " << this->getChildrenBed() << endl;
		output << "--------------------------" << endl;

		return output.str();
	}
};


int main() {

	Accomodation* h = new HotelRoom;
	cout << h->toString() << endl;
	delete h;

	return 0;
}