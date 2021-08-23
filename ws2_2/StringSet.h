/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 5,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

*/


#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

namespace sdds {
	
	class StringSet {

		std::string* m_arrOfStrings{};
		size_t m_numOfStrings{};
	public:

		StringSet();
		StringSet(const char*);
		StringSet(const StringSet&);
		StringSet( StringSet&&);
		StringSet& operator=(const StringSet& );
		StringSet& operator=(StringSet&&);
		virtual ~StringSet();
		size_t size() const;
		std::string operator[](size_t) const;

	};

}
#endif