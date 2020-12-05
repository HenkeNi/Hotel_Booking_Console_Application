#pragma once
#include "Room.h"
#include "AmenityFactory.h"
#include <memory>

// NOTE: change it back to methods that creates a room with an amenity?? ex: createSingleStandardRoom...

class RoomFactory
{
public:
	using roomPtr_t = std::shared_ptr<Room>;

public:
	static roomPtr_t getRoom(Room::RoomType type, AmenityFactory::amenityList_t amenities);

private:
	static roomPtr_t createSingleRoom(AmenityFactory::amenityList_t amenities);
	static roomPtr_t createDoubleRoom(AmenityFactory::amenityList_t amenities);
	static roomPtr_t createFamilyRoom(AmenityFactory::amenityList_t amenities);
};

