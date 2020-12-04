#include "Date.h"

#include <cassert>


Date::Date(int day, int month, int year)
	: m_day{ day }, m_month{ month }, m_year{ year }
{
	assert(day > 0 && day <= 30 && month > 0 && month <= 12 && year >= 0); // Replace with throw?
}

// overloaded (prefix) increment operator
Date& Date::operator++()
{
	if (m_day >= 30) // if m_day is largen than 30 it wraps around to 1
	{
		m_day = 1;

		if (m_month >= 12) // month also wraps around, if larger than 12
		{
			m_month = 1;
			++m_year;
		}
		else
			++m_month;
	}
	else
		++m_day;

	return *this;
}


// overloading (postfix) increment operator
Date Date::operator++(int)
{
	Date temp{ m_day, m_month, m_year }; // temporary date using the current Date's values

	++(*this); // using the prefix operator to increment the current date

	return temp; // return temporary Date 
}


// overloading comparison operator
bool operator== (const Date& d1, const Date& d2)
{
	return (
		(d1.m_day == d2.m_day) &&
		(d1.m_month == d2.m_month) &&
		(d1.m_year == d2.m_year)
		);
}


// overloading comparison operator (not)
bool operator!= (const Date& d1, const Date& d2)
{
	return !(d1 == d2);
}


std::ostream& operator<< (std::ostream& out, const Date& date)
{
	out << "Day: " << date.m_day << ", month: " << date.m_month << ", year: " << date.m_year << '\n';
	return out;
}