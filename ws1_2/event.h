/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:May 30,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

*/


#ifndef SDDS_EVENT_H_
#define SDDS_EVENT_H_

//#include <iostream>
extern unsigned int g_sysClock;

namespace sdds
{

	class Event
	{
		char* m_discript{};
		unsigned int m_seconds{};
		void setEmpty();

	public:
		Event();
		Event(const Event&);
		Event& operator=(const Event&);
		std::ostream& display(std::ostream& os=std::cout)const;
		void set(const char* sdesc=nullptr);
		virtual ~Event();
	};
}


#endif //!SDDS_EVENT_H_