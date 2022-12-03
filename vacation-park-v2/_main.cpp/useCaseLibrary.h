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
#include "_ParcController.h"
#include "_AccomodationController.h"
#include <iomanip>


void createBooking(Customer* customer);
void OwnerType(VacationParcs* vp);
void EmployeeType(VacationParcs* vp);
void CustomerType(VacationParcs* vp);






#endif // !USECASELIBRARY_H


