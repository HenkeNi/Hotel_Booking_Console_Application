#include "Amenity.h"

#include <iostream>

Amenity::Amenity(const std::string& name, double surcharge)
	: m_featureName{ name }, m_surcharge{ surcharge }
{
}

Amenity::Amenity(Amenity* amenity)
	: m_featureName{ amenity->m_featureName }, m_surcharge{ amenity->m_surcharge }
{
	delete amenity;	// TODO: Check if correct way...
	amenity = nullptr;
}


std::ostream& operator<< (std::ostream& out, const Amenity& amenity)
{
	out << amenity.m_featureName;
	//out << "Amenity:\nfeature: " << amenity.m_featureName << "\nsurcharge: " << amenity.m_surcharge << '\n';
	return out;
}