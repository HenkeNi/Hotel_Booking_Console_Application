#include "Amenity.h"

#include <iostream>

Amenity::Amenity(const std::string& name, double surcharge)
	: m_featureName{ name }, m_surcharge{ surcharge }
{
}


std::ostream& operator<< (std::ostream& out, const Amenity& amenity)
{
	out << "Amenity:\nfeature: " << amenity.m_featureName << "\nsurcharge: " << amenity.m_surcharge << '\n';
	return out;
}