#ifndef CUSTOMERCONTROLLER_H
#define CUSTOMERCONTROLLER_H

#include "VacationParcs.h"
#include "Customer.h"

void createCustomer(VacationParcs* vp);
void showCustomers(VacationParcs* vp);
void deleteCustomer(VacationParcs* vp);
void ModifyCustomer(VacationParcs* vp, Customer* c);
string ModifyCustomerEmail(VacationParcs* vp, Customer* c);

#endif // !CUSTOMERCONTROLLER_H



