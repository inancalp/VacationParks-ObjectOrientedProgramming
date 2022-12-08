#include "_ParcController.h"


//createParcServices() included in createParc();
ParcServices* createParcServices(string& parc_name)
{
	char selected_option{'\0'};
	cout << "Select Services included with the Parc" << endl;
	cout << "(y)es/(n)o/(e)xit: " << endl;

	array<bool, PARCSERVICESSIZE> parc_services{};
	array<string, PARCSERVICESSIZE> parc_service_names = {
		"SubtropicSwimmingPool",
		"SportsInfrastructure",
		"BowlingAlley",
		"BicycleRent",
		"ChildrensParadise",
		"WaterBikes"
	};

	for (size_t i{0}; i < parc_services.size(); i++)
	{

		while (!selected_option)
		{
			cout << "-> " << parc_service_names[i] << ": " << right;
			cin >> selected_option;
			if (!cin) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input please try again." << endl;
				selected_option = '\0'; //
				continue;
			}
			switch (selected_option)
			{
			case 'y':
				parc_services[i] = true;
				break;
			case 'n':
				parc_services[i] = false;
				break;
			case 'e':
				//exit
				return NULL; //null for return object.
			default:
				cout << "Invalid input please try again." << endl;
				selected_option = '\0';
				break;
			}
		}
		selected_option = '\0';
	}

	//update in case PARCSERVICESSIZE changes.
	return new ParcServices(parc_name, parc_services[0], parc_services[1], parc_services[2], parc_services[3], parc_services[4], parc_services[5]);

}

void saveParcFile(Parcs* parc)
{
	ofstream parcsFile(PARCSFILE, ios::out | ios::app);
	if (!parcsFile)
	{
		cout << "Error occured while opening parcs.txt file" << endl;
		return;
	}
	
	parcsFile << parc->getName() << " " << parc->getAddress() << endl;

	parcsFile.close();

	saveParcServicesFile(parc->getParcServices()); 

}

void saveParcServicesFile(ParcServices* parc_services)
{
	ofstream parcServicesFile(PARCSERVICESFILE, ios::out | ios::app);

	if (!parcServicesFile)
	{
		cout << "Error occured while opening parcs.txt file" << endl;
		return;
	}

	parcServicesFile <<
		parc_services->getParcName() << " " <<
		parc_services->getSubtropicSwimmingPool() << " " <<
		parc_services->getSportsInfrastructure() << " " <<
		parc_services->getBowlingAlley() << " " <<
		parc_services->getBicycleRent() << " " <<
		parc_services->getChildrensParadise() << " " <<
		parc_services->getWaterBikes() << endl;

	parcServicesFile.close();
}

void reWriteParcsFile(VacationParcs* vp)
{
	ofstream parcsFile(PARCSFILE, ios::out);

	if (!parcsFile)
	{
		cout << "Error occured while opening parcs.txt file" << endl;
		return;
	}

	emptyParcServicesFile();

	for (Parcs* parc : vp->getParcs())
	{
		cout << "Parc -> " << parc->getName() << " is being manipulated" << endl;
		parcsFile << parc->getName() << " " << parc->getAddress() << endl;
		saveParcServicesFile(parc->getParcServices());
	}

	parcsFile.close();

}

void emptyParcServicesFile()
{
	ofstream parcServicesFile(PARCSERVICESFILE, ios::out);

	if (!parcServicesFile)
	{
		cout << "Error occured while opening parcs.txt file" << endl;
		return;
	}

	parcServicesFile.close();
}

void retrieveParcsFile(VacationParcs* vp)
{
	string parc_name;
	string parc_address;

	ifstream parcsFile(PARCSFILE, ios::in);
	ifstream parcServicesFile(PARCSERVICESFILE, ios::in);

	if (!parcsFile)
	{
		cout << "Error occured while opening parcs.txt file" << endl;
		return;
	}

	while (parcsFile >> parc_name >> parc_address)
	{
		vp->setParc(new Parcs(parc_name, parc_address, retrieveParcServicesFile(parcServicesFile)));
	}
	parcServicesFile.close();
	parcsFile.close();
}

ParcServices* retrieveParcServicesFile(ifstream& parcServicesFile)
{
	array<bool, PARCSERVICESSIZE> parc_services;
	bool parc_service_value;
	string parc_name;

	parcServicesFile >> parc_name;

	for (size_t i{ 0 }; i < PARCSERVICESSIZE; i++)
	{
		parcServicesFile >> parc_service_value;
		cout << "ParcName! = " << parc_name << endl;
		cout << "ParcServicesValue! = " << parc_service_value << endl;
		parc_services[i] = parc_service_value;
	}

	return new ParcServices(
		parc_name,
		parc_services[0],
		parc_services[1],
		parc_services[2],
		parc_services[3],
		parc_services[4],
		parc_services[5]
	);
}


//Parcs CRUD
void createParc(VacationParcs* vp)
{

	string parc_name;
	string parc_address;
	ParcServices* parc_services;
	Parcs* parc;
	bool parc_created{ false };
	bool parc_name_taken{ false };
	bool parc_address_taken{ false };

	while (parc_created == false)
	{
		do
		{
			cout << "Parc Name: ";
			cin >> parc_name;
			for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
			{
				if (vp->getParcs()[i]->getName() == parc_name)
				{
					cout << "------------------------------------------------------" << endl;
					cout << "Parc Name is already in use, please try another one." << endl;
					cout << "------------------------------------------------------" << endl;
					parc_name_taken = true;
					break;
				}
				else
				{
					parc_name_taken = false;
				}
			}

		} while (parc_name_taken);


		if (parc_name == "exit")
		{
			return;
		}

		do
		{
			cout << "Parc Address: ";
			cin >> parc_address;
			for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
			{
				if (vp->getParcs()[i]->getAddress() == parc_address)
				{
					cout << "--------------------------------------------------------" << endl;
					cout << "Parc Address is already in use, please try another one." << endl;
					cout << "--------------------------------------------------------" << endl;
					parc_address_taken = true;
					break;
				}
				else
				{
					parc_address_taken = false;
				}
			}
		} while (parc_address_taken);

		if (parc_address == "exit")
		{
			return;
		}

		if (parc_name_taken == false && parc_address_taken == false) {
			parc_created = true;
		}
	}
	parc_services = createParcServices(parc_name);

	if (parc_services == NULL)
	{
		delete parc_services;
		return;
	}

	parc = new Parcs(parc_name, parc_address, parc_services);
	saveParcFile(parc);
	vp->setParc(parc);


	cout << "-------------------" << endl;
	cout << "End of createParc()" << endl;
	cout << "-------------------" << endl;
}

void showParcs(VacationParcs* vp)
{
	cout << "-------------------------" << endl;
	cout << "Parcs included in the system of VacationParcs::getName() ->> " << vp->getName() << endl;
	for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
	{
		cout << vp->getParcs()[i]->toString() << endl;
	}
	cout << "-------------------------" << endl;
}

void changeParc(VacationParcs* vp)
{
	string parc_name;
	int parc_index;
	bool parc_found{ false };
	char service_num;
	char change_another_service;
	bool bool_another_service;
	bool invalid_input;

	Parcs* selected_parc;
	ParcServices* selected_services;

	string subtropic_swimming_pool_name{ "SubtropicSwimmingPool" };
	string sports_infrastructure_name{ "SportsInfrastructure" };
	string bowling_alley_name{ "BowlingAlley" };
	string bicycle_rent_name{ "BicycleRent" };
	string childrens_paradise_name{ "ChildrensParadise" };
	string water_bikes_name{ "WaterBikes" };

	bool subtropic_swimming_pool_val;
	bool sports_infrastructure_val;
	bool bowling_alley_val;
	bool bicycle_rent_val;
	bool childrens_paradise_val;
	bool water_bikes_val;


	cout << "------------------------------------------------------" << endl;

	invalid_input = false;
	do
	{
		cout << "Enter the name of the park to see Services available: ";
		cin >> parc_name;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input please try again." << endl;
			parc_name = '\0';
			continue;
		}

		if (parc_name == "exit")
		{
			return;
		}

		for (int i{ 0 }; i < vp->getParcs().size(); i++)
		{
			if (vp->getParcs()[i]->getName() == parc_name)
			{
				parc_index = i; // (!)
				parc_found = true;
			}
		}
		if (!parc_found)
		{
			cout << "Parc name can't be found on the system. Try again." << endl;
		}
	} while (!parc_found);

	cout << "------------------------------------------------------" << endl;

	selected_parc = vp->getParcs()[parc_index];
	selected_services = selected_parc->getParcServices();

	subtropic_swimming_pool_val = selected_services->getSubtropicSwimmingPool();
	sports_infrastructure_val = selected_services->getSportsInfrastructure();
	bowling_alley_val = selected_services->getBowlingAlley();
	bicycle_rent_val = selected_services->getBicycleRent();
	childrens_paradise_val = selected_services->getChildrensParadise();
	water_bikes_val = selected_services->getWaterBikes();

	cout << "-----------------------------" << endl;
	cout << "ParcServices::toString() ->> " << endl;
	cout << selected_parc->toString() << endl;
	cout << "-----------------------------" << endl;

	do
	{
		cout << "------------------------------------------------------------------" << endl;
		cout << "Enter the number for the service you would like to add or remove or use \"e\" to exit: ";
		cin >> service_num;

		switch (service_num)
		{
		case '1':
			cout << "--------------" << endl;
			cout
				<< subtropic_swimming_pool_name
				<< " has change from \""
				<< boolalpha << subtropic_swimming_pool_val
				<< "\" to \"" << !subtropic_swimming_pool_val
				<< "\"."
				<< endl;
			cout << "--------------" << endl;
			subtropic_swimming_pool_val = !subtropic_swimming_pool_val;
			selected_services->setSubtropicSwimmingPool(subtropic_swimming_pool_val);
			break;
		case '2':
			cout << "--------------" << endl;
			cout
				<< sports_infrastructure_name
				<< " has change from \""
				<< boolalpha << sports_infrastructure_val
				<< "\" to \"" << !sports_infrastructure_val
				<< "\"."
				<< endl;
			cout << "--------------" << endl;
			sports_infrastructure_val = !sports_infrastructure_val;
			selected_services->setSportsInfrastructure(sports_infrastructure_val);
			break;
		case '3':
			cout << "--------------" << endl;
			cout
				<< bowling_alley_name
				<< " has change from \""
				<< boolalpha << bowling_alley_val
				<< "\" to \"" << !bowling_alley_val
				<< "\"."
				<< endl;
			cout << "--------------" << endl;
			bowling_alley_val = !bowling_alley_val;
			selected_services->setBowlingAlley(bowling_alley_val);
			break;
		case '4':
			cout << "--------------" << endl;
			cout
				<< bicycle_rent_name
				<< " has change from \""
				<< boolalpha << bicycle_rent_val
				<< "\" to \"" << !bicycle_rent_val
				<< "\"."
				<< endl;
			cout << "--------------" << endl;
			bicycle_rent_val = !bicycle_rent_val;
			selected_services->setBicycleRent(bicycle_rent_val);
			break;
		case '5':
			cout << "--------------" << endl;
			cout
				<< childrens_paradise_name
				<< " has change from \""
				<< boolalpha << childrens_paradise_val
				<< "\" to \"" << !childrens_paradise_val
				<< "\"."
				<< endl;
			cout << "--------------" << endl;
			childrens_paradise_val = !childrens_paradise_val;
			selected_services->setChildrensParadise(childrens_paradise_val);
			break;
		case '6':
			cout << "--------------" << endl;
			cout
				<< water_bikes_name
				<< " has change from \""
				<< boolalpha << water_bikes_val
				<< "\" to \"" << !water_bikes_val
				<< "\"."
				<< endl;
			cout << "--------------" << endl;
			water_bikes_val = !water_bikes_val;
			selected_services->setWaterBikes(water_bikes_val);
			break;
		case 'e':
			cout << "Updated Parc Object: " << endl;
			cout << selected_services->toString() << endl;
			reWriteParcsFile(vp);
			return; //exit
		default:
			cout << "--------------" << endl;
			cout << "Invalid input, try again." << endl;
			cout << "--------------" << endl;
			invalid_input = true;
			break;
		}
	
		if (invalid_input)
		{
			continue;
		}

		while (true)
		{
			cout << "Would you like to make another change?(y/n): ";
			cin >> change_another_service;
			if (change_another_service == 'y')
			{
				bool_another_service = true;
				break;
			}
			else if (change_another_service == 'n')
			{
				bool_another_service = false;
				break;
			}
			else
			{
				cout << "Invalid input, please try again." << endl;
			}
		}
		if (change_another_service == 'n')
		{
			break;
		}

	} while ((service_num < 1 || service_num > 6) || bool_another_service);

	reWriteParcsFile(vp);
}

void deleteParc(VacationParcs* vp)
{
	string parc_name;
	int parc_index;
	bool parc_found{ false };
	char delete_parc;

	do
	{
		cout << "--------------------------------------------------------" << endl;
		cout << "Enter the name of the park to that needs to be deleted: ";
		cin >> parc_name;
		for (int i{ 0 }; i < vp->getParcs().size(); i++)
		{
			if (vp->getParcs()[i]->getName() == parc_name)
			{
				parc_index = i; // (!)
				parc_found = true;
			}
		}
		if (!parc_found)
		{
			cout << "Parc name can't be found on the system. Try again." << endl;
		}
	} while (!parc_found);

	cout << "--------------------------------------------------------" << endl;
	cout << "Here is the information for the parc to be deleted: " << endl;
	cout << vp->getParcs()[parc_index]->toString() << endl;
	cout << "--------------------------------------------------------" << endl;

	do
	{
		cout << "--------------------------------------------------------" << endl;
		cout << "If you are sure to delete it enter \"y\", else enter \"n\".: ";
		cin >> delete_parc;

		if (!(delete_parc == 'y' || delete_parc == 'n'))
		{
			cout << "Invalid input, please try again." << endl;
		}
	} while (!(delete_parc == 'y' || delete_parc == 'n'));

	cout << "--------------------------------------------------------" << endl;

	if (delete_parc == 'y')
	{
		cout << "---------------------" << endl;
		cout << vp->getParcs()[parc_index]->getName() << " IS deleted." << endl;
		cout << "---------------------" << endl;
		delete vp->getParcs()[parc_index];
		vp->getParcs().erase(vp->getParcs().begin() + parc_index);

	}
	else
	{
		cout << "---------------------" << endl;
		cout << vp->getParcs()[parc_index]->getName() << " IS NOT deleted." << endl;
		cout << "---------------------" << endl;
	}

	reWriteParcsFile(vp);

}

Parcs* selectParc(VacationParcs* vp)
{
	string parc_name;
	int parc_index;
	bool parc_name_found{ false };
	int i;

	do
	{
		cout << "Please enter the \"name\" of the Parc: ";
		cin >> parc_name; //cin to secure

		for (i = 0; i < vp->getParcs().size(); i++)
		{
			if (vp->getParcs()[i]->getName() == parc_name)
			{
				parc_name_found = true;
				break;
			}
		}

		if (!parc_name_found)
		{
			cout << "Invalid ParcName, please try again!" << endl;
		}

	} while (!parc_name_found);

	for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
	{
		if (parc_name == vp->getParcs()[i]->getName())
		{
			parc_index = i;
			break;
		}
	}

	return vp->getParcs()[parc_index];
}