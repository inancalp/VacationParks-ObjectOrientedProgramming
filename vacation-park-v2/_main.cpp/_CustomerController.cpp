#include "_CustomerController.h"
#include "_AccomodationController.h"
#include "_BookingController.h"
#include "__MainController.h"

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





void createCustomer(VacationParcs* vp)
{
	string customer_name;
	string customer_address;
	string customer_email;
	Customer* c;
	bool customer_email_taken;


	customer_name.clear();
	customer_address.clear();
	customer_email.clear();
	customer_email_taken = false;

	cout << "Customer Name: ";
	cin >> customer_name;
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

	cout << "Customer Address: ";
	cin >> customer_address;
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

	do
	{
		if (customer_email.empty())
		{
			cout << "Customer Email: ";
			cin >> customer_email;
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
	cout << endl;
	cout << "---------------------------------------------------------------- " << endl;
	cout << "Customers included in the system of VacationParcs::getName() ->> " << vp->getName() << endl;
	cout << "---------------------------------------------------------------- " << endl;
	for (size_t i{ 0 }; i < vp->getCustomers().size(); i++)
	{
		cout << " ->>";
		cout << vp->getCustomers()[i]->toString() << endl << endl;
	}
}

void deleteCustomer(VacationParcs* vp)
{
	string customer_email;
	int customer_index;
	bool customer_found;
	char delete_customer;

	customer_email.clear();
	customer_index = -1;
	customer_found = false;
	delete_customer = '\0';

	do
	{
		cout << "Enter the Email of the Customer to that needs to be deleted: ";
		cin >> customer_email;
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
	
	cout << endl;
	cout << "Here is the information for the Customer to be deleted: " << endl;
	cout << vp->getCustomers()[customer_index]->toString() << endl;

	do
	{	
		cout << "-----------------------------------------------------------------" << endl;
		cout << "(!) All the bookings releated with customer will also be deleted." << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "If you are sure to delete the customer enter \"y\": ";
		cin >> delete_customer;
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
		if (!(delete_customer == 'y'))
		{
			cout << "Invalid input, please try again." << endl;
		}
	} while (!(delete_customer == 'y'));

	if (delete_customer == 'y')
	{
		for (size_t i{ 0 }; i < vp->getBookings().size(); i++)
		{
			if (vp->getCustomers()[customer_index]->getEmail() == vp->getBookings()[i]->getCustomer()->getEmail())
			{
				for (size_t j{ 0 }; j < vp->getBookings()[i]->getAccomodations().size(); j++)
				{
					vp->getBookings()[i]->getAccomodations()[j]->setIsBooked(false);
				}
				delete vp->getBookings()[i];
				vp->getBookings().erase(vp->getBookings().begin() + i);
				i--;
			}
		}

		cout << vp->getCustomers()[customer_index]->getEmail() << " IS deleted." << endl;
		delete vp->getCustomers()[customer_index];
		vp->getCustomers().erase(vp->getCustomers().begin() + customer_index);
	}

	reWriteCustomersFile(vp);
	reWriteAccomodationsFile(vp);
	reWriteBookingsFile(vp);

}

void ModifyCustomer(VacationParcs* vp, Customer* c)
{
	int selected_option;
	string customer_name;
	string customer_address;
	string customer_email;

	customer_name.clear();
	customer_address.clear();
	customer_email.clear();
	selected_option = NULL;

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
			cout << "Enter your new name: ";
			cin >> customer_name;
			if (cin.eof())
			{
				cin.clear();
				continue;
			}
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			c->setName(customer_name);
			break;
		case 2:
			cout << "Enter your new address: ";
			cin >> customer_address;
			if (cin.eof())
			{
				cin.clear();
				continue;
			}
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			c->setAddress(customer_address);
			break;
		case 3:
			customer_email = ModifyCustomerEmail(vp, c);
			if (cin.eof())
			{
				cin.clear();
				continue;
			}
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			c->setEmail(customer_email); //see below
			break;
		default:
			cout << "Invalid input." << endl;
			break;
		}
		reWriteCustomersFile(vp);
		reWriteBookingsFile(vp);
	} while (true);
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
			if (cin.eof())
			{
				return "\0";
			}
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
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





