#include "useCaseLibrary.h"
#include "_ParcController.h"
#include "_CustomerController.h"
#include "_AccomodationController.h"

int main()
{

	VacationParcs* vp = new VacationParcs("MainObject", "Sint Katelijne Waver", "VAT info here.");

	bool quit{ false };
	int user_type;
	cout << "|_________________________________|" << endl;
	cout << "|Welcome to VacationParcs Project!|" << endl;
	cout << "|_________________________________|" << endl;


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
	cout << "Thanks for using our system. See you next time!" << endl;
	cout << "-----------------------------------------------" << endl;

	delete vp;


	//createParc(vp);
	//showParcs(vp);
	//createAccomodation(vp->getParcs()[0]);
	//showAccomodations(vp->getParcs()[0]);
	//createAccomodation(vp->getParcs()[0]);
	//showAccomodations(vp->getParcs()[0]);
	
	//createCustomer(vp);
	//createCustomer(vp);
	//showCustomers(vp);
	//deleteCustomer(vp);
	//showCustomers(vp);
	//delete vp;

	//LuxuryLevel* lux_vip = new LuxuryLevel(true, true, true, true, "VIP");
	//LuxuryLevel* lux_prem = new LuxuryLevel(false, false, true, true, "Premium");
	//LuxuryLevel* lux_comfort = new LuxuryLevel(false, false, false, true, "Comfort");
	//Accomodations* a1 = new HotelRoom(1, 5, 35, false, lux_comfort, 20, "Next to Ocean", 3, 1);
	//Accomodations* a2 = new Bungalow(2, 2, 30, true, lux_vip, 1);
	//cout << a1->toString() << endl;
	//cout << a2->toString() << endl;
	//delete lux_vip;
	//delete lux_prem;
	//delete lux_comfort;
	//delete a1;
	//delete a2;

	return 0;
}