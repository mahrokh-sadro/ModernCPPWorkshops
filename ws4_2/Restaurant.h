/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 20,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"

namespace sdds {

	//rule of 5
	class Restaurant {
		Reservation* m_arrOfReservObj{};
		size_t  m_noOfReservObj{};
		
	public:

		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant&);
		Restaurant(Restaurant&&) noexcept;
		Restaurant& operator=(const Restaurant&);
		Restaurant& operator=(Restaurant&&)noexcept;
		virtual ~Restaurant();


		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant&);
	};

}

#endif