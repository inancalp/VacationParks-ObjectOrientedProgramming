
#include "_BookingController.h"
#include "_AccomodationController.h"

void saveBookingFile(Booking* booking)
{

	ofstream bookingsFile(BOOKINGSFILE, ios::out | ios::app);

	if (!bookingsFile)
	{
		cout << "savebookingfile() ->> something went wrong while opening \"bookings.txt\" file." << endl;
		return;
	}
	
	bookingsFile
		<< booking->getId() << " "
		<< booking->getCustomer()->getEmail() << " "; //customer will be retrieved with using email
	
	bookingsFile
		<< booking->getAccomodations().size() << " "; //size is stored to be used in loop when retrieving vector data

	for (size_t i{ 0 }; i < booking->getAccomodations().size(); i++)
	{
		bookingsFile
			<< booking->getAccomodations()[i]->getId() << " "; //IDs for the accomodations stored to retrieve later.
	}

	bookingsFile
		<< booking->getActivityPass() << " "
		<< booking->getSportPass() << " "
		<< booking->getBicycleRent() << " "
		<< booking->getSwimmingPass() << endl;

	cout << "Booking::getId() ->> " << booking->getId() << " is stored." << endl;
	bookingsFile.close();

}

void retrieveBookingsFile(VacationParcs* vp)
{
	int booking_id;
	string booking_customer_email;
	Customer* booking_customer_obj = nullptr;
	int booking_amount_accomodations;
	int booking_accomodation_id;
	vector<Accomodations*> booking_accomodations;
	bool booking_activityPass;
	bool booking_sportsPass;
	bool booking_bicycleRent;
	bool booking_swimmingPass;

	ifstream bookingsFile(BOOKINGSFILE, ios::in);
	if (!bookingsFile)
	{
		cout << "savebookingfile() ->> something went wrong while opening \"bookings.txt\" file." << endl;
		return;
	}

	while (bookingsFile >> booking_id)
	{
		//retrieve customer
		bookingsFile >> booking_customer_email;
		for (size_t i{ 0 }; i < vp->getCustomers().size(); i++)
		{
			if (booking_customer_email == vp->getCustomers()[i]->getEmail())
			{
				booking_customer_obj = vp->getCustomers()[i];
				break;
			}
		}

		//retrieve accomodations
		booking_accomodations.clear(); //needs to be cleaned, otherwise all accoms that been retrieved stays.
		bookingsFile >> booking_amount_accomodations;
		for (size_t i{ 0 }; i < booking_amount_accomodations; i++)
		{
			bookingsFile >> booking_accomodation_id;
			for (size_t j{ 0 }; j < vp->getParcs().size(); j++)
			{
				for (size_t k{ 0 }; k < vp->getParcs()[j]->getAccomodations().size(); k++)
				{
					if (vp->getParcs()[j]->getAccomodations()[k]->getId() == booking_accomodation_id)
					{
						booking_accomodations.push_back(vp->getParcs()[j]->getAccomodations()[k]);
					}
				}
			}
		}

		//retrieve parcServices
		bookingsFile
			>> booking_activityPass
			>> booking_sportsPass
			>> booking_bicycleRent
			>> booking_swimmingPass;

		//construct Bookings
		vp->setBooking(
			new Booking(
				booking_id,
				booking_customer_obj,
				booking_accomodations,
				booking_activityPass,
				booking_sportsPass,
				booking_bicycleRent,
				booking_swimmingPass
			));
	}

	bookingsFile.close();

}

void reWriteBookingsFile(VacationParcs* vp)
{
	ofstream bookingsFile(BOOKINGSFILE, ios::out);
	if (!bookingsFile)
	{
		cout << "reWritebookingfile() ->> something went wrong while opening \"bookings.txt\" file." << endl;
		return;
	}

	for (Booking* booking : vp->getBookings())
	{
		bookingsFile
			<< booking->getId() << " "
			<< booking->getCustomer()->getEmail() << " "; //customer will be retrieved with using email

		bookingsFile
			<< booking->getAccomodations().size() << " "; //size is stored to be used in loop when retrieving vector data

		for (size_t i{ 0 }; i < booking->getAccomodations().size(); i++)
		{
			bookingsFile
				<< booking->getAccomodations()[i]->getId() << " "; //IDs for the accomodations stored to retrieve later.
		}

		bookingsFile
			<< booking->getActivityPass() << " "
			<< booking->getSportPass() << " "
			<< booking->getBicycleRent() << " "
			<< booking->getSwimmingPass() << endl;

		cout << "Booking::getId() ->> " << booking->getId() << " is stored." << endl;
	}

	bookingsFile.close();
}


void CreateBooking(VacationParcs* vp, Customer* customer)
{

	bool luxuryLevel_selected{ false };
	bool no_bookings_found{ true };
	bool add_another_accom{ false };

	int booking_id = -1;
	int luxuryLevel_index = -1;
	int accom_nbrPeople = -1;

	char accom_luxuryLevel = '\0';
	char accom_type = '\0';
	char add_another_accom_char = '\0';
	string accom_typeid = "\0";

	Parcs* selected_parc_obj = NULL;
	Booking* booking = NULL;
	LuxuryLevel* ll = NULL;

	vector<Accomodations*> accoms_filtered;
	vector<Accomodations*> accoms_to_book;
	vector<Accomodations*> available_accoms;


	//unique_id
	for (size_t i{ 0 }; i < vp->getBookings().size(); i++)
	{
		if (booking_id <= vp->getBookings()[i]->getId())
		{
			booking_id = vp->getBookings()[i]->getId() + 1;
		}
		no_bookings_found = false;
	}
	if (no_bookings_found)
	{
		booking_id = 100;
	}

	showParcs(vp); // @_parController
	selected_parc_obj = selectParc(vp);
	if (cin.eof())
	{
		cin.clear();
		return;
	}

	do
	{
		add_another_accom = false;
		accoms_filtered.clear(); //empty the vector to fill back in.
		available_accoms.clear();
		setAvailableAccomodations(selected_parc_obj, available_accoms, accoms_to_book);
		showAvailableAccomodations(available_accoms);

		//hotel_or_bungalow
		accom_typeid = filterAccomodationType();
		if (cin.eof())
		{
			cin.clear();
			return;
		}

		if (accom_typeid == "continue")
		{
			if (accoms_to_book.empty())
			{
				cout << endl;
				cout << "----------------------------------------------------------------------" << endl;
				cout << "(!) There are no accomodation selected. Canceling the Booking Process." << endl;
				cout << "----------------------------------------------------------------------" << endl << endl;
				return;
			}
			continue;
		}

		//amount_of_people
		cout << "For how many people?: ";
		cin >> accom_nbrPeople;
		if (cin.eof())
		{
			cin.clear();
			return;
		}

		//level_of_luxury
		ll = filterAccomodationLuxuryLevel(vp);
		if (cin.eof())
		{
			cin.clear();
			return;
		}

		//filter available accomodation into an array
		for (size_t i{ 0 }; i < available_accoms.size(); i++)
		{
			if (typeid(*available_accoms[i]).name() == accom_typeid
				&& accom_nbrPeople <= available_accoms[i]->getNbrPeople()
				&& available_accoms[i]->getLuxuryLevel()->getAccomodationKind() == ll->getAccomodationKind())
			{
				accoms_filtered.push_back(available_accoms[i]);
			}
		}

		if (!accoms_filtered.empty())
		{
			showFilteredAccomodations(accoms_filtered);
			addAccomodationToBooking(accoms_filtered, accoms_to_book);
			if (cin.eof())
			{
				cin.clear();
				return;
			}
		}
		else
		{
			cout << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << "(!) There are no Accomodations available in the range of user's request." << endl;
			add_another_accom = true; //so can loop again.
			continue;
		}

		if (accoms_to_book.size() == 3)
		{
			cout << endl << "(!) Maximum amount for Accomodations per Booking has been reached." << endl;
			continue;
		}

		//ask if user wants to add another accom to booking.
		cout << "Would you like to add another Accomodation to you Booking?(y/n): ";
		cin >> add_another_accom_char;
		if (cin.eof())
		{
			cin.clear();
			return;
		}
		if (add_another_accom_char == 'y')
		{
			add_another_accom = true;
		}
		if (add_another_accom_char == 'n')
		{
			add_another_accom = false;
		}

	} while (accoms_to_book.size() <= 3 && add_another_accom == true);

	cout << endl;
	cout << "----------------------------------------------------------  " << endl;
	cout << "Here are the Accomodations user has picked for the Booking: " << endl << endl;

	for (size_t i{ 0 }; i < accoms_to_book.size(); i++)
	{
		cout << " ->>";
		cout << accoms_to_book[i]->toString() << endl;
	}




	//selectParcServices here below
	bool activityPass{ false };
	bool sportsPass{ false };
	bool bicycleRent{ false };
	bool swimmingPass{ false };

	addService(selected_parc_obj, swimmingPass, sportsPass, bicycleRent, activityPass);
	if (cin.eof())
	{
		cout << endl << "(!) Booking is canceled." << endl;
		cin.clear();
		return;
	}

	cout << "Selected Services: " << endl;
	cout << "swimmingPass: " << boolalpha << swimmingPass << endl
		<< "sportsPass: " << boolalpha << sportsPass << endl
		<< "bicycleRent: " << boolalpha << bicycleRent << endl
		<< "activityPass: " << boolalpha << activityPass << endl;
	
	//change state of accomodations
	for (size_t i{ 0 }; i < accoms_to_book.size(); i++)
	{
		accoms_to_book[i]->setIsBooked(true);
	}

	//constructing && saving into file below.
	booking = new Booking(booking_id,customer,accoms_to_book,activityPass,sportsPass,bicycleRent,swimmingPass);
	vp->setBooking(booking);
	saveBookingFile(booking);
	//since state of accomodations has changed.
	reWriteAccomodationsFile(vp);
}

void setAvailableAccomodations(Parcs* selected_parc_obj, vector<Accomodations*>& available_accoms, vector<Accomodations*>& accoms_to_book)
{
	bool accom_in_accoms_to_book = false;
	for (size_t i{ 0 }; i < selected_parc_obj->getAccomodations().size(); i++)
	{
		accom_in_accoms_to_book = false;
		if (selected_parc_obj->getAccomodations()[i]->getIsBooked() == false)
		{
			for (size_t j{ 0 }; j < accoms_to_book.size(); j++)
			{
				if (accoms_to_book[j]->getId() == selected_parc_obj->getAccomodations()[i]->getId())
				{
					accom_in_accoms_to_book = true;
					break; //(?)
				}
			}
			if (!accom_in_accoms_to_book)
			{
				available_accoms.push_back(selected_parc_obj->getAccomodations()[i]);
			}
		}
	}
}

void showAvailableAccomodations(vector<Accomodations*>& available_accoms)
{
	cout << endl;
	cout << "-----------------------------------------------------  " << endl;
	cout << "Here are the Available Accomodations for your Booking: " << endl;
	cout << "-----------------------------------------------------  " << endl << endl;

	if (available_accoms.size() == 0)
	{
		cout << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "There are no Avaliable Accomodations at the moment. Please Continue with your current selections or exit from the process." << endl << endl;
		return;
	}

	for (size_t i{ 0 }; i < available_accoms.size(); i++)
	{
		cout << " ->>\t";
		cout << available_accoms[i]->toString() << endl;
	}
}

string filterAccomodationType()
{
	char accom_type;
	string accom_typeid;

	do
	{
		cout << "Enter, \"h\" for HotelRoom, \"b\" for Bungalow, \"c\" to continue booking process: ";
		cin >> accom_type;
		if (cin.eof())
		{
			return "\0";
		}
		if (accom_type == 'c')
		{
			return "continue";
		}

		if (!(accom_type == 'h' || accom_type == 'b'))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please try again." << endl;
		}
	} while (!(accom_type == 'h' || accom_type == 'b'));

	switch (accom_type)
	{
	case 'h':
		accom_typeid = typeid(HotelRoom).name();
		break;
	case 'b':
		accom_typeid = typeid(Bungalow).name();
		break;
	}

	return accom_typeid;
}

LuxuryLevel* filterAccomodationLuxuryLevel(VacationParcs* vp)
{
	char accom_luxuryLevel;
	int luxuryLevel_index = -1;

	do
	{
		cout << "What level of luxury?" << endl;
		cout << "Enter, \"v\" for VIP, \"p\" for Premium, \"c\" for Comfort: ";
		cin >> accom_luxuryLevel;
		if (cin.eof())
		{
			return NULL;
		}

		if (!(accom_luxuryLevel == 'v' || accom_luxuryLevel == 'p' || accom_luxuryLevel == 'c'))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please try again." << endl;
			continue;
		}
		break;
	} while (true);

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
		}
		break;
	case 'p':
		for (size_t i{ 0 }; i < vp->getLuxuryLevels().size(); i++)
		{
			if (vp->getLuxuryLevels()[i]->getAccomodationKind() == "premium")
			{
				luxuryLevel_index = static_cast<int>(i);
				break;
			}
		}
		break;
	case 'c':
		for (size_t i{ 0 }; i < vp->getLuxuryLevels().size(); i++)
		{
			if (vp->getLuxuryLevels()[i]->getAccomodationKind() == "comfort")
			{
				luxuryLevel_index = static_cast<int>(i);
				break;
			}
		}
		break;
	default:
		cout << "Invalid input, please try again." << endl;
		break;
	}

	return vp->getLuxuryLevels()[luxuryLevel_index];
}

void showFilteredAccomodations(vector<Accomodations*>& accoms_filtered)
{
	cout << endl;
	cout << "--------------------------------------------------  " << endl;
	cout << "Accomodations available in range of user's request: " << endl << endl;
	for (size_t i{ 0 }; i < accoms_filtered.size(); i++)
	{
		cout << " ->>";
		cout << accoms_filtered[i]->toString() << endl;
	}
}

void addAccomodationToBooking(vector<Accomodations*>& accoms_filtered, vector<Accomodations*>& accoms_to_book)
{
	
	int accom_id;
	bool accom_not_in_list {true};

	do
	{
		cout << "ID: ";
		cin >> accom_id;
		if (cin.eof())
		{
			return;
		}

		for (size_t i{ 0 }; i < accoms_filtered.size(); i++)
		{
			if (accom_id == accoms_filtered[i]->getId())
			{
				accoms_to_book.push_back(accoms_filtered[i]);
				accom_not_in_list = false;
				break;
			}
		}

		if (accom_not_in_list)
		{
			cout << "Accomodation is not in the list, please try again." << endl;
		}
	} while (accom_not_in_list);

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
		cout << "----------------------------------------------------------------------------------------" << endl;
		cout << "(!) For some odd reason, there are no service available for this park, sorry about that!" << endl;
	}
	else
	{
		cout << "Select Parc Services(y/n)." << endl;
	}

	if (parc_subtropic_swimming_pool)
	{
		swimmingPass = addServiceMiddleware(parc_subtropic_swimming_pool, subtropic_swimming_pool_name);
		if (cin.eof())
		{
			return;
		}
	}
	if (parc_sports_infrastructure)
	{
		sportsPass = addServiceMiddleware(parc_sports_infrastructure, sports_infrastructure_name);
		if (cin.eof())
		{
			return;
		}
	}
	if (parc_bicycle_rent)
	{
		bicycleRent = addServiceMiddleware(parc_bicycle_rent, bicycle_rent_name);
		if (cin.eof())
		{
			return;
		}
	}

	if (parc_bowling_alley || parc_childrens_paradise || parc_bicycle_rent)
	{
		parc_activity_pass = true;
		cout << "Any other activities inside the park are included with Activity Pass." << endl;
		activityPass = addServiceMiddleware(parc_activity_pass, activity_pass_name);
		if (cin.eof())
		{
			return;
		}
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
			if (cin.eof())
			{
				return NULL;
			}

			if (!(include_service == 'y' || include_service == 'n'))
			{
				cout << "Invalid input, please try again." << endl;
			}
		} while (!(include_service == 'y' || include_service == 'n'));

		return include_service == 'y' ? true : false;
	}
}

void showBookings(VacationParcs* vp)
{
	string parc_name;
	int count_bookings;
	for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
	{
		parc_name = vp->getParcs()[i]->getName();
		count_bookings = 0;
		cout << endl << "->> Bookings included in Parcs::getName() ->> " << parc_name << endl << endl;
		for (size_t j{ 0 }; j < vp->getBookings().size(); j++)
		{
			if (vp->getBookings()[j]->getAccomodations()[0]->getParcName() == parc_name)
			{
				count_bookings++;
				cout << "    ->>";
				cout << vp->getBookings()[j]->toString();
			}
		}

		if (count_bookings == 0)
		{
			cout << "(!) There are no Bookings included within the Parcs::getName() ->> " << parc_name << endl << endl;
		}
	}

}

void showCustomersBookings(VacationParcs* vp, Customer* customer)
{
	bool customer_has_no_bookings{ true };
	cout << endl << "Here are the bookings of Customer::getEmail() ->> " << customer->getEmail() << endl << endl;
	for (size_t i{ 0 }; i < vp->getBookings().size(); i++)
	{
		if (vp->getBookings()[i]->getCustomer()->getEmail() == customer->getEmail())
		{
			customer_has_no_bookings = false;
			cout << " ->>";
			cout << vp->getBookings()[i]->toString() << endl;
		}
	}
	if (customer_has_no_bookings)
	{
		cout << endl;
		cout << "------------------------------------------------" << endl;
		cout << "(!) User has no Bookings recorded in the system!" << endl;
		cout << "------------------------------------------------" << endl;
	}
}

void ModifyBookings(VacationParcs* vp, Customer* customer)
{

}