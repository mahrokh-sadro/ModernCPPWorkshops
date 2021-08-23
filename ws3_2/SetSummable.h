/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 13,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include <iostream>
#include "Set.h"


 namespace sdds{ 

	 template<unsigned N, typename T>
	class SetSummable:public Set<N,T> {
	
	public:
	
		T accumulate(const std::string& filter) const {
			T temp(filter);

			for (size_t i = 0; i<this->size(); i++) {
				if (temp.isCompatibleWith(this->get(i)) == true)
					temp += this->get(i);
			}
			return temp;
		}	
	 };
 }
#endif
