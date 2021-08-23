/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 30,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>

namespace sdds {

	class Book {

		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year{};
		double m_price{};
		std::string m_description;
		std::string  ltrim(const std::string& str);
		std::string  rtrim(const std::string& str);
		std::string  fullTrim(const std::string& str);
		
	public:
	
		Book() { };
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		friend std::ostream& operator<<(std::ostream& os, const Book&);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description);
		}

	};

}

#endif