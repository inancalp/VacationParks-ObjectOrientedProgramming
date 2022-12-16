#ifndef ACCOMMODATIONCONTROLLER_H
#define ACCOMMODATIONCONTROLLER_H

#include "Parcs.h"
#include "HotelRoom.h"
#include "Bungalow.h"
#include "VacationParcs.h"
#define ACCOMSFILE "../files/accommodations.txt"

void saveLuxuryLevelsFile(const int& accom_id, LuxuryLevel* ll);
void saveAccomodationFile(Accomodations* accom);
void retrieveAccomodationsFile(VacationParcs* vp);
void reWriteAccomodationsFile(VacationParcs* vp);

void createAccomodation(VacationParcs* vp);
void createHotelRoom(VacationParcs* vp, Parcs* p, int accom_id);
void createBungalow(VacationParcs* vp, Parcs* p, int accom_id);

LuxuryLevel* selectLuxuryLevel(VacationParcs* vp);
LuxuryLevel* createLuxuryLevel(string accom_kind);
void createLuxuryLevelMiddleWare(int& data, string data_name);
void showAccomodations(VacationParcs* vp);

void modifyAccomodation(VacationParcs* vp);
Accomodations* selectAccomodation(VacationParcs* vp);
void modifyHotelRoom(VacationParcs* vp, Accomodations* accom);
void modifyBungalow(VacationParcs* vp, Accomodations* accom);
void deleteAccomodation(VacationParcs* vp);

#endif

