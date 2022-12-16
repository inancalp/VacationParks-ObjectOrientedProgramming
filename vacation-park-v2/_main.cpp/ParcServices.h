#ifndef PARCSERVICES_H
#define PARCSERVICES_H
using namespace std;
#include <iostream>
#include <string>
#include <sstream>

class ParcServices {
private:
	string m_parcName;
	bool m_subtropicSwimmingPool;
	bool m_sportsInfrastructure;
	bool m_bowlingAlley;
	bool m_bicycleRent;
	bool m_childrensParadise;
	bool m_waterBikes;
public:
	ParcServices
	(
		string m_parcName,
		bool subtropic_swimming_pool,
		bool sports_infrastructure,
		bool bowling_alley,
		bool bicycle_rent,
		bool childrens_paradise,
		bool water_bikes
	);
	~ParcServices();
	const string& getParcName() const;
	const bool& getSubtropicSwimmingPool() const;
	const bool& getSportsInfrastructure() const;
	const bool& getBowlingAlley() const;
	const bool& getBicycleRent() const;
	const bool& getChildrensParadise() const;
	const bool& getWaterBikes() const;
	void setParcName(const string& parc_name);
	void setSubtropicSwimmingPool(const bool& subtropic_swimming_pool);
	void setSportsInfrastructure(const bool& sports_infrastructure);
	void setBowlingAlley(const bool& bowling_alley);
	void setBicycleRent(const bool& bicycle_rent);
	void setChildrensParadise(const bool& childrens_paradise);
	void setWaterBikes(const bool& water_bikes);
	const string toString() const;
};

#endif // !PARCSERVICES_H