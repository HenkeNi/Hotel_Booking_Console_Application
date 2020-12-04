#pragma once

#include "Amenity.h"
#include <vector>

class AmenityFactory
{
public:
	using amenityList_t = std::vector<Amenity*>;

	enum class AmenityLevel
	{
		standard,
		deluxe,
		vip
	};

public:
	static amenityList_t getRoomAmenity(AmenityLevel lvl);

private:
	static amenityList_t createStandardRoomAmenity();
	static amenityList_t createDeluxeRoomAmenity();
	static amenityList_t createLuxuryRoomAmenity();
};

