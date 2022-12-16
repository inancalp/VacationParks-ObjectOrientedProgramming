#include "__MainController.h"
#include "_ParcController.h"
#include "_CustomerController.h"
#include "_AccomodationController.h"
#include "_BookingController.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int user_type;
	VacationParcs* vp = new VacationParcs("MainObject", "Sint Katelijne Waver", "VAT info here.");
	// luxuryLevel(bbq, surround_system, breakfast_service, cleaning_service, luxury_type)
 	vp->setLuxuryLevel(new LuxuryLevel(true, true, true, true, "vip"));
	vp->setLuxuryLevel(new LuxuryLevel(false, false, true, true, "premium"));
	vp->setLuxuryLevel(new LuxuryLevel(false, false, false, true, "comfort"));
	retrieveParcsFile(vp);
	retrieveAccomodationsFile(vp);
	retrieveCustomersFile(vp);
	retrieveBookingsFile(vp);

	cout 
		<< endl << endl
		<< "\t\t--------------------------------- " << endl
		<< "\t\tWelcome to VacationParcs Project! " << endl
		<< "\t\t_________________________________ " << endl << endl
		<< "CLI based Object Oriented Programming application with C++ " << endl << endl
		<< "(!) ForYourInformation: " << endl 
		<< "\t - User can enter \"Ctrl+Z\" to cancel any process or exit the program when in UserType Menu. " << endl
		<< "\t - Error Handling is not in it's best state, so please do mind not to put any information rather than requested. " << endl
		<< "\t - Program flow works with only \"std::cin\" to have user input. " << endl
		<< "\t\t - In case of UserName, ParkName (and so on...), please create the spaces with snake_case or camelCase etc. " << endl << endl;

	do
	{

		cout << "________________________" << endl;
		cout << "   Select UserType:     " << endl;
		cout << "________________________" << endl;
		cout << "                        " << endl;
		cout << "     1) Owner           " << endl;
		cout << "     2) Employee        " << endl;
		cout << "     3) Customer        " << endl;
		cout << "                        " << endl;
		cout << "________________________" << endl;
		cout << endl;

		cout << "Select Option: ";
		cin >> user_type;

		if (cin.eof())
		{
			cin.clear();
			delete vp;
			cout << "-----------------------------------------------" << endl;
			cout << "Thanks for using the system. See you next time!" << endl;
			cout << "-----------------------------------------------" << endl;
			return 0;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}


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
		default:
			cout << "Invalid input." << endl;
			break;
		}

	} while (true);

	cout << "-----------------------------------------------" << endl;
	cout << "Thanks for using the system. See you next time!" << endl;
	cout << "-----------------------------------------------" << endl;

	delete vp;
	return 0;
}