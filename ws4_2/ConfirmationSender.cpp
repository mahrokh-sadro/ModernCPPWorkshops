
#include <iostream>
#include <cstring>
#include "ConfirmationSender.h"
#include "Restaurant.h"
using namespace std;
namespace sdds {

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& N)
	{
		*this = N;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& N)noexcept
	{
		*this = move(N);
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& N)
	{
		if (N.size() && this != &N) {
			delete[] m_arrOfReservPointer;//*m_arrOfReservation;?
			m_sizeOfArrOfPonters = N.m_sizeOfArrOfPonters;
			m_arrOfReservPointer = new const Reservation * [m_sizeOfArrOfPonters];
			for (size_t i = 0u; i < m_sizeOfArrOfPonters; i++)
				m_arrOfReservPointer[i] = N.m_arrOfReservPointer[i];
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& N)noexcept
	{
		if (N.size() && this != &N) {
			delete[] m_arrOfReservPointer;
			m_arrOfReservPointer = N.m_arrOfReservPointer;
			N.m_arrOfReservPointer = nullptr;

			m_sizeOfArrOfPonters = N.m_sizeOfArrOfPonters;
			N.m_sizeOfArrOfPonters = 0;
		}

		return *this;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		//for(auto& elem: )

		//for (size_t i = 0u; i < size(); i++) delete[] m_arrOfReservPointer[i];
		delete[] m_arrOfReservPointer;
	}

	size_t ConfirmationSender::size() const
	{
		return m_sizeOfArrOfPonters;
	}
	
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		
		bool found = false;
		size_t i = 0;
		for ( i = 0; i < size() && !found; i++ )
		{
			if (m_arrOfReservPointer[i] == &res)
			{
				found = true;
			}
		} if (!found)
		{
			const Reservation** temp = new const Reservation * [size()+1];
			for ( i = 0;i<size() ; i++)
			{
				temp[i] = m_arrOfReservPointer[i];
			}
			temp[size()] = &res;
			m_sizeOfArrOfPonters++;
			delete[] m_arrOfReservPointer;	
			m_arrOfReservPointer = temp;
		}
		return *this;

	}


	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		
		bool found = false;
		size_t i;
		for (i = 0; i < size() && !found; i++)
			if (m_arrOfReservPointer[i] == &res)
			found = true;
		if (found) {
			for (; i < size(); i++)
				m_arrOfReservPointer[i - 1] = m_arrOfReservPointer[i];
			if (size()) {
				m_arrOfReservPointer[size() - 1] = nullptr;
				m_sizeOfArrOfPonters--;
			}
		}


		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& N)
	{

		if (!N.size())
		{

			os << "--------------------------" << endl
				<< "Confirmations to Send" << endl
				<< "--------------------------" << endl
				<< "There are no confirmations to send!" << endl
				<< "--------------------------" << endl;
		}
		else
		{
			os << "--------------------------" << endl
				<< "Confirmations to Send" << endl
				<< "--------------------------" << endl;
			for (size_t i = 0u; i < N.size(); i++)
				cout << *N.m_arrOfReservPointer[i];
			os << "--------------------------" << endl;
			
		}
		return os;

	}

}

