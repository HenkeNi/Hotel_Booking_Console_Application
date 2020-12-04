#pragma once
#include "Booking.h"
#include "HotelDetails.h"
#include "Room.h"

#include <memory>
#include <vector>

class Hotel
{
public:
	using roomList_t = std::vector<std::unique_ptr<Room>>;
	using bookingList_t = std::vector<Booking>;
	//using employeeList_t = std::vector<Employee>;

public:
	Hotel(HotelDetails& details);

	void addRoom(const Room& room);
	void addBooking(const Booking& booking);
	//void addStaff(const Employee& e);


	void sortBookings();
	void showBookedDates(); // put in hotel?
	double getPriceForBooking(); // PUT IN HOTEL?

private:
	HotelDetails   m_details;
	roomList_t	   m_rooms;
	bookingList_t  m_bookings;
	//employeeList_t m_employees;
};

