#ifndef USECASELIBRARY_H
#define USECASELIBRARY_H

#include "VacationParcs.h"
#include "Customer.h"
#include "Booking.h"
#include "Parcs.h"
#include "Accomodations.h"
#include "HotelRoom.h"
#include "Bungalow.h"
#include "LuxuryLevel.h"
#include "_CustomerController.h"
#include "_ParcController.h"
#include "_AccomodationController.h"
#include "_BookingController.h"
#include <iomanip>

void OwnerType(VacationParcs* vp);
void EmployeeType(VacationParcs* vp);
void CustomerType(VacationParcs* vp);
void CustomerSession(VacationParcs* vp, Customer* c);

void CreateBooking(VacationParcs* vp, Customer* c);
LuxuryLevel* filterAccomodations(VacationParcs* vp, char& accom_type, int& accom_nbrPeople, char& accom_luxuryLevel);
void listFilteredAccomodations(VacationParcs* vp, Parcs* selected_parc_obj, LuxuryLevel* luxuryLevel_obj, int& accom_nbrPeople, char& accom_type, vector<Accomodations*>& accoms_filtered);
void addService(Parcs* selected_parc_obj, bool& swimmingPass, bool& sportsPass, bool& bicycleRent, bool& activityPass);
bool addServiceMiddleware(bool& service_state, string& service_name);

#endif // !USECASELIBRARY_H


