#ifndef BOOKINGCONTROLLER_H
#define BOOKINGCONTROLLER_H

#include "VacationParcs.h"
#include "LuxuryLevel.h"
#include "_ParcController.h" //selectParc() in use
#include "Bungalow.h"
#include "HotelRoom.h"

#include <iostream>
using namespace std;

#define BOOKINGSFILE "../files/bookings.txt"


void saveBookingFile(Booking* booking);
void retrieveBookingsFile(VacationParcs* vp);
void reWriteBookingsFile(VacationParcs* vp);

void CreateBooking(VacationParcs* vp, Customer* c);
void addService(Parcs* selected_parc_obj, bool& swimmingPass, bool& sportsPass, bool& bicycleRent, bool& activityPass);
bool addServiceMiddleware(bool& service_state, string& service_name);
void showBookings(VacationParcs* vp);
void showCustomersBookings(VacationParcs* vp, Customer* customer);

void setAvailableAccomodations(Parcs* selected_parc_obj, vector<Accomodations*>& available_accoms, vector<Accomodations*>& accoms_to_book);
void showAvailableAccomodations(vector<Accomodations*>& available_accoms);

LuxuryLevel* filterAccomodationLuxuryLevel(VacationParcs* vp);
string filterAccomodationType();

void showFilteredAccomodations(vector<Accomodations*>& accoms_filtered);
void addAccomodationToBooking(vector<Accomodations*>& accoms_filtered, vector<Accomodations*>& accoms_to_book);


void modifyBookings(VacationParcs* vp, Customer* customer);
void bookingModifyParcServices(VacationParcs* vp, Booking* booking);
void bookingAddAccomodation(VacationParcs* vp, Booking* booking);
void bookingRemoveAccomodation(VacationParcs* vp, Booking* booking);

void deleteBookings(VacationParcs* vp);


#endif // !BOOKINGCONTROLLER_H


