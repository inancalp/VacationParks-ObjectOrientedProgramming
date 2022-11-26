#include "mLibrary.h"
#include "Customer.h"
#include "VacationParcs.h"
#include "Booking.h"

const int& Welcome()
{
	int who;

	cout << "\t\t\t\t--------------------------------------------\n";
	cout << "\t\t\t\t--------------------------------------------\n";
	cout << "\t\t\t\t                                            \n";
	cout << "\t\t\t\t     Welcome to Vacation Parks Project!     \n";
	cout << "\t\t\t\t                                            \n";
	cout << "\t\t\t\t--------------------------------------------\n";
	cout << "\t\t\t\t--------------------------------------------\n";
	cout << "\t\t\t\t                                            \n";

	who = WhoIsIt();

	while (!(who == 1 || who == 2 || who == 3))
	{
		cout << "\t-------------------------------------------------------\n";
		cout << "\t                                                       \n";
		cout << "\t Selected value is NOT A VALID option. Lets try again! \n";
		cout << "\t                                                       \n";
		cout << "\t-------------------------------------------------------\n";

		who = WhoIsIt();
	}

	return who;
}

const int& WhoIsIt()
{
	int who;

	cout << "\t\t\t\t|------------------------|\n";
	cout << "\t\t\t\t|  Who are you?          |\n";
	cout << "\t\t\t\t|------------------------|\n";
	cout << "\t\t\t\t|------------------------|\n";
	cout << "\t\t\t\t|    1) Owner            |\n";
	cout << "\t\t\t\t|                        |\n";
	cout << "\t\t\t\t|    2) Employee         |\n";
	cout << "\t\t\t\t|                        |\n";
	cout << "\t\t\t\t|    3) Customer         |\n";
	cout << "\t\t\t\t|------------------------|\n";
	cout << "\t\t\t\t|------------------------|\n";

	cin >> who;
	return who;
}

const int& CustomerOptionsList()
{
	int selected_option;

	cout << "\t\t\t\t|--------------------------------|\n";
	cout << "\t\t\t\t|  What would you like to do?    |\n";
	cout << "\t\t\t\t|--------------------------------|\n";
	cout << "\t\t\t\t|--------------------------------|\n";
	cout << "\t\t\t\t|    1) Make Booking             |\n";
	cout << "\t\t\t\t|                                |\n";
	cout << "\t\t\t\t|    2) Option...                |\n";
	cout << "\t\t\t\t|                                |\n";
	cout << "\t\t\t\t|    3) Option...                |\n";
	cout << "\t\t\t\t|--------------------------------|\n";
	cout << "\t\t\t\t|--------------------------------|\n";

	cin >> selected_option;
	return selected_option;
}

void CreateCustomer(Customer& customer, int& id, string& name, string& email, vector<int>& bookings)
{
	customer.setId(id);
	customer.setBookings(bookings);

	cout << "Customer Name: ";
	cin >> name;
	customer.setName(name);

	cout << "Customer E-Mail: ";
	cin >> email;
	customer.setEmail(email);
};

void CreateBooking(
	Customer& customer,
	int& booking_id,
	bool& activity_pass,
	bool& sports_pass,
	bool& bicycle_rent,
	bool& swimming_pass
)
{
	int activityPass;
	int sportsPass;
	int bicycleRent;
	int swimmingPass;

	cout << "\t\t\t\t|----------------------------------------------|\n";
	cout << "\t\t\t\t|   There is a couple services we recommend!   |\n";
	cout << "\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t|   - Activity Pass                            |\n";
	cout << "\t\t\t\t|   - Sports Pass                              |\n";
	cout << "\t\t\t\t|   - Bicycle Rent                             |\n";
	cout << "\t\t\t\t|   - Swimming Pass                            |\n";
	cout << "\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t| If you want to include any with your booking |\n";
	cout << "\t\t\t\t|        press <1> for each!                   |\n";
	cout << "\t\t\t\t|        Else, press any other digit to skip   |\n";
	cout << "\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t|----------------------------------------------|\n";


	cout << "\n\t\t\t\tActivity Pass: ";
	cin >> activityPass;
	cout << "\n\t\t\t\tSport Pass: ";
	cin >> sportsPass;
	cout << "\n\t\t\t\tBicycle Rent: ";
	cin >> bicycleRent;
	cout << "\n\t\t\t\tSwimming Pass: ";
	cin >> swimmingPass;

	activity_pass = activityPass == 1 ? true : false;
	sports_pass = sportsPass == 1 ? true : false;
	bicycle_rent = bicycleRent == 1 ? true : false;
	swimming_pass = swimmingPass == 1 ? true : false;

};





