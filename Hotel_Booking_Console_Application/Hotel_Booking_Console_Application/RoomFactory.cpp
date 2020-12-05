#include "RoomFactory.h"


RoomFactory::roomPtr_t RoomFactory::getRoom(Room::RoomType type, AmenityFactory::amenityList_t amenities)
{
	switch (type)
	{
	case Room::Single:
		return createSingleRoom(amenities);
	case Room::Double:
		return createDoubleRoom(amenities);
	case Room::Family:
		return createFamilyRoom(amenities);
	default:
		throw std::runtime_error("Invalid room type");
	}
}

RoomFactory::roomPtr_t RoomFactory::createSingleRoom(AmenityFactory::amenityList_t amenities)
{
	auto room{ std::make_unique<Room>(Room::RoomType::Single) };

	for (auto& amenity : amenities)
		room->addAmenity(*amenity);

	return room;
}

RoomFactory::roomPtr_t RoomFactory::createDoubleRoom(AmenityFactory::amenityList_t amenities)
{
	auto room{ std::make_unique<Room>(Room::RoomType::Double) };

	for (auto amenity : amenities)
		room->addAmenity(*amenity);

	return room;
}

RoomFactory::roomPtr_t RoomFactory::createFamilyRoom(AmenityFactory::amenityList_t amenities)
{
	auto room{ std::make_unique<Room>(Room::RoomType::Single) };
	
	for (auto amenity : amenities)
		room->addAmenity(*amenity);

	return room;
}