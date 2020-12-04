#include "Hotel.h"


Hotel::Hotel(HotelDetails& details)
	: m_details{ std::move(details) }
{
}


void Hotel::addRoom(const Room& room)
{
	m_rooms.push_back(std::make_unique<Room>(room));
}

void Hotel::addBooking(const Booking& booking)
{
	m_bookings.push_back(std::move(booking));
}
