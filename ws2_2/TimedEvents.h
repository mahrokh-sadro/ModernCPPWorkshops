/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 5,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

*/


#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <chrono>

constexpr unsigned m_maxNumEventObjs = 10;

namespace sdds {

	class TimedEvents {
				
		unsigned  m_numOfEvents{};
		std::chrono::steady_clock::time_point m_start{};
		std::chrono::steady_clock::time_point m_stop{};
	
		struct Event {
			std::string m_eventName{};
			std::string m_unitsOfTime{};
			std::chrono::steady_clock::duration m_duration{};

		}events[m_maxNumEventObjs];

	public:
		TimedEvents();
		void startClock();
		void stopClock(); 
		TimedEvents& addEvent(const char* eventName);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& obj);

	};
}
#endif