/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 5,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

*/


#include <iostream>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;

namespace sdds {


	TimedEvents::TimedEvents(){}

	void TimedEvents::startClock()
	{
		m_start= chrono::steady_clock::now();	
	}
	
	void TimedEvents::stopClock()
	{
		m_stop= chrono::steady_clock::now();	
	}

	TimedEvents& TimedEvents::addEvent(const char* eventName)
	{
		if (m_numOfEvents < m_maxNumEventObjs) {
			events[m_numOfEvents].m_eventName = string(eventName);
			events[m_numOfEvents].m_unitsOfTime = "nanoseconds";
			events[m_numOfEvents].m_duration = chrono::duration_cast<chrono::nanoseconds>(m_stop - m_start);
			m_numOfEvents++;
		}
		return *this;
	}

	ostream& operator<<(std::ostream& os, const TimedEvents& obj)
	{
		os << "--------------------------" << endl
			<< "Execution Times:" << endl
			<< "--------------------------" << endl;
		
		for (unsigned i = 0; i <obj.m_numOfEvents; i++) {
			os << setw(21)<< left << obj.events[i].m_eventName << " "
				<< setw(13)<<right << obj.events[i].m_duration.count() <<" "
				<<obj.events[i].m_unitsOfTime << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
}