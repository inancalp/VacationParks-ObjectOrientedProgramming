
#ifndef VACATIONPARCS_H
#define VACATIONPARCS_H

using namespace std;
#include "Customer.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class VacationParcs
{
private:
	string m_name;
	string m_address;
	string m_vat;
	vector<int> m_parcs; //change to pointer later
	vector<Customer*> m_customers;

public:
	VacationParcs(string name, string address, string vat);
	~VacationParcs();

	const string& getName() const;
	const string& getAddress() const;
	const string& getVat() const;

	const vector<int>& getParcs() const;
	const vector<Customer*>& getCustomers() const;

	void setName(const string& name);
	void setAddress(const string& address);
	void setVat(const string& vat);

	void setParc(int parc);
	void setCustomer(Customer* customer);

	const string toString() const;
};


#endif