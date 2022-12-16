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
	int accom_id;
	bool accom_not_found;
	char accom_type;
	string parc_name;
	Parcs* p;

	do
	{
		p = selectParc(vp);
		if (cin.eof())
		{
			cin.clear();
			return;
		}
		parc_name = p->getName();

		//unique accomodation_id implementation.
		accom_not_found = true;
		accom_id = -1; //since it can't be negative.
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

		do
		{
			accom_type = '\0';
			do
			{
				cout << "Type of accomodation?" << endl;
				cout << "Enter \"h\" for HotelRoom, \"b\" for Bungalow: ";
				cin >> accom_type;
				if (cin.eof())
				{
					break; //exit
				}

				if (!(accom_type == 'h' || accom_type == 'b'))
				{
					cout << "Invalid input, please try again." << endl;
				}
			} while (!(accom_type == 'h' || accom_type == 'b'));

			//accom_type
			if (cin.eof())
			{
				cin.clear();
				break;
			}

			switch (accom_type)
			{
			case 'h':
				createHotelRoom(vp, p, accom_id);
				if (cin.eof())
				{
					cin.clear();
					break;
				}
				return;
			case 'b':
				createBungalow(vp, p, accom_id);
				if (cin.eof())
				{
					cin.clear();
					break;
				}
				return;
			default:
				cout << "Invalid action." << endl;
				break;
			}
		} while (true);

		

	} while (true);
}

void createHotelRoom(VacationParcs* vp, Parcs* p, int accom_id)
{
	int accom_nbrPeople = -1;
	int accom_size = -1;
	int accom_withBath = -1; //static_cast when construct obj
	bool accom_isBooked{ false };
	int accom_floor = -1;
	string accom_location = "\0";
	int accom_nbrBeds = -1;
	int accom_childBed = -1;
	LuxuryLevel* accom_luxuryLevel = NULL;
	HotelRoom* hotel_room = NULL;

	do
	{
		if (accom_nbrPeople == -1)
		{
			cin.clear();
			cout << "? (Integer) NbrPeople: ";
			cin >> accom_nbrPeople;
			if (cin.eof())
			{
				return;
			}
		}

		if (accom_size == -1)
		{
			cin.clear();
			cout << "? (Integer) Size: ";
			cin >> accom_size;
			if (cin.eof())
			{
				accom_nbrPeople = -1;
				continue;
			}
		}

		if (accom_withBath == -1)
		{
			cin.clear();
			cout << "? BathroomWithBath(bool->(1/0)): ";
			cin >> accom_withBath;
			if (cin.eof())
			{
				accom_size = -1;
				continue;
			}
		}

		if (accom_luxuryLevel == NULL)
		{
			cin.clear();
			cout << "? Setup LuxuryLevel: " << endl;
			accom_luxuryLevel = selectLuxuryLevel(vp);
			if (cin.eof())
			{
				accom_withBath = -1;
				continue;
			}
		}

		if (accom_floor == -1)
		{
			cin.clear();
			cout << "? Floor(integer): ";
			cin >> accom_floor;
			if (cin.eof())
			{
				accom_luxuryLevel = NULL;
				continue;
			}
		}

		if (accom_location.empty())
		{
			cin.clear();
			cout << "? Location(string): ";
			cin >> accom_location;
			if (cin.eof())
			{
				accom_floor = -1;
				continue;
			}
		}

		if (accom_nbrBeds == -1)
		{
			cin.clear();
			cout << "? NbrBeds(integer): ";
			cin >> accom_nbrBeds;
			if (cin.eof())
			{
				accom_location.clear();
				continue;
			}
		}

		if (accom_childBed == -1)
		{
			cin.clear();
			cout << "? ChildrenBed(bool->(1/0)): ";
			cin >> accom_childBed;
			if (cin.eof())
			{
				accom_nbrBeds = -1;
				continue;
			}
		}
		break;
	} while (true);
	

	hotel_room =
		new HotelRoom(
			p->getName(),
			accom_id,
			accom_nbrPeople,
			accom_size,
			static_cast<bool>(accom_withBath),
			accom_isBooked,
			accom_luxuryLevel, //obj
			accom_floor,
			accom_location,
			accom_nbrBeds,
			static_cast<bool>(accom_childBed)
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
	int accom_nbrPeople = -1;
	int accom_size = -1;
	int accom_withBath = -1; //static_cast when construct obj
	bool accom_isBooked{ false };
	int accom_bedrooms = -1;
	LuxuryLevel* accom_luxuryLevel = NULL;
	Bungalow* bungalow = NULL;

	
	do
	{
		if (accom_nbrPeople == -1)
		{
			cin.clear();
			cout << "? NbrPeople(integer): ";
			cin >> accom_nbrPeople;
			if (cin.eof())
			{
				return;
			}
		}
		if (accom_size == -1)
		{
			cin.clear();
			cout << "? Size(integer): ";
			cin >> accom_size;
			if (cin.eof())
			{
				accom_nbrPeople = -1;
				continue;
			}
		}
		if (accom_withBath == -1)
		{
			cin.clear();
			cout << "? BathroomWithBath(bool->(1/0)): ";
			cin >> accom_withBath;
			if (cin.eof())
			{
				accom_size = -1;
				continue;
			}
		}
		if (accom_luxuryLevel == NULL)
		{
			cin.clear();
			cout << "? Setup LuxuryLevel: " << endl;
			accom_luxuryLevel = selectLuxuryLevel(vp);
			if (cin.eof())
			{
				accom_withBath = -1;
				continue;
			}
		}
		if (accom_bedrooms == -1)
		{
			cin.clear();
			cout << "Bedrooms(integer): ";
			cin >> accom_bedrooms;
			if (cin.eof())
			{
				accom_luxuryLevel = NULL;
				continue;
			}
		}
		break;
	} while (true);


	bungalow = 
		new Bungalow(
			p->getName(),
			accom_id,
			accom_nbrPeople,
			accom_size,
			static_cast<bool>(accom_withBath),
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
		cout << "Enter, \"v\" for VIP, \"p\" for Premium, \"c\" for Comfort: ";
		cin >> selected_ll;
		if (cin.eof())
		{
			return NULL;
		}

		if (!(selected_ll == 'v' || selected_ll == 'p' || selected_ll == 'c'))
		{
			cout << "Invalid input, please try again." << endl;
			cin.clear();
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
		cout << "->> Accomodations included in the system of Parcs::getName() ->> " << vp->getParcs()[i]->getName() << endl << endl;

		if (vp->getParcs()[i]->getAccomodations().size() == 0)
		{
			cout << "\t (!) There are no Accommodations to show." << endl << endl;
			continue;
		}

		for (size_t j{ 0 }; j < vp->getParcs()[i]->getAccomodations().size(); j++)
		{
			cout << "\t->>";
			cout << vp->getParcs()[i]->getAccomodations()[j]->toString() << endl;
		}
	}
}

void modifyAccomodation(VacationParcs* vp)
{
	Accomodations* accom;
	accom = NULL;
	accom = selectAccomodation(vp);
	if (cin.eof())
	{
		cin.clear();
		return;
	}

	cout << accom->toString() << endl;
	if (accom->getIsBooked() == true)
	{
		cout << "(!) Accomodation is booked. Try again later." << endl;
		return;
	}

	if (typeid(*accom) == typeid(HotelRoom))
	{
		modifyHotelRoom(vp, accom);
		if (cin.eof())
		{
			cout << "(!) modifyHotelRoom() canceled." << endl;
			cin.clear();
			return;
		}
	}
	if (typeid(*accom) == typeid(Bungalow))
	{
		modifyBungalow(vp, accom);
		if (cin.eof())
		{
			cout << "(!) modifyBungalow() canceled." << endl;
			cin.clear();
			return;
		}
	}
	reWriteAccomodationsFile(vp); //(?)
}

Accomodations* selectAccomodation(VacationParcs* vp)
{
	int accom_id;
	do
	{
		cout << "Enter Accommodation ID: ";
		cin >> accom_id;
		if (cin.eof())
		{
			return NULL;
		}

		for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
		{
			for (size_t j{ 0 }; j < vp->getParcs()[i]->getAccomodations().size(); j++)
			{
				if (accom_id == vp->getParcs()[i]->getAccomodations()[j]->getId())
				{
					return vp->getParcs()[i]->getAccomodations()[j];//
				}
			}
		}
		cout << "Accomodation with ID[" << accom_id << "] could not found." << endl;
	} while (true);
}

void modifyHotelRoom(VacationParcs* vp, Accomodations* accom)
{
	int selected_option = -1;
	int accom_nbrPeople = -1;
	int accom_size = -1;
	int accom_withBath = -1; //static_cast<bool>
	int accom_floor = -1;
	string accom_location;
	int accom_nbrBeds = -1;
	int accom_childBed = -1; //static_cast<bool>
	LuxuryLevel* accom_luxuryLevel = NULL;
	HotelRoom* hotel_room = static_cast<HotelRoom*>(accom);

	cout << "HotelRoom selected to modify.(Don't forget to save changes!)" << endl;
	cout << "\t (1) NbrPeople" << endl;
	cout << "\t (2) Size" << endl;
	cout << "\t (3) BathRoomWithBath" << endl;
	cout << "\t (4) LuxuryLevel" << endl;
	cout << "\t (5) Floor" << endl;
	cout << "\t (6) Location" << endl;
	cout << "\t (7) NbrBeds" << endl;
	cout << "\t (8) ChildrenBed" << endl;
	cout << "\t (9) SAVE CHANGES and EXIT." << endl;

	do
	{
		cout << "Select option: ";
		cin >> selected_option;
		if (cin.eof())
		{
			return;
		}

		switch (selected_option)
		{
		case 1:
			cout << "Enter new NbrPeople(integer): ";
			cin >> accom_nbrPeople;
			if (cin.eof())
			{
				return;
			}
			break;
		case 2:
			cout << "Enter new Size(integer): ";
			cin >> accom_size;
			if (cin.eof())
			{
				return;
			}
			break;
		case 3:
			cout << "Enter new BathRoomWithBath(bool(1/0)): ";
			cin >> accom_withBath;
			if (cin.eof())
			{
				return;
			}
			break;
		case 4:
			accom_luxuryLevel = selectLuxuryLevel(vp);
			if (cin.eof())
			{
				return;
			}
			break;
		case 5:
			cout << "Enter new Floor(integer): ";
			cin >> accom_floor;
			if (cin.eof())
			{
				return;
			}
			break;
		case 6:
			cout << "Enter new Location(string): ";
			cin >> accom_location;
			if (cin.eof())
			{
				return;
			}
			break;
		case 7:
			cout << "Enter new NbrBeds(integer): ";
			cin >> accom_nbrBeds;
			if (cin.eof())
			{
				return;
			}
			break;
		case 8:
			cout << "Enter new ChildrenBed(bool(1/0)): ";
			cin >> accom_childBed;
			if (cin.eof())
			{
				return;
			}
			break;
		case 9:
			if (accom_nbrPeople != -1)
			{
				hotel_room->setNbrPeople(accom_nbrPeople);
			}
			if (accom_size != -1)
			{
				hotel_room->setSize(accom_size);
			}
			if (accom_withBath != -1)
			{
				hotel_room->setBathroomWithBath(static_cast<bool>(accom_withBath));
			}
			if (accom_luxuryLevel != NULL)
			{
				hotel_room->setLuxuryLevel(accom_luxuryLevel);
			}
			if (accom_floor != -1)
			{
				hotel_room->setFloor(accom_floor);
			}
			if (!accom_location.empty())
			{
				hotel_room->setLocation(accom_location);
			}
			if (accom_nbrBeds != -1)
			{
				hotel_room->setNbrBeds(accom_nbrBeds);
			}
			if (accom_childBed != -1)
			{
				hotel_room->setChildrenBed(static_cast<bool>(accom_childBed));
			}
			return;
		default:
			cout << "Invalid input." << endl;
			cin.clear();
			break;
		}
	} while (true);
}

void modifyBungalow(VacationParcs* vp, Accomodations* accom)
{
	int selected_option = -1;
	int accom_nbrPeople = -1;
	int accom_size = -1;
	int accom_withBath = -1; //static_cast<bool>
	int accom_bedrooms = -1;
	Bungalow* bungalow = static_cast<Bungalow*>(accom);
	LuxuryLevel* accom_luxuryLevel = NULL;

	cout << "Bungalow selected to modify.(Don't forget to save changes!)" << endl;
	cout << "\t (1) NbrPeople" << endl;
	cout << "\t (2) Size" << endl;
	cout << "\t (3) BathRoomWithBath" << endl;
	cout << "\t (4) LuxuryLevel" << endl;
	cout << "\t (5) NbrBedrooms" << endl;
	cout << "\t (6) SAVE CHANGES and EXIT." << endl;

	do
	{
		cout << "Enter option: ";
		cin >> selected_option;
		if (cin.eof())
		{
			return;
		}

		switch (selected_option)
		{
		case 1:
			cout << "Enter new NbrPeople(integer): ";
			cin >> accom_nbrPeople;
			if (cin.eof())
			{
				return;
			}
			break;
		case 2:
			cout << "Enter new Size(integer): ";
			cin >> accom_size;
			if (cin.eof())
			{
				return;
			}
			break;
		case 3:
			cout << "Enter new BathRoomWithBath(bool(1/0)): ";
			cin >> accom_withBath;
			if (cin.eof())
			{
				return;
			}
			break;
		case 4:
			accom_luxuryLevel = selectLuxuryLevel(vp);
			if (cin.eof())
			{
				return;
			}
			break;
		case 5:
			cout << "Enter new Bedrooms(integer): ";
			cin >> accom_bedrooms;
			if (cin.eof())
			{
				return;
			}
			break;
		case 6:
			if (accom_nbrPeople != -1)
			{
				bungalow->setNbrPeople(accom_nbrPeople);
			}
			if (accom_size != -1)
			{
				bungalow->setSize(accom_size);
			}
			if (accom_withBath != -1)
			{
				bungalow->setBathroomWithBath(static_cast<bool>(accom_withBath));
			}
			if (accom_luxuryLevel != NULL)
			{
				bungalow->setLuxuryLevel(accom_luxuryLevel);
			}
			if (accom_bedrooms != -1)
			{
				bungalow->setBedrooms(accom_bedrooms);
			}
			return;
		default:
			cout << "Invalid input." << endl;
			cin.clear();
			break;
		}
	} while (true);
}

void deleteAccomodation(VacationParcs* vp)
{
	int accom_index_i = -1;
	int accom_index_j = -1;
	char delete_accom = '\0';
	bool accom_found{ false };
	Accomodations* selected_accom = NULL;

	do
	{
		cin.clear();
		selected_accom = selectAccomodation(vp);
		if (cin.eof())
		{
			cin.clear();
			return;
		}

		if (selected_accom->getIsBooked() == true)
		{
			cout << "----------------------------------------" << endl;
			cout << "Accomodation is booked. Try again later." << endl;
			cout << "----------------------------------------" << endl;
			return;
		}

		for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
		{
			for (size_t j{ 0 }; j < vp->getParcs()[i]->getAccomodations().size(); j++)
			{
				if (selected_accom->getId() == vp->getParcs()[i]->getAccomodations()[j]->getId())
				{
					accom_found = true;
					accom_index_i = static_cast<int>(i);
					accom_index_j = static_cast<int>(j);
					break;
				}
			}
		}

		if (!accom_found)
		{
			cout << "Accomodation not found." << endl;
		}

	} while (!accom_found);

	do
	{
		cout << selected_accom->toString() << endl;
		cout << "If you are sure to delete it enter \"y\": ";
		cin >> delete_accom;
		if (cin.eof())
		{
			cin.clear();
			return;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (!(delete_accom == 'y'))
		{
			cout << "Invalid input, please try again." << endl;
		}
	} while (!(delete_accom == 'y'));

	cout << "Accomodation with id[" << selected_accom->getId() << "] is deleted." << endl;
	delete selected_accom;
	vp->getParcs()[accom_index_i]->getAccomodations().erase(vp->getParcs()[accom_index_i]->getAccomodations().begin() + accom_index_j);
	reWriteAccomodationsFile(vp);
}