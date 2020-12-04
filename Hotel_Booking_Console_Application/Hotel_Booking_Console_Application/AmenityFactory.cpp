#include "AmenityFactory.h"
#include <stdexcept>


AmenityFactory::amenityList_t AmenityFactory::getRoomAmenity(AmenityLevel lvl)
{
	switch (lvl)
	{
	case AmenityLevel::standard:
		return createStandardRoomAmenity();
		break;
	case AmenityLevel::deluxe:
		return createDeluxeRoomAmenity();
		break;
	case AmenityLevel::vip:
		return createLuxuryRoomAmenity();
		break;
	default:
		throw std::runtime_error("Invalid AmenityLevel!");
	}
}

AmenityFactory::amenityList_t AmenityFactory::createStandardRoomAmenity()
{
	AmenityFactory::amenityList_t amenities;
	amenities.push_back(new Amenity{ "TV", 5.43 });
	amenities.push_back(new Amenity{ "Kettle", 0.39 });
	amenities.push_back(new Amenity{ "Hair dryer", 1.23 });
	
	return amenities;
}

AmenityFactory::amenityList_t AmenityFactory::createDeluxeRoomAmenity()
{
	auto amenities{ createStandardRoomAmenity() }; // fetch all standard amenities...
	amenities.push_back(new Amenity{ "Soft Mattress", 6.99 });
	amenities.push_back(new Amenity{ "Desk", 7.89 });
	
	return amenities;
}

AmenityFactory::amenityList_t AmenityFactory::createLuxuryRoomAmenity()
{
	auto amenities{ createDeluxeRoomAmenity() };
	amenities.push_back(new Amenity{ "Kitchen", 23.59 });
	amenities.push_back(new Amenity{ "Balcony", 13.99 });
	amenities.push_back(new Amenity{ "Pool-Table", 17.89 });

	return amenities;
}
