#pragma once
#include "Address.h"

#include <memory>
#include <optional>
#include <string>


class ContactDetails
{
public:
	ContactDetails();
	ContactDetails(std::optional<std::string> email, std::optional<std::string> phone, std::shared_ptr<Address> address);
	
	// NEEDED?
	std::optional<std::string> getEmail() const;
	std::optional<std::string> getPhoneNumber() const;

	//Address* getAddress() const; // return a shared pointer or just a raw pointer
	
	void setEmailAddres(const std::string& email);
	void setPhoneNumber(const std::string& phone);
	void setAddress(std::shared_ptr<Address> address); 

	void printAddress() const; 

private:
	std::optional<std::string> m_emailAddress;
	std::optional<std::string> m_phoneNumber;
	std::shared_ptr<Address>   m_address;
};

