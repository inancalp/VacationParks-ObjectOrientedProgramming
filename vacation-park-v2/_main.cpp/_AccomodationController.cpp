#include "_AccomodationController.h"


void createAccomodation(Parcs* p)
{
	static int accom_id = 100;
	int accom_nbrPeople;
	int accom_size;
	bool accom_withBath;
	LuxuryLevel* accom_luxuryLevel;
	int accom_floor;
	string accom_location;
	int accom_nbrBeds;
	bool accom_childBed;
	int accom_bedrooms;
	char accom_type;

	do
	{
		cout << "Type of accomodation('h' for hotel, 'b' for bungalow): ";
		cin >> accom_type;

		if (!(accom_type == 'h' || accom_type == 'b'))
		{
			cout << "Invalid input, please try again." << endl;
		}
	} while (!(accom_type == 'h' || accom_type == 'b'));


	switch (accom_type)
	{
	case 'h':
		cout << "? NbrPeople: ";
		cin >> accom_nbrPeople;
		cout << "? Size: ";
		cin >> accom_size;
		cout << "? BathroomWithBath: ";
		cin >> accom_withBath;
		cout << "--------------------" << endl;
		cout << "? Setup LuxuryLevel: " << endl;
		accom_luxuryLevel = createLuxuryLevel("Hotel Room");
		cout << "---------------------" << endl;
		cout << "? Floor: ";
		cin >> accom_floor;
		cout << "? Location: ";
		cin >> accom_location;
		cout << "? NbrBeds: ";
		cin >> accom_nbrBeds;
		cout << "? ChildrenBed: ";
		cin >> accom_childBed;

		p->setAccomodation(
			new HotelRoom(
				accom_id++,
				accom_nbrPeople,
				accom_size,
				accom_withBath,
				accom_luxuryLevel,
				accom_floor,
				accom_location,
				accom_nbrBeds,
				accom_childBed
			)
		);
		cout << "--------------------------------------" << endl;
		cout << "End of createAccomodation()->HotelRoom" << endl;
		cout << "--------------------------------------" << endl;
		break;

	case 'b':
		cout << "? NbrPeople: ";
		cin >> accom_nbrPeople;
		cout << "? Size: ";
		cin >> accom_size;
		cout << "? BathroomWithBath: ";
		cin >> accom_withBath;
		cout << "--------------------" << endl;
		cout << "? Setup LuxuryLevel: " << endl;
		accom_luxuryLevel = createLuxuryLevel("Bungalow");
		cout << "---------------------" << endl;
		cout << "Bedrooms: ";
		cin >> accom_bedrooms;

		p->setAccomodation(
			new Bungalow(
				accom_id++,
				accom_nbrPeople,
				accom_size,
				accom_withBath,
				accom_luxuryLevel,
				accom_bedrooms
			)
		);
		cout << "--------------------------------------" << endl;
		cout << "End of createAccomodation()->Bungalow" << endl;
		cout << "--------------------------------------" << endl;
		break;
	}


}

LuxuryLevel* createLuxuryLevel(string accom_kind)
{
	int bbq;
	int surround_system;
	int breakfast_service;
	int cleaning_service;

	createLuxuryLevelMiddleWare(bbq, "BBQ");
	createLuxuryLevelMiddleWare(surround_system, "Surround System");
	createLuxuryLevelMiddleWare(breakfast_service, "Breakfast Service");
	createLuxuryLevelMiddleWare(cleaning_service, "Cleaning Service");

	return new LuxuryLevel
	(
		static_cast<bool>(bbq),
		static_cast<bool>(surround_system),
		static_cast<bool>(breakfast_service),
		static_cast<bool>(cleaning_service),
		accom_kind
	);

}

void createLuxuryLevelMiddleWare(int& data, string data_name)
{
	do
	{
		cout << "\t? " << data_name << ": ";
		cin >> data;
		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			data = -1; //invalid value to handle.
		}
		if (data < 0 || data > 1)
		{
			cout << "(!) Invalid input, try again." << endl;
		}
	} while (data < 0 || data > 1);
}

void showAccomodations(Parcs* p)
{
	cout << "-------------------------" << endl;
	cout << "Accomodations included in the system of Parcs::getName() ->> " << p->getName() << endl;
	for (size_t i{ 0 }; i < p->getAccomodations().size(); i++)
	{
		cout << p->getAccomodations()[i]->toString() << endl;
	}
	cout << "-------------------------" << endl;
}