#include "Address.h"

#include <iostream>

Address& Address::setStreetName(const std::string& street)
{
	m_streetName = street;
	return *this;
}

Address& Address::setStreetNumber(const std::string& number)
{
	m_streetNumber = number;
	return *this;
}

Address& Address::setPostalCode(const std::string& postalCode)
{
	m_postalCode = postalCode;
	return *this;
}

Address& Address::setCity(const std::string& city)
{
	m_city = city;
	return *this;
}

Address& Address::setCountry(const std::string& country)
{
	m_country = country;
	return *this;
}


// Overloaded output operator
std::ostream& operator<< (std::ostream& out, const Address& address)
{
	out << "Address: "
		"\ncountry: "       << address.m_country      << 
		"\ncity: "		    << address.m_city	      <<
		"\nstreet name: "   << address.m_streetName   << 
		"\nstreet number: " << address.m_streetNumber << 
		"\npostal code: "	<< address.m_postalCode   << 
		'\n';
	return out;
}


// Overloaded input operator
std::istream& operator>> (std::istream& in, Address& address)
{	
	std::cout << "Country: ";
	std::getline(in, address.m_country);	// accepts multiple words
	
	std::cout << "City: ";
	std::getline(in, address.m_city);

	std::cout << "Street name: ";
	std::getline(in, address.m_streetName);

	std::cout << "Street number: ";
	std::getline(in, address.m_streetNumber);

	std::cout << "Postal code: ";
	std::getline(in, address.m_postalCode);
	
	return in;
}