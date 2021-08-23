/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 20,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>


#include "Reservation.h"

using namespace std;
namespace sdds {



	Reservation::Reservation() {};

	Reservation::Reservation(const std::string& res)
	{
		string s = res;
        string id = s.substr(0, s.find(':'));
        id = trim(id);
		m_reservationId = new char[id.length() + 1];
		strcpy(m_reservationId, id.c_str());
        s = s.erase(0, s.find(':') + 1);
        string name = s.substr(0, s.find(','));
        name = trim(name);
        strcpy(m_name, name.c_str());
        s = s.erase(0, s.find(',') + 1);      
        string email = s.substr(0, s.find(","));
        email = trim(email);                              
		m_email = email;
        s = s.erase(0, s.find(",") + 1);
        m_numOfPpl = stoi(s.substr(0, s.find(",")));
        s = s.erase(0, s.find(",") + 1);
        m_day = stoi(s.substr(0, s.find(",")));
        s = s.erase(0, s.find(",") + 1);
        m_startHour = stoi(s);
	}

	Reservation::Reservation(const Reservation& N)
	{
		*this = N;
	}

	Reservation::Reservation(Reservation&& N)noexcept
	{
		*this = move(N);
	}

	Reservation& Reservation::operator=(const Reservation& N)
	{
		if (N.m_reservationId) {
			if (this != &N) {

				delete[] m_reservationId;
				strcpy(m_name, N.m_name);
				m_email = N.m_email;
				m_numOfPpl = N.m_numOfPpl;
				m_day = N.m_day;
				m_startHour = N.m_startHour;

				m_reservationId = new char[strlen(N.m_reservationId) + 1];
				strcpy(m_reservationId, N.m_reservationId);


			}
		}
		return *this;
	}

	Reservation& Reservation::operator=(Reservation&& N)noexcept
	{
		if (N.m_reservationId) {
			if (this != &N) {
				delete[] m_reservationId;
				m_reservationId = N.m_reservationId;
				N.m_reservationId = nullptr;

				strcpy(m_name, N.m_name);
				m_email = N.m_email;
				m_numOfPpl = N.m_numOfPpl;
				m_day = N.m_day;
				m_startHour = N.m_startHour;

				N.m_name[0] = 0;
				N.m_email = "";
				N.m_numOfPpl = 0;
				N.m_day = 0;
				N.m_startHour = 0;

			}
		}
		return *this;
	}

	Reservation::~Reservation()
	{
		delete[] m_reservationId;

	}

	std::ostream& operator<<(std::ostream& os, const Reservation& obj)
	{
		
	
		os << "Reservation "<< setw(10) << right <<obj.m_reservationId << ": " << setw(20)
			<< right << obj.m_name << setw(26) << left << "  <"+ obj.m_email+"> ";
			
		     if (6 <= obj.m_startHour && obj.m_startHour <= 9) os << "Breakfast";
			else if(11 <= obj.m_startHour && obj.m_startHour <= 15)  os << "Lunch";
			else if(17 <= obj.m_startHour && obj.m_startHour <= 21)  os << "Dinner";
			else  os << "Drinks";	
			os<<" on day "
			<< obj.m_day << " @ " << obj.m_startHour << ":00 " << "for "
			<< obj.m_numOfPpl  <<(obj.m_numOfPpl > 1 ? " people." : " person.") << endl;

		return os;
	}

}

