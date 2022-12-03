#include "useCaseLibrary.h"



void createBooking(Customer* customer)
{
	static int id = 0;  // should change
	bool activityPass;
	bool sportsPass;
	bool bicycleRent;
	bool swimmingPass;

	cout << "\t\t\t\t|----------------------------------------------|\n";
	cout << "\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t|   There is a couple services we recommend!   |\n";
	cout << "\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t|   - Activity Pass                            |\n";
	cout << "\t\t\t\t|   - Sports Pass                              |\n";
	cout << "\t\t\t\t|   - Bicycle Rent                             |\n";
	cout << "\t\t\t\t|   - Swimming Pass                            |\n";
	cout << "\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t|	  If you want to include any                |\n";
	cout << "\t\t\t\t|          press <1> for each.                 |\n";
	cout << "\t\t\t\t|    Else, press <0>.                          |\n";
	cout << "\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t|----------------------------------------------|\n";


	// make it secure
	cout << "\n\t\t\t\tActivity Pass: ";
	cin >> activityPass;
	cout << "\n\t\t\t\tSport Pass: ";
	cin >> sportsPass;
	cout << "\n\t\t\t\tBicycle Rent: ";
	cin >> bicycleRent;
	cout << "\n\t\t\t\tSwimming Pass: ";
	cin >> swimmingPass;
	cout << endl;

	//customer->setBooking(new Booking(++id, activityPass, sportsPass, bicycleRent, swimmingPass));

}

void OwnerType(VacationParcs* vp)
{
	bool quit{ false };
	int selected_option;
	Parcs* p;
	do
	{
		cout << "__________________________________" << endl;
		cout << "   OwnerType Functionalities:     " << endl;
		cout << "__________________________________" << endl;
		cout << "                                  " << endl;
		cout << "     1) Show Parcs                " << endl;
		cout << "     2) Create Parc               " << endl;
		cout << "     3) Change Parc               " << endl;
		cout << "     4) Delete Parc               " << endl;
		cout << "     5) Show Accomodations        " << endl;
		cout << "     6) Create Accomodation       " << endl;
		cout << "     7) Change Accomodation       " << endl;
		cout << "     8) Delete Accomodation       " << endl;
		cout << "     9) Exit                      " << endl;
		cout << "                                  " << endl;
		cout << "__________________________________" << endl;
		cout << endl;
		cout << "Select Option: ";
		cin >> selected_option;
		cout << endl;
		cout << endl;
		switch (selected_option)
		{
		case 1:
			showParcs(vp);
			break;
		case 2:
			createParc(vp);
			break;
		case 3:
			changeParc(vp);
			break;
		case 4:
			deleteParc(vp);
			break;
		case 5:
			p = selectParc(vp);
			showAccomodations(p);
			break;
		case 6:
			p = selectParc(vp);
			createAccomodation(p);
			break;
		case 7:
			cout << "changeAccomodation() FEATURE (COMING SOON..)" << endl;
			break;
		case 8:
			cout << "deleteAccomodation() FEATURE (COMING SOON..)" << endl;
			break;
		case 9:
			quit = true;
			break;
		default:
			cout << "Invalid input, please try again later." << endl;
			break;
		}
	} while (!quit);



}







void EmployeeType(VacationParcs* vp)
{

}

void CustomerType(VacationParcs* vp)
{

}