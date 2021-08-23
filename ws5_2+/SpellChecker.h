/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 30,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/



#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>

constexpr size_t m_size = 6u;
namespace sdds {
	class SpellChecker {
		std::string m_badWords[m_size];
		std::string m_goodWords[m_size];
	    size_t m_count[m_size]{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out);
	};
}
#endif

