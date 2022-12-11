#include "_CustomerController.h"
#include "_AccomodationController.h"
#include "_BookingController.h"


void saveCustomerFile(Customer* c)
{
	ofstream customersFile(CUSTOMERSFILE, ios::out | ios::app);
	if (!customersFile)
	{
		cout << "Error occured while opening customers.txt file" << endl;
		return;
	}

	cout << "saveCustomerFile() ->> Customer::getEmail() ->> " << c->getEmail() << " being saved." << endl;

	customersFile
		<< c->getName() << " "
		<< c->getAddress() << " "
		<< c->getEmail() << endl;

	customersFile.close();
}

void retrieveCustomersFile(VacationParcs* vp)
{
	string customer_name;
	string customer_address;
	string customer_email;
	Customer* c;

	ifstream customersFile(CUSTOMERSFILE, ios::in);
	if (!customersFile)
	{
		cout << "Error opening the file \"customers.txt\"." << endl;
	}

	while (customersFile >> customer_name >> customer_address >> customer_email)
	{
		c = new Customer(customer_name, customer_address, customer_email);
		vp->setCustomer(c);
		//cout << "retrieveCustomersFile() ->> Customer::getEmail() ->> " << c->getEmail() << " is retrieved." << endl;
	}

	customersFile.close();
}

void reWriteCustomersFile(VacationParcs* vp)
{
	ofstream customersFile(CUSTOMERSFILE, ios::out);
	if (!customersFile)
	{
		cout << "Error opening the file \"customers.txt\"." << endl;
		return;
	}

	for (Customer* customer : vp->getCustomers())
	{
		customersFile
			<< customer->getName() << " "
			<< customer->getAddress() << " "
			<< customer->getEmail() << endl;
	}

	customersFile.close();
}



void CustomerSession(VacationParcs* vp, Customer* c)
{
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
		cout << "  4) Modify Existing Booking         " << endl;
		cout << "  5) Exit                            " << endl;
		cout << "                                     " << endl;
		cout << "_____________________________________" << endl;

		cout << endl;
		cout << "Select Option: ";
		cin >> selected_option; //


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
			cout << "COMING SOON." << endl;
			break;
		case 5:
			quit = true;
			break;
		default:

			break;
		}

	} while (!quit);
}

void createCustomer(VacationParcs* vp)
{
	string customer_name;
	string customer_address;
	string customer_email;
	Customer* c;
	bool customer_email_taken{ false };

	cout << "Customer Name: ";
	cin >> customer_name;

	if (customer_name == "exit")
	{
		return;
	}

	cout << "Customer Address: ";
	cin >> customer_address;

	if (customer_address == "exit")
	{
		return;
	}

	do
	{
		if (customer_email.empty())
		{
			cout << "Customer Email: ";
			cin >> customer_email;
		}

		if (customer_email == "exit")
		{
			return;
		}

		for (size_t i{ 0 }; i < vp->getCustomers().size(); i++)
		{
			if (vp->getCustomers()[i]->getEmail() == customer_email)
			{
				cout << "This email is already in use, please try another one." << endl;
				customer_email.clear();
				customer_email_taken = true;
				break;
			}
			else
			{
				customer_email_taken = false;
			}
		}
	} while (customer_email_taken);
	c = new Customer(customer_name, customer_address, customer_email);
	vp->setCustomer(c);
	saveCustomerFile(c);
	cout << "End of createCustomer()" << endl;
	CustomerSession(vp, c);
}

void showCustomers(VacationParcs* vp)
{
	cout << "Customers included in the system of VacationParcs::getName() ->> " << vp->getName() << endl;
	for (size_t i{ 0 }; i < vp->getCustomers().size(); i++)
	{
		cout << vp->getCustomers()[i]->toString() << endl;
	}
}


//update later
	//if customer has booking, delete is not possible.
void deleteCustomer(VacationParcs* vp)
{
	string customer_email;
	int customer_index;
	bool customer_found{ false };
	char delete_customer;

	do
	{
		cout << "Enter the Email of the Customer to that needs to be deleted: ";
		cin >> customer_email;
		for (int i{ 0 }; i < vp->getCustomers().size(); i++)
		{
			if (vp->getCustomers()[i]->getEmail() == customer_email)
			{
				customer_index = i; //(!)
				customer_found = true;
			}
		}
		if (!customer_found)
		{
			cout << "Customer can't be found on the system. Try again." << endl;
		}
	} while (!customer_found);

	cout << "Here is the information for the Customer to be deleted: " << endl;
	cout << vp->getCustomers()[customer_index]->toString() << endl;

	do
	{
		cout << "If you are sure to delete the customer enter \"y\", else enter \"n\".: ";
		cin >> delete_customer;

		if (!(delete_customer == 'y' || delete_customer == 'n'))
		{
			cout << "Invalid input, please try again." << endl;
		}
	} while (!(delete_customer == 'y' || delete_customer == 'n'));

	if (delete_customer == 'y')
	{
		cout << vp->getCustomers()[customer_index]->getEmail() << " IS deleted." << endl;
		delete vp->getCustomers()[customer_index];
		vp->getCustomers().erase(vp->getCustomers().begin() + customer_index);
	}
	else
	{
		cout << vp->getCustomers()[customer_index]->getEmail() << " IS NOT deleted." << endl;
	}
}

void ModifyCustomer(VacationParcs* vp, Customer* c)
{
	bool quit{ false };
	int selected_option;
	string customer_name;
	string customer_address;
	string customer_email;

	do
	{
		cout << "_____________________________________" << endl;
		cout << "                                     " << endl;
		cout << "   Modify Customer:                  " << endl;
		cout << "                                     " << endl;
		cout << "  -Name: " << c->getName() << endl;
		cout << "  -Address: " << c->getAddress() << endl;
		cout << "  -Email: " << c->getEmail() << endl;
		cout << "                                     " << endl;
		cout << "  1) Change Name                     " << endl;
		cout << "  2) Change Address                  " << endl;
		cout << "  3) Change Email                    " << endl;
		cout << "  4) Exit                            " << endl;
		cout << "                                     " << endl;
		cout << "_____________________________________" << endl;

		cout << endl;
		cout << "Select Option: ";
		cin >> selected_option;

		switch (selected_option)
		{
		case 1:
			cout << "Enter your new name: ";
			cin >> customer_name;
			if (customer_name == "exit")
			{
				continue;
			}
			c->setName(customer_name);
			break;
		case 2:
			cout << "Enter your new address: ";
			cin >> customer_address;
			if (customer_address == "exit")
			{
				continue;
			}
			c->setAddress(customer_address);
			break;
		case 3:
			customer_email = ModifyCustomerEmail(vp, c);
			if (customer_email == "exit")
			{
				continue;
			}
			c->setEmail(customer_email); //see below
			break;
		case 4:
			quit = true;
			break;
		default:
			cout << "Invalid option, please try again." << endl;
			break;
		}
	} while (!quit);

	reWriteCustomersFile(vp);
}

string ModifyCustomerEmail(VacationParcs* vp, Customer* c)
{

	string customer_email;
	bool email_is_different;
	bool email_is_taken{ false };
	do
	{
		do
		{
			cout << "Enter your new email address: ";
			cin >> customer_email;
			if (customer_email == "exit")
			{
				cout << "No change has been done to Email." << endl;
				return "exit";
			}

			if (customer_email == c->getEmail())
			{
				cout << "Please enter any other email different than your current email. Try again." << endl;
				email_is_different = false;
			}
			else
			{
				email_is_different = true;
			}

		} while (!email_is_different);


		for (size_t i{ 0 }; i < vp->getCustomers().size(); i++)
		{
			if (vp->getCustomers()[i]->getEmail() == customer_email)
			{
				cout << "Email is already taken! Try again." << endl;
				email_is_taken = true;
				break; //out of the for loop.
			}
			else
			{
				email_is_taken = false;
			}
		}

	} while (email_is_taken);

	return customer_email;

}



