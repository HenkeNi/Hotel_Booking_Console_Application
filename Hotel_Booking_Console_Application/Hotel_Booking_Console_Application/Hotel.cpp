#include "Hotel.h"
#include "Address.h"
#include "AmenityFactory.h"
#include "RoomFactory.h"

Hotel::Hotel()
{
	initRooms();
	initDetails();
}

Hotel::Hotel(HotelDetails& details, std::vector<Room> rooms)
	: m_details{ std::move(details) }, m_rooms{ std::move(rooms) }
{
}

void Hotel::initRooms()
{
	Room::RoomType type;
	std::vector<std::shared_ptr<Amenity>> amenities;

	for (int i{ 0 }; i <= 249; ++i)
	{
		if (i % 20 == 0) // Luxury (Vip)
		{
			type = Room::RoomType::Family;
			amenities = AmenityFactory::getRoomAmenity(AmenityFactory::AmenityLevel::vip);
		}
		else if (i % 10 == 0) // Deluxe
		{
			type = i % 20 == 0 ? Room::RoomType::Double : Room::RoomType::Family;
			amenities = AmenityFactory::getRoomAmenity(AmenityFactory::AmenityLevel::deluxe);
		}
		else // Standard
		{
			type = i % 2 == 0 ? Room::RoomType::Single : Room::RoomType::Double;
			amenities = AmenityFactory::getRoomAmenity(AmenityFactory::AmenityLevel::standard);
		}
		m_rooms.push_back(*RoomFactory::getRoom(type, amenities));
	}
}

void Hotel::initDetails()
{
	auto address{ std::make_shared<Address>() }; // Keep as shared_ptr??
	address
		->setCountry("United States")
		.setCity("Colorado")
		.setPostalCode("237")
		.setStreetName("Rocky Road")
		.setStreetNumber("37");
		
	HotelDetails details;
	details
		.setHotelName("The Overlook Hotel")
		//.setDistanceToOcean(std::nullopt)
		.setStarRating(3)
		.setContactDetails({ "Overlook@hotel.com", "190 923 71 921", address }) // email, phone, address
		.addAmenity({"Sauna", 0.0})
		.addAmenity({"Labyrinth", 0.0})
		.addAmenity({"Indoor-pool", 0.0 });

	m_details = std::move(details);

}


void Hotel::addRoom(const Room& room)
{
	m_rooms.push_back(room);
	//m_rooms.push_back(std::make_unique<Room>(room));
}

void Hotel::addBooking(const Booking& booking)
{
	m_bookings.push_back(std::move(booking));
}

std::ostream& operator<< (std::ostream& out, const Hotel& hotel)
{
	out << hotel.m_details;
	return out;
}