#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

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
#include <iostream>
using namespace std;

void OwnerType(VacationParcs* vp);
void EmployeeType(VacationParcs* vp);
void CustomerType(VacationParcs* vp);
void CustomerSession(VacationParcs* vp, Customer* c);

#endif // !MAINCONTROLLER_H


