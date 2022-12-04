#include "useCaseLibrary.h"
#include "_ParcController.h"
#include "_CustomerController.h"
#include "_AccomodationController.h"
#include "_BookingController.h"
int main()
{

	VacationParcs* vp = new VacationParcs("MainObject", "Sint Katelijne Waver", "VAT info here.");
	vp->setCustomer(new Customer("inanc", "hertog", "inanc@gmail"));
	vp->setCustomer(new Customer("alp", "heverlee", "inanc@alp"));
	ParcServices* ps1 = new ParcServices(1, 1, 1, 1, 1, 1);
	ParcServices* ps2 = new ParcServices(1, 1, 1, 1, 1, 1);
	Parcs* p1 = new Parcs("park1", "park-address1", ps1);
	Parcs* p2 = new Parcs("park2", "park-address2", ps2);
	LuxuryLevel* lux_vip = new LuxuryLevel(true, true, true, true, "VIP");
	LuxuryLevel* lux_prem = new LuxuryLevel(false, false, true, true, "Premium");
	LuxuryLevel* lux_comfort = new LuxuryLevel(false, false, false, true, "Comfort");
	Accomodations* a1 = new HotelRoom(1, 5, 35, false, false, lux_comfort, 20, "Next to Ocean", 3, 1);
	Accomodations* a2 = new Bungalow(2, 2, 30, true, false, lux_vip, 1);
	Accomodations* a3 = new Bungalow(3, 2, 30, true, false, lux_prem, 1);
	Accomodations* a4 = new Bungalow(4, 2, 30, true, false, lux_comfort, 1);
	Accomodations* a5 = new HotelRoom(5, 5, 35, false, false, lux_vip, 20, "Next to Downtown", 3, 1);
	Accomodations* a6 = new HotelRoom(6, 5, 35, false, false, lux_comfort, 20, "Next to market", 3, 1);
	Accomodations* a7 = new HotelRoom(7, 5, 35, false, false, lux_comfort, 20, "Next to hood", 3, 1);
	Accomodations* a8 = new HotelRoom(8, 5, 35, false, false, lux_comfort, 20, "Next to parc", 3, 1);
	p1->setAccomodation(a1);
	p1->setAccomodation(a2);
	p2->setAccomodation(a3);
	p2->setAccomodation(a4);
	p2->setAccomodation(a5);
	p2->setAccomodation(a6);
	p2->setAccomodation(a7);
	p2->setAccomodation(a8);
	vp->setLuxuryLevel(lux_vip);
	vp->setLuxuryLevel(lux_prem);
	vp->setLuxuryLevel(lux_comfort);
	vp->setParc(p1);
	vp->setParc(p2);

	bool quit{ false };
	int user_type;

	cout << "|---------------------------------|" << endl;
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


	return 0;
}