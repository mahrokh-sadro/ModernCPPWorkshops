/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 13,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H


#include <iostream>
#include <iomanip>
#include "Pair.h"


namespace sdds {
	template<typename V,typename K>
	class PairSummable :public Pair<V, K> {

		static V m_initial;
		static size_t m_minFeildWidth;
	public:
		PairSummable() {};
		PairSummable( const K& key, const V& value= m_initial) :Pair<V, K >(key,value)
		{
			if (key.size() > m_minFeildWidth)   m_minFeildWidth= key.size();
		}
		bool isCompatibleWith(const PairSummable<V,K>& b) const {

			return this->key() == b.key();
		}
		PairSummable<V, K>& operator+=(const PairSummable<V, K>& obj){
			*this = PairSummable(obj.key(), this->value()+obj.value());
			return *this;
		}
		void display(std::ostream& os) const {
			os <<std::setw(m_minFeildWidth)<<std::left;
			Pair<V, K>::display(os); 
			os<< std::right;
		}
	};
	template<typename V, typename K>
	size_t PairSummable<V, K>::m_minFeildWidth = 0;

	template<typename V, typename K>
	V PairSummable<V, K>::m_initial{};

	template <>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& obj) {

		if(this->value().length()) *this = PairSummable(obj.key(), this->value()+ ", " + obj.value());
		else  *this = PairSummable(obj.key(),obj.value());
		return *this;
	}
}
#endif