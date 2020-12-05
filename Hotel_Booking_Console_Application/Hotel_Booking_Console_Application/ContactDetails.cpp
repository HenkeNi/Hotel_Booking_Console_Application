#include "ContactDetails.h"
#include <iostream>


ContactDetails::ContactDetails()
{
}

ContactDetails::ContactDetails(std::optional<std::string> email, std::optional<std::string> phone, std::shared_ptr<Address> address)
	: m_emailAddress{ email }, m_phoneNumber{ phone }, m_address{ address }
{
}

std::optional<std::string> ContactDetails::getEmail() const
{
	if (m_emailAddress)
		return m_emailAddress.value();
	
	return std::nullopt;
}

std::optional<std::string> ContactDetails::getPhoneNumber() const
{
	if (m_phoneNumber)
		return m_phoneNumber.value();
	
	return std::nullopt;
}

void ContactDetails::setEmailAddres(const std::string& email)
{
	m_emailAddress = email; // TODO: use move-semantics instead??
}

void ContactDetails::setPhoneNumber(const std::string& phone)
{
	m_phoneNumber = phone;
}

void ContactDetails::setAddress(std::shared_ptr<Address> address)
{
	m_address = address;
}


//void ContactDetails::addAddress(std::shared_ptr<Address> address)
//{
//	m_address = address;
//}



void ContactDetails::printAddress() const
{
	std::cout << *m_address;
}
