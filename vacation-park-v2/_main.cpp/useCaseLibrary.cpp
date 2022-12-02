#include "useCaseLibrary.h"

void createCustomer(VacationParcs* vp)
{
	string name;
	string address;
	string email;

	bool customer_created{ false };
	bool email_is_taken{ false };

	cout << "Name: ";
	cin >> name;
	cout << "Address: ";
	cin >> address;

	while (customer_created == false) {

		cout << "Email: ";
		cin >> email;

		for (size_t i{ 0 }; i < vp->getCustomers().size(); i++)
		{
			if (vp->getCustomers()[i]->getEmail() == email)
			{
				cout << "E-mail is already in use, please try another one." << endl;
				email_is_taken = true;
			}
			else
			{
				email_is_taken = false;
			}
		}

		if (email_is_taken == false) {
			customer_created = true;
		}
	}
	vp->setCustomer(new Customer(name, address, email));
}

void createBooking(Customer* customer)
{
	static int id = 0; 
	vector<string> accomodations; // should change
	bool activityPass;
	bool sportsPass;
	bool bicycleRent;
	bool swimmingPass;

	cout << "\t\t\t\t|----------------------------------------------|\n";
	cout << "\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t|   There is a couple services we recommend!   |\n";
	cout << "\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t|   - Activity Pass                            |\n";
	cout << "\t\t\t\t|   - Sports Pass                              |\n";
	cout << "\t\t\t\t|   - Bicycle Rent                             |\n";
	cout << "\t\t\t\t|   - Swimming Pass                            |\n";
	cout << "\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t|	  If you want to include any                |\n";
	cout << "\t\t\t\t|          press <1> for each.                 |\n";
	cout << "\t\t\t\t|    Else, press <0>.                          |\n";
	cout << "\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t|----------------------------------------------|\n";


	// make it secure
	cout << "\n\t\t\t\tActivity Pass: ";
	cin >> activityPass;
	cout << "\n\t\t\t\tSport Pass: ";
	cin >> sportsPass;
	cout << "\n\t\t\t\tBicycle Rent: ";
	cin >> bicycleRent;
	cout << "\n\t\t\t\tSwimming Pass: ";
	cin >> swimmingPass;
	cout << endl;

	customer->setBooking(new Booking(++id, accomodations, activityPass, sportsPass, bicycleRent, swimmingPass));

}
