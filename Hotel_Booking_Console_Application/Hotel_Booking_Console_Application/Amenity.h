#pragma once
#include <string>

class Amenity
{
public:
	Amenity(const std::string& name, double surcharge);

	//void setFeatureName(const std::string& name);
	friend std::ostream& operator<< (std::ostream& out, const Amenity& amenity);

private:
	std::string	 m_featureName;
	double		 m_surcharge;
};

