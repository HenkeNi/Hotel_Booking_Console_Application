#pragma once
#include <iostream>

class Date
{
public:
	Date(int day, int month, int year);

	// overloading operators
	Date& operator++ ();	// ++ prefix (++Date)
	Date operator++ (int);	// ++ postfix (Date++)

	friend bool operator== (const Date& d1, const Date& d2);
	friend bool operator!= (const Date& d1, const Date& d2);
	friend std::ostream& operator<< (std::ostream& out, const Date& date);

private:
	int m_day;
	int m_month;
	int m_year;
};

