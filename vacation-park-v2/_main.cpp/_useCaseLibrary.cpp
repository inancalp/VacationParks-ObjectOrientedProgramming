#include "_useCaseLibrary.h"



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
		cout << "     9) Show Bookings             " << endl;
		cout << "    10) Exit                      " << endl;
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
			showAccomodations(vp);
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
			showBookings(vp);
		case 10:
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
	bool quit{ false };
	int selected_option;
	string customer_email;
	Customer* customer;
	int customer_index;
	bool customer_found{ false };

	do
	{
		cout << "__________________________________" << endl;
		cout << "   CustomerType Functionalities:  " << endl;
		cout << "__________________________________" << endl;
		cout << "                                  " << endl;
		cout << "     1) Sign-in                   " << endl;
		cout << "     2) Sign-up                   " << endl;
		cout << "     3) Exit                      " << endl;
		cout << "                                  " << endl;
		cout << "__________________________________" << endl;

		cin >> selected_option;

		switch (selected_option)
		{
		case 1:
			do
			{
				cout << "Enter Customer Account Email to Login: ";
				cin >> customer_email;

				for (size_t i{ 0 }; i < vp->getCustomers().size(); i++)
				{
					if (vp->getCustomers()[i]->getEmail() == customer_email)
					{
						customer_index = static_cast<int>(i);
						customer_found = true;
					}
				}
				if (!customer_found)
				{
					cout << "Customer can't be found in the system, please try again." << endl;
				}
			} while (!customer_found);

			customer = vp->getCustomers()[customer_index];
			CustomerSession(vp, customer);
			break;

		case 2:
			createCustomer(vp);
			break;
		case 3:
			quit = true;
			break;
		default:
			cout << "Invalid input, please try again." << endl;
			break;
		}
	} while (!quit);


}	
void CustomerSession(VacationParcs* vp, Customer* c)
{
	bool quit{ false };
	int selected_option;
	do
	{
		cout << endl << endl;
		cout << "_____________________________________" << endl;
		cout << "_____________________________________" << endl;
		cout << "   Current Customer:                 " << endl;
		cout << "                                     " << endl;
		cout << "  -Name: " << c->getName()             << endl;
		cout << "  -Email: " << c->getEmail()           << endl;
		cout << "_____________________________________" << endl;
		cout << "_____________________________________" << endl;
		cout << "                                     " << endl;
		cout << "  1) Modify Customer's Informations  " << endl;
		cout << "  2) Show Available Accomodations    " << endl;
		cout << "  3) Make a Booking                  " << endl;
		cout << "  4) Modify Existing Booking         " << endl;
		cout << "  5) Exit                            " << endl;
		cout << "                                     " << endl;
		cout << "_____________________________________" << endl;

		cin >> selected_option; //


		switch (selected_option)
		{
		case 1:
			ModifyCustomer(vp, c);
			break;
		case 2:
			showAccomodations(vp);
			break;
		case 3:
			CreateBooking(vp, c);
			break;
		case 4:

			break;
		case 5:
			quit = true;
			break;
		default:

			break;
		}

	} while (!quit);
}






