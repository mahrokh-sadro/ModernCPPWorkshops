/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 20,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Restaurant.h"

using namespace std;
namespace sdds {


	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		if (reservations && cnt) {
			m_noOfReservObj = cnt;
			m_arrOfReservObj = new  Reservation[m_noOfReservObj];
			for (size_t i = 0u; i < m_noOfReservObj; i++) {
				m_arrOfReservObj[i] = *reservations[i];
			}
		}
		
	}

	Restaurant::Restaurant(const Restaurant& N)
	{
		*this = N;
	}

	Restaurant::Restaurant(Restaurant&& N)noexcept
	{
		*this = move(N);
	}

	Restaurant& Restaurant::operator=(const Restaurant& N)
	{
		if (N.size() && this != &N) {
			delete[] m_arrOfReservObj;
			m_noOfReservObj = N.m_noOfReservObj;
			m_arrOfReservObj = new Reservation[m_noOfReservObj];
			for (size_t i = 0u; i < m_noOfReservObj; i++)
				m_arrOfReservObj[i] = N.m_arrOfReservObj[i];
		}

		return *this;
	}



	Restaurant& Restaurant::operator=(Restaurant&& N)noexcept
	{
		if (N.size() && this != &N) {
			delete[] m_arrOfReservObj;
			m_arrOfReservObj = N.m_arrOfReservObj;
			N.m_arrOfReservObj = nullptr;

			m_noOfReservObj = N.m_noOfReservObj;
			N.m_noOfReservObj = 0;
		}

		return *this;
	}

	Restaurant::~Restaurant()
	{

		delete[] m_arrOfReservObj;
	}

	size_t Restaurant::size() const
	{
		return m_noOfReservObj;
	}



	std::ostream& operator<<(std::ostream& os, const Restaurant& N)
	{
		static unsigned CALL_CNT{ 1 };
		if (N.m_noOfReservObj) {
			os << "--------------------------" << endl
				<< "Fancy Restaurant (" << CALL_CNT << ")" << endl
				<< "--------------------------" << endl;
			for (size_t i = 0u; i < N.m_noOfReservObj; i++) cout << N.m_arrOfReservObj[i];
			os << "--------------------------" << endl;
			CALL_CNT++;
		}
		else
		{
			os << "--------------------------" << endl
				<< "Fancy Restaurant (" << CALL_CNT << ")" << endl
				<< "--------------------------" << endl
				<< "This restaurant is empty!" << endl
				<< "--------------------------" << endl;
			CALL_CNT++;
			
		}

		return os;
	}

}