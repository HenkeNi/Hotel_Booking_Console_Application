#include "HotelDetails.h"

HotelDetails::HotelDetails()
{
}

HotelDetails& HotelDetails::setHotelName(const std::string& name)
{
	m_hotelName = name;
	return *this;
}

HotelDetails& HotelDetails::setContactDetails(const ContactDetails& details)
{
	m_contactDetails = details;
	//m_contactDetails = std::make_unique<ContactDetails>(details);
	return *this;
}

HotelDetails& HotelDetails::addAmenity(const Amenity& amenity)
{
	m_amenities.push_back(std::move(amenity));
	return *this;
}

HotelDetails& HotelDetails::setDistanceToOcean(int meters)
{
	m_metersToOcean = meters;
	return *this;
}

HotelDetails& HotelDetails::setStarRating(int stars)
{
	m_starRating = stars;
	return *this;
}

std::ostream& operator<< (std::ostream& out, const HotelDetails& details)
{
	out << details.m_hotelName;
	return out;
}