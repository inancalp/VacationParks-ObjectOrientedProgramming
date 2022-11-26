
// include's from VacationParcs.h follow us through to this file.
#include "VacationParcs.h"


VacationParcs::VacationParcs(string name, string address, string vat)
	: Name(name), Address(address), Vat(vat)
{
	// initializations(?) below can be deleted.
	Parks = {};
	Customers = {};
	Bookings = {};
	Accomodations = {}; //
	cout << "(!) VacationParcs::Constructor" << endl;
}
VacationParcs::~VacationParcs() {
	cout << "(!) VacationParcs::Destructor" << endl;
}


void VacationParcs::addCustomer(const int& customer_id)
{
	this->Customers.push_back(customer_id);
}

const void VacationParcs::getCustomers() const
{
	int i;
	cout << "Customer IDs: [ ";
	for (i = 0; i < this->Customers.size(); i++)
	{
		cout << this->Customers[i];
		if (i != this->Customers.size() - 1)
		{
			cout << ", ";
		}
	}
	cout << " ]" << endl;
}


void VacationParcs::setName(const string name) {
	this->Name = name;
};
void VacationParcs::setAddress(const string address) {
	this->Address = address;
};
void VacationParcs::setVat(const string vat) {
	this->Vat = vat;
};

const string& VacationParcs::getName() const {
	return this->Name;
};
const string& VacationParcs::getAddress() const {
	return this->Address;
};
const string& VacationParcs::getVat() const {
	return this->Vat;
};

const string VacationParcs::toString() const {
	ostringstream output;
	output << " VacationParcs::Name -> " << this->getName() << endl;
	output << " VacationParcs::Address -> " << this->getAddress() << endl;
	output << " VacationParcs::Vat -> " << this->getVat();
	return output.str();
}

const string VacationParcs::getAccomodations() const {

	ostringstream output;
	output << endl;
	output << "\t-------------------------------------" << endl;
	output << "\t(!) VacationParcs::getAccomodations CALL" << endl;
	output << "\t-------------------------------------" << endl;
	output << "\tSIZE OF VECTOR: " << this->Accomodations.size() << endl;
	output << endl << endl;

	if (this->Accomodations.size() == 0) {
		output << "------------------------------------------------------" << endl;
		output << "VacationParcs::getAccomodations() ->> Nothing to show!" << endl;
		output << "------------------------------------------------------" << endl;
		return output.str();
	}
	for (size_t i{ 0 }; i < this->Accomodations.size(); i++)
	{	
		output << Accomodations[i]->toString() << endl << endl;
	}

	return output.str();

}