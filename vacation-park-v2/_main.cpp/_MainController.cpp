#include "_MainController.h"



void OwnerType(VacationParcs* vp)
{
	bool quit{ false };
	int selected_option;

	do
	{
		cout << "__________________________________" << endl;
		cout << "   OwnerType Functionalities:     " << endl;
		cout << "__________________________________" << endl;
		cout << "                                  " << endl;
		cout << "     1) Show Parcs                " << endl;
		cout << "     2) Create Parc               " << endl;
		cout << "     3) Modify Parc               " << endl;
		cout << "     4) Delete Parc               " << endl;
		cout << "     5) Show Accomodations        " << endl;
		cout << "     6) Create Accomodation       " << endl;
		cout << "     7) Modify Accomodation       " << endl;
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
			modifyParc(vp);
			break;
		case 4:
			deleteParc(vp);
			break;
		case 5:
			showAccomodations(vp);
			break;
		case 6:
			createAccomodation(vp);
			break;
		case 7:
			modifyAccomodation(vp);
			break;
		case 8:
			deleteAccomodation(vp);
			break;
		case 9:
			//loop thru every booking.
			cout << "COMING SOON." << endl;
			//showBookings(vp);
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

		cout << endl;
		cout << "Select Option: ";
		cin >> selected_option;

		switch (selected_option)
		{
		case 1:
			do
			{
				cout << "Enter Customer Account Email to Login: ";
				cin >> customer_email;
				if (customer_email == "exit")
				{
					return;
				}

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







