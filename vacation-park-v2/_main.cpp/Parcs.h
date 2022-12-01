#ifndef  PARCS_H
#define PARCS_H

using namespace std;
#include "Accomodations.h"
#include <vector>

class Parcs {
private:
	string m_name;
	string m_address;
	vector<string> m_parcServices; // change later on
	vector<Accomodations*> m_accomodations;
public:
	Parcs(string name, string address);
	~Parcs();

	const string& getName() const;
	const string& getAddress() const;
	const vector<string>& getParcServices() const;
	const vector<Accomodations*>& getAccomodations() const;

	void setName(const string& name);
	void setAddress(const string& address);
	void setParcServices(string parc_services);
	void setAccomodation(Accomodations* accomodation);

	const string toString() const;
};



#endif // ! PARCS_H
