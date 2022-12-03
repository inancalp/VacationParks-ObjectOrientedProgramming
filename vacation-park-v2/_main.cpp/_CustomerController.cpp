#include "_CustomerController.h"

void createCustomer(VacationParcs* vp)
{
	string customer_name;
	string customer_address;
	string customer_email;

	bool customer_email_taken{ false };

	cout << "Customer Name: ";
	cin >> customer_name;

	cout << "Customer Address: ";
	cin >> customer_address;

	do
	{
		if (customer_email.empty())
		{
			cout << "Customer Email: ";
			cin >> customer_email;
		}
		for (size_t i{ 0 }; i < vp->getCustomers().size(); i++)
		{
			if (vp->getCustomers()[i]->getEmail() == customer_email)
			{
				cout << "This email is already in use, please try another one." << endl;
				customer_email.clear();
				customer_email_taken = true;
			}
			else
			{
				customer_email_taken = false;
			}
		}
	} while (customer_email_taken);
	vp->setCustomer(new Customer(customer_name, customer_address, customer_email));
	cout << "End of createCustomer()" << endl;
}

void showCustomers(VacationParcs* vp)
{
	cout << "Customers included in the system of VacationParcs::getName() ->> " << vp->getName() << endl;
	for (size_t i{ 0 }; i < vp->getCustomers().size(); i++)
	{
		cout << vp->getCustomers()[i]->toString() << endl;
	}
}

// later
void changeCustomer(VacationParcs* vp)
{
	cout << "Hello";
}

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
