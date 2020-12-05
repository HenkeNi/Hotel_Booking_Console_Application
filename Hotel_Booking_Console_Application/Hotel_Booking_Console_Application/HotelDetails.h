#pragma once

#include "Amenity.h"
#include "ContactDetails.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class HotelDetails
{
public:
	using amenityList_t = std::vector<Amenity>;
	//using contactDetails_t = std::unique_ptr<ContactDetails>;

public:
	HotelDetails();

	HotelDetails& setHotelName(const std::string& name);
	HotelDetails& setContactDetails(const ContactDetails& details);
	HotelDetails& addAmenity(const Amenity& amenity);
	HotelDetails& setDistanceToOcean(int meters);
	HotelDetails& setStarRating(int stars);

	friend std::ostream& operator<< (std::ostream& out, const HotelDetails& details);

private:
	std::string		   m_hotelName;
	ContactDetails     m_contactDetails;
	amenityList_t	   m_amenities;
	std::optional<int> m_metersToOcean;
	int				   m_starRating;
};

