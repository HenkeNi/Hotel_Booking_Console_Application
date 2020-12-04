#pragma once
#include "Amenity.h"
#include "Date.h"

#include <vector>

class Room
{
public:
	using amenityList_t = std::vector<Amenity>;
	using bookedDates_t = std::vector<Date>;

	enum RoomType
	{
		Single = 1,
		Double = 2,
		Family = 4
	};

public:
	Room();
	
	void setRoomType(const RoomType& type);
	void addAmenity(const Amenity& amenity);
	void addBooking(Date& startDate, int duration);

	bool checkIfBooked(Date& startDate, int duration) const;
	void printBookedDate(const Date& date) const;

	friend std::ostream& operator<< (std::ostream& out, const Room& room);

private:
	RoomType	  m_roomType;
	amenityList_t m_amenities;
	bookedDates_t m_bookedDates;

	static int	  s_idGenerator;
	int			  m_roomNumber;

};

