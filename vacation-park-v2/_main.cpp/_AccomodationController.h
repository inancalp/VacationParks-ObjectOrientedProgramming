
#include "Parcs.h"
#include "HotelRoom.h"
#include "Bungalow.h"
#include "VacationParcs.h"

void createAccomodation(Parcs* p);
LuxuryLevel* createLuxuryLevel(string accom_kind);
void createLuxuryLevelMiddleWare(int& data, string data_name);
void showAccomodations(VacationParcs* vp);