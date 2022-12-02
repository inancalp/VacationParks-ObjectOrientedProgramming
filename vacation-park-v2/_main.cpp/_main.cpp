#include "useCaseLibrary.h"
#include "_ParcController.h"

//(check!) there are no bookings for getName() 

int main()
{

	VacationParcs* vp = new VacationParcs("MainObject", "Sint Katelijne Waver", "VAT info here.");

	createParc(vp);
	createParc(vp);
	showParcs(vp);
	deleteParc(vp);
	showParcs(vp);

	delete vp;



	//luxury_level(bbq, surround, breakfast, cleaning, accKind)
	//LuxuryLevel* lux_vip = new LuxuryLevel(true, true, true, true, "VIP");
	//LuxuryLevel* lux_prem = new LuxuryLevel(false, false, true, true, "Premium");
	//LuxuryLevel* lux_comfort = new LuxuryLevel(false, false, false, true, "Comfort");

	////accomodation many params...
	//Accomodations* a1 = new HotelRoom(1, 5, 35, false, lux_comfort, 20, "Next to Ocean", 3, 1);
	//Accomodations* a2 = new Bungalow(2, 2, 30, true, lux_vip, 1);
	//cout << a1->toString() << endl;
	//cout << a2->toString() << endl;


	//delete lux_vip;
	//delete lux_prem;
	//delete lux_comfort;

	//delete a1;
	//delete a2;
	return 0;
}