#ifndef BOOKINGCONTROLLER_H
#define BOOKINGCONTROLLER_H

#include "VacationParcs.h"
#include "LuxuryLevel.h"
#include "_ParcController.h" //selectParc() in use
#include "Bungalow.h"
#include "HotelRoom.h"

void CreateBooking(VacationParcs* vp, Customer* c);
void addService(Parcs* selected_parc_obj, bool& swimmingPass, bool& sportsPass, bool& bicycleRent, bool& activityPass);
bool addServiceMiddleware(bool& service_state, string& service_name);
LuxuryLevel* filterAccomodations(VacationParcs* vp, char& accom_type, int& accom_nbrPeople, char& accom_luxuryLevel);
void listFilteredAccomodations(VacationParcs* vp, Parcs* selected_parc_obj, LuxuryLevel* luxuryLevel_obj, int& accom_nbrPeople, char& accom_type, vector<Accomodations*>& accoms_filtered);


//void searchBooking(VacationParcs* vp, Customer* c);

void showBookings(VacationParcs* vp);


#endif // !BOOKINGCONTROLLER_H


