
#ifndef  PARCCONTROLLER_H
#define PARCCONTROLLER_H

#include "VacationParcs.h"
#include "Parcs.h"
#include <iomanip>
#include <iostream>
#include <array>
#include <fstream>
#define PARCSERVICESSIZE 6
#define PARCSFILE "../files/parcs.txt"
#define PARCSERVICESFILE "../files/parcservices.txt"

void reWriteParcsFile(VacationParcs* vp);
void emptyParcServicesFile();
void retrieveParcsFile(VacationParcs* vp);
ParcServices* retrieveParcServicesFile(ifstream& parcServicesFile);
void createParc(VacationParcs* vp);
void saveParcFile(Parcs* parc);
void saveParcServicesFile(ParcServices* parc_services);
ParcServices* createParcServices(string& parc_name);
void showParcs(VacationParcs* vp);
void changeParc(VacationParcs* vp);
void deleteParc(VacationParcs* vp);
Parcs* selectParc(VacationParcs* vp);

#endif