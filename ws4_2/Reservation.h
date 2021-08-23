/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 20,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

namespace sdds {
	
	
	class Reservation{

		char* m_reservationId{};	
		char m_name[256]{};
		std::string m_email;
		unsigned short int m_numOfPpl{};// in the party
		unsigned short int m_day{};	//integer between 1 and 28
		unsigned short int m_startHour{};//integer between 1 and 24

		std::string ltrim(const std::string& s)
		{
			size_t start = s.find_first_not_of(' ');
			return (start == std::string::npos) ? "" : s.substr(start);
		}
		std::string rtrim(const std::string& s)
		{
			size_t end = s.find_last_not_of(' ');
			return (end == std::string::npos) ? "" : s.substr(0, end + 1);
		}

		std::string trim(const std::string& s) {
			return rtrim(ltrim(s));
		}
	public:

		Reservation();
		Reservation(const std::string& res);
		Reservation(const Reservation&);
		Reservation(Reservation&&)noexcept;
		Reservation& operator=(const Reservation&);
		Reservation& operator=(Reservation&&)noexcept;
		virtual ~Reservation();
		friend 	std::ostream& operator<<(std::ostream& os, const Reservation&);

	};


	
}



#endif
