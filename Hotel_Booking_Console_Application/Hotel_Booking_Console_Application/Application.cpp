#include "Application.h"
#include <iostream>

// Design Choice: Having an hotel class that contains heap allocated Room(s) or an heap allocated hotel that contains room by value??

// TODO: Check if setters should have move semantics - maybe have extra methods for r-values?? - &&

#include "Room.h"
#include "Amenity.h"
#include "AmenityFactory.h"
#include "RoomFactory.h"
#include "Hotel.h"
void Application::run()
{
	std::cout << "Start";
	Hotel hotel{};
	std::cout << hotel;

	//std::cout << "Start" << std::endl;

	//auto standardAmenity = AmenityFactory::getRoomAmenity(AmenityFactory::AmenityLevel::standard);
	//auto deluxeAmenity = AmenityFactory::getRoomAmenity(AmenityFactory::AmenityLevel::deluxe);
	//auto luxuryAmenity = AmenityFactory::getRoomAmenity(AmenityFactory::AmenityLevel::vip);

	//std::vector<Room> rooms;

	//for (int i{ 0 }; i < 10; ++i)
	//{
	//	Room room = *RoomFactory::getRoom(Room::RoomType::Single, standardAmenity);
	//	rooms.push_back(room);
	//}


	//for (const auto& room : rooms)
	//	std::cout << room;






	
	while (true)
	{

	}
}