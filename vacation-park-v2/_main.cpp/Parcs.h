#ifndef  PARCS_H
#define PARCS_H

using namespace std;
#include "Accomodations.h"
#include "ParcServices.h"

class Parcs {
private:
	string m_name;
	string m_address;
	ParcServices* m_parcServices; // change later on
	vector<Accomodations*> m_accomodations;
public:
	Parcs(string name, string address, ParcServices* parc_services);
	~Parcs();

	const string& getName() const;
	const string& getAddress() const;
	ParcServices* getParcServices() const; //deleted const, refer changeParc()
	const vector<Accomodations*>& getAccomodations() const;

	void setName(const string& name);
	void setAddress(const string& address);
	void setParcServices(ParcServices* parc_services);
	void setAccomodation(Accomodations* accomodation);

	const string toString() const;
};



#endif // ! PARCS_H
