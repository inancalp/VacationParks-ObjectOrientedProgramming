
#ifndef VACATIONPARCS_H
#define VACATIONPARCS_H

using namespace std;
#include "Customer.h"
#include "Parcs.h" // two times standard libraries ??

class VacationParcs
{
private:
	string m_name;
	string m_address;
	string m_vat;
	vector<Parcs*> m_parcs; //change to pointer later
	vector<Customer*> m_customers;

public:
	VacationParcs(string name, string address, string vat);
	~VacationParcs();

	const string& getName() const;
	const string& getAddress() const;
	const string& getVat() const;

	vector<Parcs*>& getParcs();
	const vector<Customer*>& getCustomers() const;

	void setName(const string& name);
	void setAddress(const string& address);
	void setVat(const string& vat);

	void setParc(Parcs* parc);
	void setCustomer(Customer* customer);

	string toString();
};


#endif

