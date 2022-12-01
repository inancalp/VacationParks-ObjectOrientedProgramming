#include "ParcServices.h"

ParcServices::ParcServices
(
	bool subtropic_swimming_pool,
	bool sports_infrastructure,
	bool bowling_alley,
	bool bicycle_rent,
	bool childrens_paradise,
	bool water_bikes
) : m_subtropicSwimmingPool(subtropic_swimming_pool), m_sportsInfrastructure(sports_infrastructure), m_bowlingAlley(bowling_alley), m_bicycleRent(bicycle_rent), m_childrensParadise(childrens_paradise), m_waterBikes(water_bikes)
{
	cout << "(!) Parcs::Constructor" << endl;
}

ParcServices::~ParcServices()
{
	cout << "(!) Parcs::Destructor" << endl;
}

const bool& ParcServices::getSubtropicSwimmingPool() const
{
	return this->m_subtropicSwimmingPool;
}
const bool& ParcServices::getSportsInfrastructure() const
{
	return this->m_sportsInfrastructure;
}
const bool& ParcServices::getBowlingAlley() const
{
	return this->m_bowlingAlley;
}
const bool& ParcServices::getBicycleRent() const
{
	return this->m_bicycleRent;
}
const bool& ParcServices::getChildrensParadise() const
{
	return this->m_childrensParadise;
}
const bool& ParcServices::getWaterBikes() const
{
	return this->m_waterBikes;
}

void ParcServices::setSubtropicSwimmingPool(const bool& subtropic_swimming_pool)
{
	this->m_subtropicSwimmingPool = subtropic_swimming_pool;
}
void ParcServices::setSportsInfrastructure(const bool& sports_infrastructure)
{
	this->m_sportsInfrastructure = sports_infrastructure;
}
void ParcServices::setBowlingAlley(const bool& bowling_alley)
{
	this->m_bowlingAlley = bowling_alley;
}
void ParcServices::setBicycleRent(const bool& bicycle_rent)
{
	this->m_bicycleRent = bicycle_rent;
}
void ParcServices::setChildrensParadise(const bool& childrens_paradise)
{
	this->m_childrensParadise = childrens_paradise;
}
void ParcServices::setWaterBikes(const bool& water_bikes)
{
	this->m_waterBikes = water_bikes;
}

const string ParcServices::toString() const
{
	stringstream output;
	output << "--------------" << endl;
	output << "ParcServices::getSubtropicSwimmingPool() ->> " << boolalpha << this->getSubtropicSwimmingPool() << endl;
	output << "ParcServices::getSportsInfrastructure() ->> " << boolalpha << this->getSportsInfrastructure() << endl;
	output << "ParcServices::getBowlingAlley() ->> " << boolalpha << this->getBowlingAlley() << endl;
	output << "ParcServices::getBicycleRent() ->> " << boolalpha << this->getBicycleRent() << endl;
	output << "ParcServices::getChildrensParadise() ->> " << boolalpha << this->getChildrensParadise() << endl;
	output << "ParcServices::getWaterBikes() ->> " << boolalpha << this->getWaterBikes() << endl;
	output << "--------------";
	return output.str();
}