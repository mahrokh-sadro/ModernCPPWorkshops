/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 20,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds {

	class ConfirmationSender{

		const Reservation** m_arrOfReservPointer{};
		size_t m_sizeOfArrOfPonters{}; 
	public:
		ConfirmationSender() {};
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&) noexcept;
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender& operator=(ConfirmationSender&&)noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		virtual ~ConfirmationSender();
		size_t size() const;

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender&);

	};
}

#endif
