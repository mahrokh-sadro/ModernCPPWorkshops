/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 30,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/



#include <iostream>
#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds {


	std::string  Book::ltrim(const std::string& str)
	{
		std::string ret = str;
		return ret.erase(0, ret.find_first_not_of(' '));
	}

	std::string  Book::rtrim(const std::string& str)
	{
		std::string ret = str;
		return ret.substr(0, ret.find_last_not_of(' ') + 1);
	}

	std::string  Book::fullTrim(const std::string& str)
	{
		std::string ret = str;
		return ltrim(rtrim(ret));
	}



	const std::string& Book::title() const
	{
		return m_title;
	}

	const std::string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}

	Book::Book(const std::string& strBook)//we can use getline too
	{
		string t = strBook;

		t = fullTrim(t);


		m_author = t.substr(0, t.find(','));

		t = t.erase(0, t.find(',') + 1);
		
		t = t.erase(0, t.find_first_not_of(' '));
		
		m_title = rtrim(t.substr(0, t.find(',')));
		
		t = t.erase(0, t.find(',') + 1);
	
		t = t.erase(0, t.find_first_not_of(' '));

		m_country = t.substr(0, t.find(','));

		t = t.erase(0, t.find(',') + 1);

		t = t.erase(0, t.find_first_not_of(' '));
	
		m_price = stod(t.substr(0, t.find(',')));

		t = t.erase(0, t.find(',') + 1);

		t = t.erase(0, t.find_first_not_of(' '));

		m_year = stoi(t.substr(0, t.find(",")));

		t = t.erase(0, t.find(',') + 1);
	
		t = t.erase(0, t.find_first_not_of(' '));

		m_description = t;

	}


	std::ostream& operator<<(std::ostream& os, const Book& n)
	{
		os << setw(20)<<right << n.m_author << " | " <<
			setw(22) << n.m_title << " | " <<
			setw(5) << n.m_country << " | " <<

			setw(4) << n.m_year << " | " <<
			setw(6) << fixed << setprecision(2) << n.m_price << " | " <<
			n.m_description << endl;
	
		return os;
	}

}
