#include "VacationParcs.h"
#include "Customer.h"
#include "Booking.h"
#include "Accomodation.h"
#include "Bungalow.h"
#include "HotelRoom.h"
#include "mLibrary.h"

int main()
{
	int is_customer;
	int booking_id = 1;
	int customer_id = 1;
	string customer_name;
	string customer_email;
	vector<int> customer_bookings{};
	int selected_option;
	

	cout << "\t(0)######################";
	cout << endl << endl;

	VacationParcs* v = new VacationParcs("VacationParcs::Name", "VacationParcs::Address", "VacationParcs::VAT");
	cout << v->toString() << endl;
	v->Accomodations.push_back(new Accomodation(1, 10, 3, true, "Luxurious!!"));
	v->Accomodations.push_back(new Accomodation(10, 100, 30, false, "Not too Luxurious"));

	cout << v->getAccomodations() << endl;



	delete v->Accomodations[0];
	delete v->Accomodations[1];

	v->Accomodations.erase(v->Accomodations.begin());
	v->Accomodations.erase(v->Accomodations.begin());
	cout << v->getAccomodations() << endl;
	delete v;


	cout << endl << endl;
	cout << endl << endl;








	/*cout << "\t(1)######################";
	cout << endl << endl;
	Accomodation* a = new Accomodation(1, 10, 3, true, "Luxurious!!");
	cout << a->toString() << endl;
	delete a;

	cout << endl << endl;
	cout << endl << endl;*/








	/*cout << "\t(2)######################";
	cout << endl << endl;
	Accomodation* b = new Bungalow;
	cout << b->toString() << endl;
	b->setId(1);
	b->setNbrPeople(10);
	b->setBathroomWithBath(true);
	b->setSize(40);
	b->setLuxuryLevel("Very Luxurious!");
	cout << "   ------" << endl;
	cout << b->toString() << endl;
	delete b;
	cout << endl << endl;
	cout << endl << endl;









	cout << "\t(3)######################";
	cout << endl << endl;
	Accomodation* h = new HotelRoom;
	cout << h->toString() << endl;
	delete h;
	cout << endl << endl;
	cout << endl << endl;








	cout << "\t(4)######################";
	cout << endl << endl;
	HotelRoom h2;
	cout << h2.toString() << endl;
	cout << endl << endl;
	cout << endl << endl;*/









	

	// "Welcome();" should return [int](3) for to progress as customer.
	is_customer = Welcome(); 
	if (is_customer != 3)
	{
		cout << "\nThis program is only functional if the user is a customer." << endl;
		cout << " Program being terminated." << endl;
		return 0;
	}
	Customer myCustomer;
	cout << "You are a customer, great! Let's get going..." << endl;

	CreateCustomer(
		myCustomer,
		customer_id,
		customer_name,
		customer_email,
		customer_bookings
	);

	myCustomer.showCustomerInfo();

	cout << "\nOkay then " << myCustomer.getName() << "! " << "Lets show you your options: \n\n";

	selected_option = CustomerOptionsList();

	bool activity_pass;
	bool sports_pass;
	bool bicycle_rent;
	bool swimming_pass;
	vector<int> accomodations{ -1 };

	switch (selected_option)
	{
		// can't put another "case" cuz Booking Object Declaration
	case 1:
		CreateBooking(
			myCustomer,
			booking_id,
			activity_pass,
			sports_pass,
			bicycle_rent,
			swimming_pass
		);
		Booking myBooking(
			booking_id,
			myCustomer,
			accomodations,
			activity_pass,
			sports_pass,
			bicycle_rent,
			swimming_pass
		);
		myCustomer.addBooking(booking_id);
		booking_id++;
		myCustomer.showCustomerInfo();
		break;
	}
	return 0;
}