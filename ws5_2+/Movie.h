/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 30,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/





#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include "SpellChecker.h"

namespace sdds {
	class Movie {
		std::string m_title{};
		size_t m_year{};
		std::string m_description{};
		std::string  ltrim(const std::string& str);
		std::string  rtrim(const std::string& str);
		std::string  fullTrim(const std::string& str);
	
	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
		friend 	std::ostream& operator<<(std::ostream& os, const Movie& src);
	};
}
#endif