#include "_ParcController.h"





//ParcServices
ParcServices* createParcServices()
{
	int subtropic_swimming_pool;
	int sports_infrastructure;
	int bowling_alley;
	int bicycle_rent;
	int childrens_paradise;
	int water_bikes;
	string subtropic_swimming_pool_name{ " -> SubtropicSwimmingPool: " };
	string sports_infrastructure_name{ " -> SportsInfrastructure: " };
	string bowling_alley_name{ " -> BowlingAlley: " };
	string bicycle_rent_name{ " -> BicycleRent: " };
	string childrens_paradise_name{ " -> ChildrensParadise: " };
	string water_bikes_name{ " -> WaterBikes: " };

	cout << "Select Services included with the Parc" << endl;
	cout << "(1) to include, (0) to not: " << endl;

	createParcServicesMiddleWare(subtropic_swimming_pool, subtropic_swimming_pool_name);
	createParcServicesMiddleWare(sports_infrastructure, sports_infrastructure_name);
	createParcServicesMiddleWare(bowling_alley, bowling_alley_name);
	createParcServicesMiddleWare(bicycle_rent, bicycle_rent_name);
	createParcServicesMiddleWare(childrens_paradise, childrens_paradise_name);
	createParcServicesMiddleWare(water_bikes, water_bikes_name);

	return new ParcServices
	(
		static_cast<bool>(subtropic_swimming_pool),
		static_cast<bool>(sports_infrastructure),
		static_cast<bool>(bowling_alley),
		static_cast<bool>(bicycle_rent),
		static_cast<bool>(childrens_paradise),
		static_cast<bool>(water_bikes)
	);
}

void createParcServicesMiddleWare(int& data, string& data_name)
{
	do
	{
		cout << setw(28) << left << data_name << right;
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



//Parcs CRUD
void createParc(VacationParcs* vp)
{
	string name;
	string address;

	bool parc_created{ false };
	bool parc_name_taken{ false };
	bool parc_address_taken{ false };

	while (parc_created == false)
	{
		do
		{
			if (name.empty())
			{
				cout << "Parc Name: ";
				cin >> name;
			}
			for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
			{
				if (vp->getParcs()[i]->getName() == name)
				{
					cout << "Parc Name is already in use, please try another one." << endl;
					name.clear(); // to empty the string
					parc_name_taken = true;
				}
				else
				{
					parc_name_taken = false;
				}
			}
		} while (parc_name_taken);

		do
		{
			if (address.empty())
			{
				cout << "Parc Address: ";
				cin >> address;
			}
			for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
			{
				if (vp->getParcs()[i]->getAddress() == address)
				{
					cout << "Parc Address is already in use, please try another one." << endl;
					address.clear();
					parc_address_taken = true;
				}
				else
				{
					parc_address_taken = false;
				}
			}
		} while (parc_address_taken);

		if (parc_name_taken == false && parc_address_taken == false) {
			parc_created = true;
		}
	}
	ParcServices* p = createParcServices();
	vp->setParc(new Parcs(name, address, p));
}

void showParcs(VacationParcs* vp)
{
	cout << "Parcs included in the system of VacationParcs::getName() ->> " << vp->getName() << endl;
	for (size_t i{ 0 }; i < vp->getParcs().size(); i++)
	{
		cout << vp->getParcs()[i]->toString() << endl;
	}
}

void changeParc(VacationParcs* vp)
{
	string parc_name;
	int parc_index;
	bool parc_found{ false };
	int service_num;

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

	do
	{
		cout << "Enter the name of the park to see Services available: ";
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


	selected_parc = vp->getParcs()[parc_index];
	selected_services = selected_parc->getParcServices();

	subtropic_swimming_pool_val = selected_services->getSubtropicSwimmingPool();
	sports_infrastructure_val = selected_services->getSportsInfrastructure();
	bowling_alley_val = selected_services->getBowlingAlley();
	bicycle_rent_val = selected_services->getBicycleRent();
	childrens_paradise_val = selected_services->getChildrensParadise();
	water_bikes_val = selected_services->getWaterBikes();


	cout << "ParcServices::toString() ->> " << endl;
	cout << selected_parc->toString() << endl;


	do
	{
		cout << "Enter the number for the service you would like to add or remove: ";
		cin >> service_num;

		switch (service_num)
		{
		case 1:
			cout
				<< subtropic_swimming_pool_name
				<< " has change from \""
				<< boolalpha << subtropic_swimming_pool_val
				<< "\" to \"" << !subtropic_swimming_pool_val
				<< "\"."
				<< endl;
			selected_services->setSubtropicSwimmingPool(!subtropic_swimming_pool_val);
			break;
		case 2:
			cout
				<< sports_infrastructure_name
				<< " has change from \""
				<< boolalpha << sports_infrastructure_val
				<< "\" to \"" << !sports_infrastructure_val
				<< "\"."
				<< endl;
			selected_services->setSportsInfrastructure(!sports_infrastructure_val);
			break;
		case 3:
			cout
				<< bowling_alley_name
				<< " has change from \""
				<< boolalpha << bowling_alley_val
				<< "\" to \"" << !bowling_alley_val
				<< "\"."
				<< endl;
			selected_services->setBowlingAlley(!bowling_alley_val);
			break;
		case 4:
			cout
				<< bicycle_rent_name
				<< " has change from \""
				<< boolalpha << bicycle_rent_val
				<< "\" to \"" << !bicycle_rent_val
				<< "\"."
				<< endl;
			selected_services->setBicycleRent(!bicycle_rent_val);
			break;
		case 5:
			cout
				<< childrens_paradise_name
				<< " has change from \""
				<< boolalpha << childrens_paradise_val
				<< "\" to \"" << !childrens_paradise_val
				<< "\"."
				<< endl;
			selected_services->setChildrensParadise(!childrens_paradise_val);
			break;
		case 6:
			cout
				<< water_bikes_name
				<< " has change from \""
				<< boolalpha << water_bikes_val
				<< "\" to \"" << !water_bikes_val
				<< "\"."
				<< endl;
			selected_services->setWaterBikes(!water_bikes_val);
			break;
		default:
			cout << "Invalid input, try again." << endl;
			break;
		}
	} while (service_num < 1 || service_num > 6);

}

void deleteParc(VacationParcs* vp)
{
	string parc_name;
	int parc_index;
	bool parc_found{ false };
	char delete_parc;

	do
	{
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


	cout << "Here is the information for the parc to be deleted: " << endl;
	cout << vp->getParcs()[parc_index]->toString() << endl;

	do
	{
		cout << "If you are sure to delete it enter \"y\", else enter \"n\".: ";
		cin >> delete_parc;

		if (!(delete_parc == 'y' || delete_parc == 'n'))
		{
			cout << "Invalid input, please try again." << endl;
		}
	} while (!(delete_parc == 'y' || delete_parc == 'n'));

	if (delete_parc == 'y')
	{
		cout << vp->getParcs()[parc_index]->getName() << " IS deleted." << endl;
		delete vp->getParcs()[parc_index];
		vp->getParcs().erase(vp->getParcs().begin() + parc_index);
	}
	else
	{
		cout << vp->getParcs()[parc_index]->getName() << " IS NOT deleted." << endl;
	}


}