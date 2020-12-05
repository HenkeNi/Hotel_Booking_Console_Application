#pragma once

#include "Amenity.h"
#include <memory>
#include <vector>

class AmenityFactory
{
public:
	using amenityList_t = std::vector<std::shared_ptr<Amenity>>;

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

