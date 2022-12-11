#include "_AccomodationController.h"
#include "_ParcController.h"


//do mind that, luxury_level for the objects are not saved as in order.
//when retrieving the date for luxury_level, another function should be called after "is_booked" to construct the object without any error.
void saveAccomodationFile(Accomodations* accom)
{
	ofstream accomsFile(ACCOMSFILE, ios::out | ios::app);
	if (!accomsFile)
	{
		cout << "Error occured while opening accommodations.txt file" << endl;
		return;
	}
	if (typeid(*accom) == typeid(HotelRoom))
	{
		cout << "saveAccomodationFile() ->> HotelRoom::getId() ->> " << accom->getId() << " being saved." << endl;
		HotelRoom* hotel_room = static_cast<HotelRoom*>(accom);
		accomsFile
			<< "hotel_room" << " "//to be able to see type.(could be changed to member variable?)
			<< hotel_room->getParcName() << " "
			<< hotel_room->getId() << " "
			<< hotel_room->getNbrPeople() << " "
			<< hotel_room->getSize() << " "
			<< hotel_room->getBathroomWithBath() << " "
			<< hotel_room->getIsBooked() << " "
			<< hotel_room->getLuxuryLevel()->getAccomodationKind() << " "
			<< hotel_room->getFloor() << " "
			<< hotel_room->getLocation() << " "
			<< hotel_room->getNbrBeds() << " "
			<< hotel_room->getChildrenBed() 
			<< endl;
		accomsFile.close();
	}

	if (typeid(*accom) == typeid(Bungalow))
	{
		cout << "saveAccomodationFile() ->> Bungalow::getId() ->> " << accom->getId() << " being saved." << endl;
		Bungalow* bungalow = static_cast<Bungalow*>(accom);
		accomsFile
			<< "bungalow" << " " //to be able to see type.(could be changed to member variable?)
			<< bungalow->getParcName() << " "
			<< bungalow->getId() << " "
			<< bungalow->getNbrPeople() << " "
			<< bungalow->getSize() << " "
			<< bungalow->getBathroomWithBath() << " "
			<< bungalow->getIsBooked() << " "
			<< bungalow->getLuxuryLevel()->getAccomodationKind() << " "
			<< bungalow->getBedrooms() 
			<< endl;
		accomsFile.close();
	}
}

void retrieveAccomodationsFile(VacationParcs* vp)
{
	string type;
	int ll_index;
	string parc_name;
	string luxuryLevel;

	int accom_id;
	int accom_nbrPeople;
	int accom_size;
	bool accom_bathroomWithBath;
	bool accom_isBooked;
	int accom_floor;
	string accom_location;
	int accom_nbrBeds;
	bool accom_childrenBed;
	int accom_bedrooms;

	ifstream accomodationsFile(ACCOMSFILE, ios::in);
	if (!accomodationsFile)
	{
		cout << "Error opening the file \"accommodations.txt\"." << endl;
	}

	while (accomodationsFile >> type)
	{
		if (type == "hotel_room")
		{
			accomodationsFile
				>> parc_name
				>> accom_id
				>> accom_nbrPeople
				>> accom_size
				>> accom_bathroomWithBath
				>> accom_isBooked
				>> luxuryLevel //string to find the original object.
				>> accom_floor
				>> accom_location
				>> accom_nbrBeds
				>> accom_childrenBed;

			for (size_t i{ 0 }; i < vp->getLuxuryLevels().size(); i++)
			{
				if (vp->getLuxuryLevels()[i]->getAccomodationKind() == luxuryLevel)
				{
					ll_index = static_cast<int>(i);
					break;
				}
			}

			for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
			{
				if (vp->getParcs()[i]->getName() == parc_name)
				{
					vp->getParcs()[i]->setAccomodation(
						new HotelRoom(
							parc_name,
							accom_id,
							accom_nbrPeople,
							accom_size,
							accom_bathroomWithBath,
							accom_isBooked,
							vp->getLuxuryLevels()[ll_index],
							accom_floor,
							accom_location,
							accom_nbrBeds,
							accom_childrenBed
						)
					);
				}
			}
		}
		if (type == "bungalow")
		{
			accomodationsFile
				>> parc_name
				>> accom_id
				>> accom_nbrPeople
				>> accom_size
				>> accom_bathroomWithBath
				>> accom_isBooked
				>> luxuryLevel //string to find the original object.
				>> accom_bedrooms;

			for (size_t i{ 0 }; i < vp->getLuxuryLevels().size(); i++)
			{
				if (vp->getLuxuryLevels()[i]->getAccomodationKind() == luxuryLevel)
				{
					ll_index = static_cast<int>(i);
					break;
				}
			}

			for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
			{
				if (vp->getParcs()[i]->getName() == parc_name)
				{
					vp->getParcs()[i]->setAccomodation(
						new Bungalow(
							parc_name,
							accom_id,
							accom_nbrPeople,
							accom_size,
							accom_bathroomWithBath,
							accom_isBooked,
							vp->getLuxuryLevels()[ll_index],
							accom_bedrooms
						)
					);
				}
			}
		}
	}

	accomodationsFile.close();
}

void reWriteAccomodationsFile(VacationParcs* vp)
{
	ofstream accomsFile(ACCOMSFILE, ios::out);

	if (!accomsFile)
	{
		cout << "reWriteAccomodationsFile() ->> Error occured while opening accommodations.txt file.";
		return;
	}

	for (Parcs* parc : vp->getParcs())
	{
		for (Accomodations* accom : parc->getAccomodations())
		{
			if (typeid(*accom) == typeid(HotelRoom))
			{
				cout << "reWriteAccomodations() ->> HotelRoom::getId() ->> " << accom->getId() << " being manipulated." << endl;
				HotelRoom* hotel_room = static_cast<HotelRoom*>(accom);
				accomsFile
					<< "hotel_room" << " "//to be able to see type.(could be changed to member variable?)
					<< hotel_room->getParcName() << " "
					<< hotel_room->getId() << " "
					<< hotel_room->getNbrPeople() << " "
					<< hotel_room->getSize() << " "
					<< hotel_room->getBathroomWithBath() << " "
					<< hotel_room->getIsBooked() << " "
					<< hotel_room->getLuxuryLevel()->getAccomodationKind() << " "
					<< hotel_room->getFloor() << " "
					<< hotel_room->getLocation() << " "
					<< hotel_room->getNbrBeds() << " "
					<< hotel_room->getChildrenBed()
					<< endl;
			}

			if (typeid(*accom) == typeid(Bungalow))
			{
				cout << "reWriteAccomodations() ->> Bungalow::getId() ->> " << accom->getId() << " being manipulated." << endl;
				Bungalow* bungalow = static_cast<Bungalow*>(accom);
				accomsFile
					<< "bungalow" << " " //to be able to see type.(could be changed to member variable?)
					<< bungalow->getParcName() << " "
					<< bungalow->getId() << " "
					<< bungalow->getNbrPeople() << " "
					<< bungalow->getSize() << " "
					<< bungalow->getBathroomWithBath() << " "
					<< bungalow->getIsBooked() << " "
					<< bungalow->getLuxuryLevel()->getAccomodationKind() << " "
					<< bungalow->getBedrooms()
					<< endl;
			}
		}
	}

	accomsFile.close();
}


//not_in_use (refer: selectLuxuryLevel())
void saveLuxuryLevelsFile(const int& accom_id, LuxuryLevel* ll)
{
	//ofstream luxuryLevelsFile(LUXURYLEVELSFILE, ios::out | ios::app);
	//if (!luxuryLevelsFile)
	//{
	//	cout << "Error occured while opening luxurylevels.txt file" << endl;
	//	return;
	//}
	//luxuryLevelsFile
	//	<< accom_id << " "
	//	<< ll->getBbq() << " "
	//	<< ll->getSurroundSystem() << " "
	//	<< ll->getBreakfastService() << " "
	//	<< ll->getCleaningService() << " "
	//	<< ll->getAccomodationKind() << endl;
	//luxuryLevelsFile.close();
}

void createAccomodation(VacationParcs* vp)
{
	int accom_id = -1;
	bool accom_not_found{ true };
	char accom_type;
	Parcs* p = selectParc(vp);

	if (p == NULL)
	{
		return; //exit
	}

	//unique accomodation_id implementation.
	for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
	{
		for (size_t j{ 0 }; j < vp->getParcs()[i]->getAccomodations().size(); j++)
		{
			//checks the largest id, increment it by 1.
			if (accom_id <= vp->getParcs()[i]->getAccomodations()[j]->getId())
			{
				accom_id = vp->getParcs()[i]->getAccomodations()[j]->getId() + 1;
			}
			accom_not_found = false;
		}
	}

	if (accom_not_found)
	{
		accom_id = 1000;
	}

	

	string parc_name = p->getName();

	do
	{
		cout << "Do mind that, exit is not possible after the input below." << endl;
		cout << "Type of accomodation('h' for hotel, 'b' for bungalow, 'e' for exit): ";
		cin >> accom_type;

		if (accom_type == 'e')
		{
			return; //exit
		}

		if (!(accom_type == 'h' || accom_type == 'b'))
		{
			cout << "Invalid input, please try again." << endl;
		}
	} while (!(accom_type == 'h' || accom_type == 'b'));


	switch (accom_type)
	{
	case 'h':
		createHotelRoom(vp, p, accom_id);
		break;

	case 'b':
		createBungalow(vp, p, accom_id);
		break;
	}
}

void createHotelRoom(VacationParcs* vp, Parcs* p, int accom_id)
{
	int accom_nbrPeople;
	int accom_size;
	bool accom_withBath;
	bool accom_isBooked{ false };
	int accom_floor;
	string accom_location;
	int accom_nbrBeds;
	bool accom_childBed;
	char accom_type;

	LuxuryLevel* accom_luxuryLevel;
	HotelRoom* hotel_room;

	cout << "? NbrPeople(integer): ";
	cin >> accom_nbrPeople;
	cout << "? Size(integer): ";
	cin >> accom_size;
	cout << "? BathroomWithBath(bool->(1/0)): ";
	cin >> accom_withBath;
	cout << "--------------------" << endl;
	cout << "? Setup LuxuryLevel: " << endl;
	accom_luxuryLevel = selectLuxuryLevel(vp);
	cout << "---------------------" << endl;
	cout << "? Floor(integer): ";
	cin >> accom_floor;
	cout << "? Location(string): ";
	cin >> accom_location;
	cout << "? NbrBeds(integer): ";
	cin >> accom_nbrBeds;
	cout << "? ChildrenBed(bool->(1/0)): ";
	cin >> accom_childBed;

	hotel_room =
		new HotelRoom(
			p->getName(),
			accom_id,
			accom_nbrPeople,
			accom_size,
			accom_withBath,
			accom_isBooked,
			accom_luxuryLevel, //obj
			accom_floor,
			accom_location,
			accom_nbrBeds,
			accom_childBed
		);

	saveAccomodationFile(hotel_room);
	p->setAccomodation(hotel_room);
	cout << hotel_room->toString() << endl;

	cout << "--------------------------------------" << endl;
	cout << "End of createAccomodation()->HotelRoom" << endl;
	cout << "--------------------------------------" << endl;

}

void createBungalow(VacationParcs* vp, Parcs* p, int accom_id)
{
	int accom_nbrPeople;
	int accom_size;
	bool accom_withBath;
	bool accom_isBooked{ false };
	int accom_bedrooms;

	LuxuryLevel* accom_luxuryLevel;
	Bungalow* bungalow;

	cout << "? NbrPeople(integer): ";
	cin >> accom_nbrPeople;
	cout << "? Size(integer): ";
	cin >> accom_size;
	cout << "? BathroomWithBath(bool->(1/0)): ";
	cin >> accom_withBath;
	cout << "--------------------" << endl;
	cout << "? Setup LuxuryLevel: " << endl;
	accom_luxuryLevel = selectLuxuryLevel(vp);
	cout << "---------------------" << endl;
	cout << "Bedrooms(integer): ";
	cin >> accom_bedrooms;

	bungalow = 
		new Bungalow(
			p->getName(),
			accom_id,
			accom_nbrPeople,
			accom_size,
			accom_withBath,
			accom_isBooked,
			accom_luxuryLevel,
			accom_bedrooms
		);

	saveAccomodationFile(bungalow);
	p->setAccomodation(bungalow);
	cout << bungalow->toString() << endl;

	cout << "--------------------------------------" << endl;
	cout << "End of createAccomodation()->Bungalow" << endl;
	cout << "--------------------------------------" << endl;
}


//selectLuxuryLevel() instead of createLuxuryLevel()
//decision on having stable LuxuryLevel objects that can be used for any accomodation
//current objects -> vip, premium, comfort LuxuryLevels
LuxuryLevel* selectLuxuryLevel(VacationParcs* vp)
{
	char selected_ll;
	string accom_kind;

	do
	{
		cout << "Enter (v)ip/(p)remium/(c)omfort: ";
		cin >> selected_ll;
		if (!(selected_ll == 'v' || selected_ll == 'p' || selected_ll == 'c'))
		{
			cout << "Invalid input, please try again." << endl;
		}
	} while (!(selected_ll == 'v' || selected_ll == 'p' || selected_ll == 'c'));

	switch (selected_ll)
	{
	case 'v':
		accom_kind = "vip";
		break;
	case 'p':
		accom_kind = "premium";
		break;
	case 'c':
		accom_kind = "comfort";
		break;
	default:
		cout << "selectLuxuryLevel() -> something went wrong!" << endl;
		break;
	}

	cout << "vp->getLuxuryLevels().size() ->> " << vp->getLuxuryLevels().size() << endl;
	for (size_t i{ 0 }; i < vp->getLuxuryLevels().size(); i++)
	{
		if (vp->getLuxuryLevels()[i]->getAccomodationKind() == accom_kind)
		{
			cout << "Selected LuxuryLevel ->> " << endl << vp->getLuxuryLevels()[i]->toString() << endl;
			return vp->getLuxuryLevels()[i];
		}
	}

	cout << "Something went wrong! Please check LuxuryLevel->AccomodationKind data placed regardings to selectLuxuryLevel funtion." << endl;
}

//not_in_use
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

//not_in_use
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

void showAccomodations(VacationParcs* vp)
{
	for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
	{
		if (vp->getParcs().size() == 0)
		{
			cout << "There are no Parcs to show, thus no Accomodations to show either!" << endl;
			return;
		}
		cout << "Accomodations included in the system of Parcs::getName() ->> " << vp->getParcs()[i]->getName() << endl << endl;

		if (vp->getParcs()[i]->getAccomodations().size() == 0)
		{
			cout << "\t (!) There are no Accommodations to show." << endl << endl;
			continue;
		}

		for (size_t j{ 0 }; j < vp->getParcs()[i]->getAccomodations().size(); j++)
		{
			cout << " ->>";
			cout << vp->getParcs()[i]->getAccomodations()[j]->toString() << endl;
		}
	}
}

void modifyAccomodation(VacationParcs* vp)
{
	Accomodations* accom;
	accom = selectAccomodation(vp);

	if (accom == NULL)
	{
		return;
	}

	if (accom->getIsBooked() == true)
	{
		cout << "Accomodation is booked. Try again later." << endl;
		return;
	}

	cout << accom->toString() << endl;

	if (typeid(*accom) == typeid(HotelRoom))
	{
		modifyHotelRoom(vp, accom);
	}
	if (typeid(*accom) == typeid(Bungalow))
	{
		modifyBungalow(vp, accom);
	}

	reWriteAccomodationsFile(vp); //(?)
}

Accomodations* selectAccomodation(VacationParcs* vp)
{
	string accom_id_string;
	int accom_id;
	bool accom_not_found{ true };

	do
	{
		cout << "Enter Accommodation ID: ";
		cin >> accom_id_string;

		//exit
		if (accom_id_string == "exit")
		{
			return NULL;//
		}

		accom_id = stoi(accom_id_string); //stringToInt

		for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
		{
			for (size_t j{ 0 }; j < vp->getParcs()[i]->getAccomodations().size(); j++)
			{
				if (accom_id == vp->getParcs()[i]->getAccomodations()[j]->getId())
				{
					cout << "Accomodation found!" << endl;
					return vp->getParcs()[i]->getAccomodations()[j];//
				}
			}
		}

		cout << "Accomodation with ID[" << accom_id << "] could not found." << endl;
	} while (accom_not_found);


}

void modifyHotelRoom(VacationParcs* vp, Accomodations* accom)
{
	char selected_option_char;
	int selected_option;
	int accom_nbrPeople;
	int accom_size;
	bool accom_withBath;
	int accom_floor;
	string accom_location;
	int accom_nbrBeds;
	bool accom_childBed;
	HotelRoom* hotel_room = static_cast<HotelRoom*>(accom);

	cout << "HotelRoom selected to modify." << endl;
	cout << "(!) Please do mind that, \"exit\" is not possible when an option is selected." << endl;
	cout << "\t (1) NbrPeople" << endl;
	cout << "\t (2) Size" << endl;
	cout << "\t (3) BathRoomWithBath" << endl;
	cout << "\t (4) LuxuryLevel" << endl;
	cout << "\t (5) Floor" << endl;
	cout << "\t (6) Location" << endl;
	cout << "\t (7) NbrBeds" << endl;
	cout << "\t (8) ChildrenBed" << endl;
	cout << "\t (e) Exit the Function" << endl;

	do
	{
		cout << "Enter the value for the attribute to be changed: ";
		cin >> selected_option_char;
		if (selected_option_char == 'e')
		{
			return;
		}
		selected_option = selected_option_char - '0';

		switch (selected_option)
		{
		case 1:
			cout << "Enter new NbrPeople(integer): ";
			cin >> accom_nbrPeople;
			hotel_room->setNbrPeople(accom_nbrPeople);
			break;
		case 2:
			cout << "Enter new Size(integer): ";
			cin >> accom_size;
			hotel_room->setSize(accom_size);
			break;
		case 3:
			cout << "Enter new BathRoomWithBath(bool(1/0)): ";
			cin >> accom_withBath;
			hotel_room->setBathroomWithBath(accom_withBath);
			break;
		case 4:
			hotel_room->setLuxuryLevel(selectLuxuryLevel(vp));
			break;
		case 5:
			cout << "Enter new Floor(integer): ";
			cin >> accom_floor;
			hotel_room->setFloor(accom_floor);
			break;
		case 6:
			cout << "Enter new Location(string): ";
			cin >> accom_location;
			hotel_room->setLocation(accom_location);
			break;
		case 7:
			cout << "Enter new NbrBeds(integer): ";
			cin >> accom_nbrBeds;
			hotel_room->setNbrBeds(accom_nbrBeds);
			break;
		case 8:
			cout << "Enter new ChildrenBed(bool(1/0)): ";
			cin >> accom_childBed;
			hotel_room->setChildrenBed(accom_childBed);
			break;
		}
	} while (true);
}

void modifyBungalow(VacationParcs* vp, Accomodations* accom)
{
	char selected_option_char;
	int selected_option;
	int accom_nbrPeople;
	int accom_size;
	bool accom_withBath;
	int accom_bedrooms;
	Bungalow* bungalow = static_cast<Bungalow*>(accom);

	cout << "Bungalow selected to modify." << endl;
	cout << "(!) Please do mind that, \"exit\" is not possible when an option is selected." << endl;
	cout << "\t (1) NbrPeople" << endl;
	cout << "\t (2) Size" << endl;
	cout << "\t (3) BathRoomWithBath" << endl;
	cout << "\t (4) LuxuryLevel" << endl;
	cout << "\t (5) NbrBedrooms" << endl;
	cout << "\t (e) Exit the Function" << endl;

	do
	{
		cout << "Enter the value for the attribute to be changed: ";
		cin >> selected_option_char;
		if (selected_option_char == 'e')
		{
			return;
		}
		selected_option = selected_option_char - '0';

		switch (selected_option)
		{
		case 1:
			cout << "Enter new NbrPeople(integer): ";
			cin >> accom_nbrPeople;
			bungalow->setNbrPeople(accom_nbrPeople);
			break;
		case 2:
			cout << "Enter new Size(integer): ";
			cin >> accom_size;
			bungalow->setSize(accom_size);
			break;
		case 3:
			cout << "Enter new BathRoomWithBath(bool(1/0)): ";
			cin >> accom_withBath;
			bungalow->setBathroomWithBath(accom_withBath);
			break;
		case 4:
			bungalow->setLuxuryLevel(selectLuxuryLevel(vp));
			break;
		case 5:
			cout << "Enter new Floor(integer): ";
			cin >> accom_bedrooms;
			bungalow->setBedrooms(accom_bedrooms);
			break;
		}
	} while (true);
}

void deleteAccomodation(VacationParcs* vp)
{
	Accomodations* selected_accom;
	selected_accom = selectAccomodation(vp);
	int accom_index_i;
	int accom_index_j;

	if (selected_accom == NULL)
	{
		return;
	}

	if (selected_accom->getIsBooked() == true)
	{
		cout << "Accomodation is booked. Try again later." << endl;
		return;
	}

	for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
	{
		for (size_t j{ 0 }; j < vp->getParcs()[i]->getAccomodations().size(); j++)
		{
			if (selected_accom->getId() == vp->getParcs()[i]->getAccomodations()[j]->getId())
			{
				accom_index_i = i;
				accom_index_j = j;
				break;
			}
		}
	}

	cout << "Accomodation with id[" << selected_accom->getId() << "] is deleted." << endl;
	delete selected_accom;
	vp->getParcs()[accom_index_i]->getAccomodations().erase(vp->getParcs()[accom_index_i]->getAccomodations().begin() + accom_index_j);

	reWriteAccomodationsFile(vp);
}