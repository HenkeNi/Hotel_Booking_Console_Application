#pragma once
#include <string>
#include <iostream>
class Amenity
{
public:
	Amenity(const std::string& name, double surcharge);
	Amenity(Amenity* amenity);
	//void setFeatureName(const std::string& name);
	void sayHi() { std::cout << "HI"; }

	friend std::ostream& operator<< (std::ostream& out, const Amenity& amenity);

private:
	std::string	 m_featureName;
	double		 m_surcharge;
};

