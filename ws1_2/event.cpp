/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:May 30,2021
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

using namespace std;
unsigned int g_sysClock = 0; 

namespace sdds
{

	Event::Event() {
		setEmpty();
	}

	Event::Event(const Event& N) {
		*this = N;
	}

	Event& Event::operator=(const Event& N) {
		if (this != &N) {

			delete[] m_discript;		
			if (N.m_discript && N.m_discript[0]) {
				m_discript = new char[strlen(N.m_discript) + 1];
				strcpy(m_discript, N.m_discript);
				m_seconds = N.m_seconds;
			}
		}
		return *this;
	}

	void Event::setEmpty() {

		m_discript = nullptr;
		m_seconds = 0;
	}

	void Event::set(const char* sdesc) {

		delete[] m_discript;
		if (sdesc  && sdesc[0] ) {
			
			m_discript = new char[strlen(sdesc) + 1];
			strcpy(m_discript, sdesc);
			m_seconds = g_sysClock;
		}
		else {
			setEmpty();
		}
	}

	ostream& Event::display(ostream& os) const {
		static unsigned short counter = 1;
				
			if (m_discript &&  m_discript[0]){
				os << setw(2) << setfill(' ')<<counter++ << ". " <<setw(2)<<setfill('0')
					<< m_seconds / 3600 << ":" << setw(2)
					<< (m_seconds % 3600) / 60
					<< ":" << setw(2) << (m_seconds % 3600) % 60 << " => " << m_discript << endl;	
			}
			else{
				os << setw(2) << setfill(' ') << counter++ << ". | No Event |" << endl;
					
			}
			return os;
	}

	Event::~Event() {
		delete[] m_discript;
	}
}

