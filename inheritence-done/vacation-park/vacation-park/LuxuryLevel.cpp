#include "LuxuryLevel.h"


LuxuryLevel::LuxuryLevel() {
	cout << "(!) LuxuryLevel::Constructor" << endl;
}
LuxuryLevel::~LuxuryLevel() {
	cout << "(!) LuxuryLevel::Destructor" << endl;
}

void LuxuryLevel::setBbq(bool bbq) {
	this->Bbq = bbq;
}
void LuxuryLevel::setSurroundSystem(const bool surround_system) { // (?)&
	this->SurroundSystem = surround_system;
}
void LuxuryLevel::setBreakfastService(const bool breakfast_service) { // (?)&
	this->BreakfastService = breakfast_service;
}
void LuxuryLevel::setCleaningService(const bool cleaning_service) { // (?)&
	this->CleaningService = cleaning_service;
}
void LuxuryLevel::setAccomodationKind(const string accomodation_kind) {
	this->AccomodationKind = accomodation_kind;
}

const bool& LuxuryLevel::getBbq() const {
	return this->Bbq;
}
const bool& LuxuryLevel::getSurroundSystem() const {
	return this->SurroundSystem;
}
const bool& LuxuryLevel::getBreakfastService() const {
	return this->BreakfastService;
}
const bool& LuxuryLevel::getCleaningService() const {
	return this->CleaningService;
}
const string& LuxuryLevel::getAccomodationKind() const {
	return this->AccomodationKind;
}