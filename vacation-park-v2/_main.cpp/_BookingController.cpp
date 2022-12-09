
#include "_BookingController.h"



void CreateBooking(VacationParcs* vp, Customer* c)
{

	static int booking_id = 1000;
	LuxuryLevel* luxuryLevel_obj;
	Parcs* selected_parc_obj;
	char accom_type;
	int accom_nbrPeople;
	char accom_luxuryLevel;
	int accom_id;
	bool accom_id_found{ false };
	vector<Accomodations*> accoms_filtered;
	vector<Accomodations*> accoms_to_book;
	char add_another_accom;
	bool parc_has_service{ false };
	char include_service;
	bool no_available_accom;

	cout << "---------------------" << endl;
	cout << "LET'S GET YOU BOOKED!" << endl;
	cout << "---------------------" << endl;

	showParcs(vp); // @_parController

	cout << "Here above, is the list of parcs in our system!" << endl;

	do
	{
		selected_parc_obj = selectParc(vp); // @_parcController

		if (selected_parc_obj->getAccomodations().size() == 0)
		{
			cout << "There are no Accomodations available in the park..Please try another park." << endl;
			continue;
		}
		for (size_t i{ 0 }; i < selected_parc_obj->getAccomodations().size(); i++)
		{
			if (selected_parc_obj->getAccomodations()[i]->getIsBooked() == false)
			{
				cout << selected_parc_obj->getAccomodations()[i]->toString() << endl;
			}
		}
	} while (selected_parc_obj->getAccomodations().size() == 0);


	cout << "---------------------------------------------------------- " << endl;
	cout << "Here Above, are the available accomodations from the parc: " << selected_parc_obj->getName() << endl;
	cout << "---------------------------------------------------------- " << endl;

	do
	{
		//initializes accom variables and luxuryLevel_obj and selected_parc
		luxuryLevel_obj = filterAccomodations(vp, accom_type, accom_nbrPeople, accom_luxuryLevel);

		cout << "Your filters are complete!" << endl;
		cout << "Selected park: " << selected_parc_obj->getName() << endl; //initialize parc object!!!!
		cout << (accom_type == 'h' ? " -Hotel selected." : " -Bungalow selected.") << endl; //accom_type can only be 'h' || 'b'
		cout << "Asked for an accomodation for " << accom_nbrPeople << " people." << endl;
		cout << "Selected LuxuryLevel: " << luxuryLevel_obj->getAccomodationKind() << endl;
		cout << endl;
		cout << "Here is the list of accomodations available for you needs!: " << endl;



		cout << "------------------------------------------------------------" << endl;

		//appends accoms_filtered, depending on the filter variables.
		//(!) change names of the variables & make them explicit for filters)
		listFilteredAccomodations(vp, selected_parc_obj, luxuryLevel_obj, accom_nbrPeople, accom_type, accoms_filtered);

		cout << "------------------------------------------------------------" << endl;

		if (!accoms_filtered.size())
		{
			cout << "-----------------------------------------------------------------" << endl;
			cout << "No accomodations found in terms of your demand, please try again." << endl;
			cout << "-----------------------------------------------------------------" << endl;
			cout << "\n\n\n\n";
		}
	} while (accoms_filtered.empty());


	cout << "Let's initialize your Booking!" << endl;
	cout << "To start, we need you to enter the \"ID\" of the desired accomodation from the list above." << endl;
	do
	{
		accom_id_found = false;
		add_another_accom = 'n';

		cout << "ID: ";
		cin >> accom_id;

		for (size_t i{ 0 }; i < accoms_filtered.size(); i++)
		{
			if (accom_id == accoms_filtered[i]->getId())
			{
				if (accoms_filtered[i]->getIsBooked() == false)
				{
					accom_id_found = true;
					accoms_filtered[i]->setIsBooked(true);
					accoms_to_book.push_back(accoms_filtered[i]);

					cout << "#######################################################" << endl;
					cout << "Accomodation added to your booking's accomodation list: " << endl;

					cout << accoms_filtered[i]->toString() << endl;

					cout << "#######################################################" << endl;
				}
			}
		}

		if (!accom_id_found)
		{
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			cout << "Accomodation ID is not in the list, or you have already initialize it for your booking. Try again" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
			continue;
		}



		if (accoms_to_book.size() < 3)
		{

			do
			{
				cout << "Would you like to add another Accomodation to you booking? (y/n):";
				cin >> add_another_accom;

				if (!(add_another_accom == 'y' || add_another_accom == 'n'))
				{
					cout << "Invalid input, please try again." << endl;
				}
			} while (!(add_another_accom == 'y' || add_another_accom == 'n'));
		}
		else
		{
			cout << "Max amount of Accommodations have been reached." << endl;
		}

	} while ((!accom_id_found) || (add_another_accom == 'y'));

	cout << "Here is the list of your accomodations:" << endl;

	for (size_t i{ 0 }; i < accoms_to_book.size(); i++)
	{
		cout << accoms_to_book[i]->toString() << endl;
	}




	cout << "\n\n\n\n";

	bool activityPass{ false };
	bool sportsPass{ false };
	bool bicycleRent{ false };
	bool swimmingPass{ false };

	addService(selected_parc_obj, swimmingPass, sportsPass, bicycleRent, activityPass);

	cout << "Selected Services: " << endl;

	cout << "swimmingPass: " << boolalpha << swimmingPass << endl
		<< "sportsPass: " << boolalpha << sportsPass << endl
		<< "bicycleRent" << boolalpha << bicycleRent << endl
		<< "activityPass: " << boolalpha << activityPass << endl;

	//setBooking()
	vp->setBooking(new Booking(booking_id++, c, accoms_to_book, activityPass, sportsPass, bicycleRent, swimmingPass));
}

void addService(Parcs* selected_parc_obj, bool& swimmingPass, bool& sportsPass, bool& bicycleRent, bool& activityPass)
{

	string subtropic_swimming_pool_name{ "SubtropicSwimmingPool" };
	string sports_infrastructure_name{ "SportsInfrastructure" };
	string bowling_alley_name{ "BowlingAlley" };
	string bicycle_rent_name{ "BicycleRent" };
	string childrens_paradise_name{ "ChildrensParadise" };
	string water_bikes_name{ "WaterBikes" };
	string activity_pass_name{ "Activity Pass" };

	bool parc_subtropic_swimming_pool = selected_parc_obj->getParcServices()->getSubtropicSwimmingPool();
	bool parc_sports_infrastructure = selected_parc_obj->getParcServices()->getSportsInfrastructure();
	bool parc_bowling_alley = selected_parc_obj->getParcServices()->getBowlingAlley();
	bool parc_bicycle_rent = selected_parc_obj->getParcServices()->getBicycleRent();
	bool parc_childrens_paradise = selected_parc_obj->getParcServices()->getChildrensParadise();
	bool parc_water_bikes = selected_parc_obj->getParcServices()->getWaterBikes();
	bool parc_activity_pass{ false };

	//if no service has set to true:
	if (!(parc_subtropic_swimming_pool == true
		|| parc_sports_infrastructure == true
		|| parc_bowling_alley == true
		|| parc_bicycle_rent == true
		|| parc_childrens_paradise == true
		|| parc_water_bikes == true))
	{
		cout << "For some odd reason, there are no service available for this park, sorry about that!" << endl;
	}
	else
	{
		cout << "Select the Parc Services you would like to include with your booking(y/n)." << endl;
	}

	if (parc_subtropic_swimming_pool)
	{
		swimmingPass = addServiceMiddleware(parc_subtropic_swimming_pool, subtropic_swimming_pool_name);
	}
	if (parc_sports_infrastructure)
	{
		sportsPass = addServiceMiddleware(parc_sports_infrastructure, sports_infrastructure_name);
	}
	if (parc_bicycle_rent)
	{
		bicycleRent = addServiceMiddleware(parc_bicycle_rent, bicycle_rent_name);
	}

	if (parc_bowling_alley || parc_childrens_paradise || parc_bicycle_rent)
	{
		parc_activity_pass = true;
		cout << "Any other activities inside the park are included with Activity Pass." << endl;
		activityPass = addServiceMiddleware(parc_activity_pass, activity_pass_name);
	}

}

bool addServiceMiddleware(bool& service_state, string& service_name)
{
	char include_service;
	if (service_state == true)
	{
		do
		{
			cout << service_name << ": ";
			cin >> include_service;
			if (!(include_service == 'y' || include_service == 'n'))
			{
				cout << "Invalid input, please try again." << endl;
			}
		} while (!(include_service == 'y' || include_service == 'n'));

		return include_service == 'y' ? true : false;
	}
}

LuxuryLevel* filterAccomodations(VacationParcs* vp, char& accom_type, int& accom_nbrPeople, char& accom_luxuryLevel)
{
	int luxuryLevel_index;
	bool luxuryLevel_selected{ false };

	do
	{
		cout << "Type of accomodation('h' for hotel, 'b' for bungalow): ";
		cin >> accom_type; //cin to secure

		if (!(accom_type == 'h' || accom_type == 'b'))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please try again." << endl;
		}
	} while (!(accom_type == 'h' || accom_type == 'b'));

	// cin to secure
	cout << "For how many people?: ";
	cin >> accom_nbrPeople;

	do
	{
		do
		{
			cout << "What level of luxury?" << endl;
			cout << " -Choices are VIP,Premium,Comfort (v/p/c):";
			cin >> accom_luxuryLevel;
			if (!(accom_luxuryLevel == 'v' || accom_luxuryLevel == 'p' || accom_luxuryLevel == 'c'))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input, please try again." << endl;
			}
		} while (!(accom_luxuryLevel == 'v' || accom_luxuryLevel == 'p' || accom_luxuryLevel == 'c'));

		switch (accom_luxuryLevel)
		{
		case 'v':
			for (size_t i{ 0 }; i < vp->getLuxuryLevels().size(); i++)
			{
				if (vp->getLuxuryLevels()[i]->getAccomodationKind() == "vip")
				{
					luxuryLevel_index = static_cast<int>(i);
					break;
				}
				else
				{
					luxuryLevel_index = -1;
				}
			}
			luxuryLevel_selected = true;
			break;
		case 'p':
			for (size_t i{ 0 }; i < vp->getLuxuryLevels().size(); i++)
			{
				if (vp->getLuxuryLevels()[i]->getAccomodationKind() == "premium")
				{
					luxuryLevel_index = static_cast<int>(i);
					break;
				}
				else
				{
					luxuryLevel_index = -1;
				}
			}
			luxuryLevel_selected = true;
			break;
		case 'c':
			for (size_t i{ 0 }; i < vp->getLuxuryLevels().size(); i++)
			{
				if (vp->getLuxuryLevels()[i]->getAccomodationKind() == "comfort")
				{
					luxuryLevel_index = static_cast<int>(i);
					break;
				}
				else
				{
					luxuryLevel_index = -1;
				}
			}
			luxuryLevel_selected = true;
			break;
		default:
			cout << "Invalid input, please try again." << endl;
			break;
		}
		if (luxuryLevel_index == -1) //(?) uninitialized
		{
			cout << "Something went wrong! (Refer: luxuryLevel_index)" << endl;
			luxuryLevel_selected = false;
		}
	} while (!luxuryLevel_selected);


	return vp->getLuxuryLevels()[luxuryLevel_index];
}

void listFilteredAccomodations(VacationParcs* vp, Parcs* selected_parc_obj, LuxuryLevel* luxuryLevel_obj, int& accom_nbrPeople, char& accom_type, vector<Accomodations*>& accoms_filtered)
{
	cout << "---------------------------------------" << endl;
	cout << "Accomodations included inside the Parc: " << selected_parc_obj->getName() << endl;
	cout << "---------------------------------------" << endl;
	vector<HotelRoom*> hotelrooms;
	vector<Bungalow*> bungalows;
	switch (accom_type)
	{
	case 'h':
		for (size_t i{ 0 }; i < selected_parc_obj->getAccomodations().size(); i++)
		{
			if (typeid(*selected_parc_obj->getAccomodations()[i]) == typeid(HotelRoom))
			{
				//hotelrooms.push_back(static_cast<HotelRoom*>(selected_parc_obj->getAccomodations()[i]));
				if (selected_parc_obj->getAccomodations()[i]->getIsBooked() == false && selected_parc_obj->getAccomodations()[i]->getNbrPeople() >= accom_nbrPeople && selected_parc_obj->getAccomodations()[i]->getLuxuryLevel() == luxuryLevel_obj)
				{
					accoms_filtered.push_back(selected_parc_obj->getAccomodations()[i]);
				}
			}
		}
		for (size_t i{ 0 }; i < accoms_filtered.size(); i++)
		{
			cout << accoms_filtered[i]->toString() << endl;
		}
		break;
	case 'b':
		for (size_t i{ 0 }; i < selected_parc_obj->getAccomodations().size(); i++)
		{
			if (typeid(*selected_parc_obj->getAccomodations()[i]) == typeid(Bungalow))
			{
				if (selected_parc_obj->getAccomodations()[i]->getIsBooked() == false && selected_parc_obj->getAccomodations()[i]->getNbrPeople() >= accom_nbrPeople && selected_parc_obj->getAccomodations()[i]->getLuxuryLevel() == luxuryLevel_obj)
				{
					accoms_filtered.push_back(selected_parc_obj->getAccomodations()[i]);
				}
			}
		}
		for (size_t i{ 0 }; i < accoms_filtered.size(); i++)
		{
			cout << accoms_filtered[i]->toString() << endl;
		}
		break;
	}
}

void showBookings(VacationParcs* vp)
{
	cout << "Current Bookings in the system: " << endl;

	for (size_t i{ 0 }; i < vp->getBookings().size(); i++)
	{
		cout << vp->getBookings()[i]->toString() << endl;
	}
}

