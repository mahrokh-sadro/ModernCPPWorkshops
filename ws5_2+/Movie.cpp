/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 30,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/


#include <iomanip>
#include "Movie.h"


using namespace std;
namespace sdds {


	std::string  Movie::ltrim(const std::string& str)
	{
		std::string ret = str;
		return ret.erase(0, ret.find_first_not_of(' '));
	}

	std::string  Movie::rtrim(const std::string& str)
	{
		std::string ret = str;
		return ret.substr(0, ret.find_last_not_of(' ') + 1);
	}

	std::string  Movie::fullTrim(const std::string& str)
	{
		std::string ret = str;
		return ltrim(rtrim(ret));
	}



	const string& Movie::title() const {
		return m_title;
	}

	Movie::Movie(const string& strMovie) {

		string str = strMovie;
		str = fullTrim(str);

		m_title = rtrim(str.substr(0, str.find(',')));

		str = ltrim(str.erase(0, str.find(',') + 1));

		m_year = stoi(rtrim(str.substr(0, str.find(','))));

		str = str.erase(0, str.find(',') + 1);

		str = fullTrim(str);

		m_description = str;
	
	}

	ostream& operator<<(ostream& os, const Movie& n) {
		os << setw(40) << right << n.m_title << " | ";
		os << setw(4) << n.m_year << " | ";
		os << left << n.m_description << endl;
		
		return os;
	}
}