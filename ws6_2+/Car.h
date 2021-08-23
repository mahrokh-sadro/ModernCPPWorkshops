
/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:July 10,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include "Vehicle.h"

namespace sdds {

	class Car:public Vehicle {

		std::string m_maker;
		char m_condition{};
		double m_topSpeed{};//check if its int or double
		char m_tag{};
		std::string ltrim(const std::string& str);
		std::string rtrim(const std::string& str);
		std::string fullTrim(const std::string& str);

	public:
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		virtual ~Car() {};
	
	};


}







#endif
