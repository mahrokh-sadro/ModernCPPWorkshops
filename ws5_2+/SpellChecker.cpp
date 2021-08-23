/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 30,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/



#include <fstream>					
#include <iostream>
#include <iomanip>
#include "SpellChecker.h"
using namespace std;
namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			string str;
			size_t i{};
			while (file && i < m_size) {
				getline(file, m_badWords[i], ' ');
				m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' '));
				m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);
				getline(file, m_goodWords[i]);
				m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
				m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
				i++;
			}
			
		}
	}

	void SpellChecker::operator()(string& text) {
		for (auto i = 0u; i < m_size; i++) {
			while (text.find(m_badWords[i]) != string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				m_count[i]++;
			}
		}
	}

	void SpellChecker::showStatistics(ostream& out) {
		cout << "Spellchecker Statistics" << endl;
		for (auto i= 0u; i < m_size; i++) {
			out << setw(15) << right << m_badWords[i] << ": " << m_count[i] << " replacements" << endl;
		}
	}
}





