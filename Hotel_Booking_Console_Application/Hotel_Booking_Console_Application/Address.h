#pragma once

#include <string>

class Address
{
public:
	Address& setCountry(const std::string& country);
	Address& setCity(const std::string& city);
	Address& setStreetName(const std::string& street);
	Address& setStreetNumber(const std::string& number);
	Address& setPostalCode(const std::string& postalCode);

	friend std::ostream& operator<< (std::ostream& out, const Address& address);
	friend std::istream& operator>> (std::istream& in, Address& address);

private:
	std::string m_country;
	std::string m_city;
	std::string m_streetName;
	std::string m_streetNumber;
	std::string m_postalCode;
};

