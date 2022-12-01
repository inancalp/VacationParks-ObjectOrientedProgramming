#include "LuxuryLevel.h"

LuxuryLevel::LuxuryLevel(
	const bool bbq,
	const bool surround_system,
	const bool breakfast_service,
	const bool cleaning_service,
	const string accomodation_kind
) : m_bbq(bbq), m_surroundSystem(surround_system), m_breakfastService(breakfast_service), m_cleaningService(cleaning_service), m_accomodationKind(accomodation_kind)
{
	cout << "(!) LuxuryLevel::Constructor" << endl;
}
LuxuryLevel::~LuxuryLevel() {
	cout << "(!) LuxuryLevel::Destructor" << endl;
}

const bool& LuxuryLevel::getBbq() const {
	return this->m_bbq;
}
const bool& LuxuryLevel::getSurroundSystem() const {
	return this->m_surroundSystem;
}
const bool& LuxuryLevel::getBreakfastService() const {
	return this->m_breakfastService;
}
const bool& LuxuryLevel::getCleaningService() const {
	return this->m_cleaningService;
}
const string& LuxuryLevel::getAccomodationKind() const {
	return this->m_accomodationKind;
}

void LuxuryLevel::setBbq(const bool& bbq) {
	this->m_bbq = bbq;
}
void LuxuryLevel::setSurroundSystem(const bool& surrond_system) {
	this->m_bbq = surrond_system;
}
void LuxuryLevel::setBreakfastService(const bool& breakfast_service) {
	this->m_breakfastService = breakfast_service;
}
void LuxuryLevel::setCleaningService(const bool& cleaning_service) {
	this->m_cleaningService = cleaning_service;
}
void LuxuryLevel::setAccomodationKind(const string& accomodation_kind) {
	this->m_accomodationKind = accomodation_kind;
}

const string LuxuryLevel::toString() const {
	ostringstream output;
	output << "--------------" << endl;
	output << "LuxuryLevel::getBbq() ->> " << boolalpha << this->getBbq() << endl;
	output << "LuxuryLevel::getSurroundSystem() ->> " << boolalpha << this->getSurroundSystem() << endl;
	output << "LuxuryLevel::getBreakfastService() ->> " << boolalpha << this->getBreakfastService() << endl;
	output << "LuxuryLevel::getCleaningService() ->> " << boolalpha << this->getCleaningService() << endl;
	output << "LuxuryLevel::getAccomodationKind() ->> " << this->getAccomodationKind() << endl;
	output << "--------------";
	return output.str();
}