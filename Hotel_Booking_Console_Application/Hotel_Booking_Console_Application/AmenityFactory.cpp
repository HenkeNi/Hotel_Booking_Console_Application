#include "AmenityFactory.h"
#include <stdexcept>


AmenityFactory::amenityList_t AmenityFactory::getRoomAmenity(AmenityLevel lvl)
{
	switch (lvl)
	{
	case AmenityLevel::standard:
		return createStandardRoomAmenity();
	case AmenityLevel::deluxe:
		return createDeluxeRoomAmenity();
	case AmenityLevel::vip:
		return createLuxuryRoomAmenity();
	default:
		throw std::runtime_error("Invalid AmenityLevel!");
	}
}

AmenityFactory::amenityList_t AmenityFactory::createStandardRoomAmenity()
{
	AmenityFactory::amenityList_t amenities;
	amenities.push_back(std::make_shared<Amenity>("TV", 5.43));
	amenities.push_back(std::make_shared<Amenity>("Kettle", 0.39));
	amenities.push_back(std::make_shared<Amenity>("Hair dryer", 1.23));
	
	return amenities;
}

AmenityFactory::amenityList_t AmenityFactory::createDeluxeRoomAmenity()
{
	auto amenities{ createStandardRoomAmenity() }; // fetch all standard amenities...
	amenities.push_back(std::make_shared<Amenity>("Soft Mattress", 6.99));
	amenities.push_back(std::make_shared<Amenity>("Desk", 7.89));
	
	return amenities;
}

AmenityFactory::amenityList_t AmenityFactory::createLuxuryRoomAmenity()
{
	auto amenities{ createDeluxeRoomAmenity() };
	amenities.push_back(std::make_shared<Amenity>("Kitchen", 23.59));
	amenities.push_back(std::make_shared<Amenity>("Balcony", 13.99));
	amenities.push_back(std::make_shared<Amenity>("Pool-Table", 17.89));

	return amenities;
}
