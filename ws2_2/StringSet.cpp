/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 5,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

*/

#include <iostream>
#include <string>
#include <fstream>

#include "StringSet.h"

using namespace std;
namespace sdds {

	

	StringSet::StringSet(){}	
	StringSet::StringSet(const char* filename)
	{

		ifstream fin(filename);
		string str;
		while (getline(fin, str, ' ')) m_numOfStrings++;//why fin>>str doesnt work properly?
		m_arrOfStrings = new string[m_numOfStrings];
	
		fin.clear();
		fin.seekg(ios::beg);
		for (unsigned int i = 0; i < m_numOfStrings; ++i) {
			getline(fin, m_arrOfStrings[i], ' ');
		}
	}

	StringSet::StringSet(const StringSet& N)
	{
		*this = N;
	}

	StringSet::StringSet(StringSet&& N) 
	{
		*this = move(N);
	}

	StringSet& StringSet::operator=(const StringSet& N)
	{
		if (this != &N) {
			delete[] m_arrOfStrings;
			m_numOfStrings = N.size();
			m_arrOfStrings =new string[m_numOfStrings];
			
			for (unsigned i = 0; i < m_numOfStrings; i++) 
				m_arrOfStrings[i] = N.m_arrOfStrings[i];
		}
		return *this;
	}

	StringSet& StringSet::operator=(StringSet&& N) 
	{
		if (this != &N) {
			delete[] m_arrOfStrings;
			m_arrOfStrings = N.m_arrOfStrings;
			N.m_arrOfStrings = nullptr;
			m_numOfStrings = N.m_numOfStrings;
			N.m_numOfStrings = 0;
		}
		return *this;
	}

	StringSet::~StringSet()
	{
		delete[] m_arrOfStrings;
	}
	
	size_t StringSet::size() const
	{
		return m_numOfStrings;
	}


	string StringSet::operator[](size_t index) const
	{
		return index>=0 && index<m_numOfStrings? m_arrOfStrings[index]:"";
	}
}