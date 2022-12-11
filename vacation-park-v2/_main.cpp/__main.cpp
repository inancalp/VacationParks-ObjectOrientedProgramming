#include "_MainController.h"
#include "_ParcController.h"
#include "_CustomerController.h"
#include "_AccomodationController.h"
#include "_BookingController.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{

	VacationParcs* vp = new VacationParcs("MainObject", "Sint Katelijne Waver", "VAT info here.");
	
	// luxuryLevel(bbq, surround_system, breakfast_service, cleaning_service, luxury_type)
 	vp->setLuxuryLevel(new LuxuryLevel(true, true, true, true, "vip"));
	vp->setLuxuryLevel(new LuxuryLevel(false, false, true, true, "premium"));
	vp->setLuxuryLevel(new LuxuryLevel(false, false, false, true, "comfort"));

	retrieveParcsFile(vp);
	retrieveAccomodationsFile(vp);
	retrieveCustomersFile(vp);
	retrieveBookingsFile(vp);

	

	bool quit{ false };
	int user_type;

	cout << endl << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\tWelcome to VacationParcs Project!" << endl;
	cout << "\t\t_________________________________" << endl;
	cout << endl << endl;
	cout << "CLI based Object Oriented Programming application with C++" << endl;
	cout << " - ForYourInformation:" << endl;
	cout << "\t - Unless information displayed, user can enter \"exit\" (all lower letters) to cancel any function." << endl;
	cout << "\t - Error Handling is not in it's best state, so please do mind not to put any information rather than requested." << endl;
	cout << "\t - Program flow works with only \"std::cin\" to have user input." << endl;
	cout << "\t\t - In case of UserName, ParkName (and so on...), please create the spaces with snake_case or camelCase etc." << endl;
	do
	{

		cout << "________________________" << endl;
		cout << "   Select UserType:     " << endl;
		cout << "________________________" << endl;
		cout << "                        " << endl;
		cout << "     1) Owner           " << endl;
		cout << "     2) Employee        " << endl;
		cout << "     3) Customer        " << endl;
		cout << "     4) Exit            " << endl;
		cout << "                        " << endl;
		cout << "________________________" << endl;
		cout << endl;
		cout << "Select Option: ";
		cin >> user_type;

		switch (user_type)
		{
		case 1:
			OwnerType(vp);
			break;
		case 2:
			EmployeeType(vp);
			break;
		case 3:
			CustomerType(vp);
			break;
		case 4:
			quit = true;
			break;
		default:
			cout << "Invalid input, please try again." << endl;
			break;
		}

	} while (!quit);

	cout << "-----------------------------------------------" << endl;
	cout << "Thanks for using the system. See you next time!" << endl;
	cout << "-----------------------------------------------" << endl;


	delete vp;

	return 0;
}