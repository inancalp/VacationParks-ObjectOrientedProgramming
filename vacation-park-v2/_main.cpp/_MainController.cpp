#include "_MainController.h"

void OwnerType(VacationParcs* vp)
{
	int selected_option;
	selected_option = -1;

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
		cout << "                                  " << endl;
		cout << "__________________________________" << endl;
		cout << endl;

		cout << "Select Option: ";
		cin >> selected_option;
		if (cin.eof())
		{
			cin.clear();
			return;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

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
			showBookings(vp);
			break;
		default:
			cout << "Invalid input." << endl;
			break;
		}
	} while (true);
}
void EmployeeType(VacationParcs* vp)
{
	int selected_option;
	selected_option = -1;
	string customer_email;
	bool customer_not_found;
	Customer* c = NULL;

	do
	{
		cout << "__________________________________" << endl;
		cout << "  EmployeeType Functionalities:   " << endl;
		cout << "__________________________________" << endl;
		cout << "                                  " << endl;
		cout << "    1) Show Parcs                 " << endl;
		cout << "    2) Show Accomodations         " << endl;
		cout << "    3) Show Customers             " << endl;
		cout << "    4) Show Bookings              " << endl;
		cout << "    5) Delete Customer's Bookings " << endl;
		cout << "    6) Delete Customer            " << endl;
		cout << "                                  " << endl;
		cout << "__________________________________" << endl;
		cout << endl;

		cout << "Select Option: ";
		cin >> selected_option;
		if (cin.eof())
		{
			cin.clear();
			return;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (selected_option)
		{
		case 1:
			showParcs(vp);
			break;
		case 2:
			showAccomodations(vp);
			break;
		case 3:
			showCustomers(vp);
			break;
		case 4:
			showBookings(vp);
			break;
		case 5:
			deleteBookings(vp);
			break;
		case 6:
			deleteCustomer(vp);
			break;
		default:
			cout << "Invalid input." << endl;
			break;
		}
	} while (true);
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
		cout << "                                  " << endl;
		cout << "__________________________________" << endl;

		cout << endl;
		cout << "Select Option: ";
		cin >> selected_option;
		if (cin.eof())
		{
			cin.clear();
			return;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (selected_option)
		{
		case 1:
			do
			{
				customer_email.clear();
				customer_found = false;
				customer_index = -1;

				cout << "Enter Customer Account Email to Login: ";
				cin >> customer_email;

				//breaks out of loop and checks state of cin.eof() again below
				if (cin.eof())
				{
					break;
				}
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

			//cin.eof() state check
			if (cin.eof())
			{
				cin.clear();
				continue;
			}

			customer = vp->getCustomers()[customer_index];
			CustomerSession(vp, customer);

			break;
		case 2:
			createCustomer(vp);
			break;
		default:
			cout << "Invalid input." << endl;
			break;
		}
	} while (true);
}	
void CustomerSession(VacationParcs* vp, Customer* c)
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool quit{ false };
	int selected_option;
	do
	{
		cout << "_____________________________________" << endl;
		cout << "                                     " << endl;
		cout << "   Current Customer:                 " << endl;
		cout << "                                     " << endl;
		cout << "  -Name: " << c->getName() << endl;
		cout << "  -Address: " << c->getAddress() << endl;
		cout << "  -Email: " << c->getEmail() << endl;
		cout << "                                     " << endl;
		cout << "  1) Modify Customer's Informations  " << endl;
		cout << "  2) Show Customer's Bookings        " << endl;
		cout << "  3) Make a Booking                  " << endl;
		cout << "  4) Modify Customer's Bookings      " << endl;
		cout << "                                     " << endl;
		cout << "_____________________________________" << endl;
		cout << endl;

		cout << "Select Option: ";
		cin >> selected_option;
		if (cin.eof())
		{
			cin.clear();
			return;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (selected_option)
		{
		case 1:
			ModifyCustomer(vp, c);
			break;
		case 2:
			showCustomersBookings(vp, c);
			break;
		case 3:
			CreateBooking(vp, c);
			break;
		case 4:
			modifyBookings(vp, c);
			break;
		default:
			cout << "Invalid input." << endl;
			break;
		}
	} while (true);
}






