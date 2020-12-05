#include "Room.h"

#include <iostream>
#include <stdexcept>

int Room::s_idGenerator{ 1 };

Room::Room(RoomType type)
	: m_roomType{ type }
{
	m_roomNumber = s_idGenerator++; // assign current value of s_idGenerator, then increment generator
}


Room::Room(const Room& room)
	: m_roomType{ room.m_roomType }, 
	m_amenities{ std::move(room.m_amenities) },
	m_bookedDates{ std::move(room.m_bookedDates) },
	m_roomNumber{ room.m_roomNumber }
{
	s_idGenerator = room.s_idGenerator;
}


void Room::setRoomType(const RoomType& type)
{
	m_roomType = type;
}


void Room::addAmenity(const Amenity& amenity)
{
	m_amenities.push_back(amenity);
}


void Room::addBooking(Date& startDate, int duration)
{
	if (checkIfBooked(startDate, duration))
		throw std::runtime_error("Booking Failed - one or more selected dates already booked!\n");

	for (int i{ 0 }; i < duration; ++i)
		m_bookedDates.push_back(startDate++);
}


bool Room::checkIfBooked(Date& startDate, int duration) const
{
	if (m_bookedDates.empty())
		return false;

	bool bookingFailed{ false };

	// iterate through all the days
	for (int i{ 0 }; i < duration; ++i)
	{
		auto foundDate = std::find(m_bookedDates.begin(), m_bookedDates.end(), startDate++); // search m_bookedDates for similar dates
		
		// if date already exist
		if (foundDate != m_bookedDates.end())
		{
			printBookedDate(*foundDate);
			bookingFailed = true;
		}
	}
	return bookingFailed;
}


void Room::printBookedDate(const Date& date) const
{
	std::cout << date << " - date is already booked!\n";
}


std::ostream& operator<< (std::ostream& out, const Room& room)
{
	switch (room.m_roomType)
	{
	case Room::Single:
		out << "Single Bedroom";
		break;
	case Room::Double:
		out << "Double Bedroom";
		break;
	case Room::Family:
		out << "Family Sized Bedroom";	
		break;
	}

	out << "\n\tincludes: ";

	for (const auto& amenity : room.m_amenities)
		out << amenity;

	return out;
}