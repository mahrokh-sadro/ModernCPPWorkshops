/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:July 10,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"
namespace sdds {

	class Racecar :public Car {
		double m_booster{};//percentage between 0 n 1

	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
		virtual ~Racecar() {};
	};


}
#endif