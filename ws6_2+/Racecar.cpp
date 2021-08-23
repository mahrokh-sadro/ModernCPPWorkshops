/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:July 10,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/


#include <iostream>
#include <string>
#include "Racecar.h"
using namespace std;
namespace sdds {

	Racecar::Racecar(std::istream& in):Car(in)
	{
		
		string booster;
		getline(in, booster);
		booster.erase(0,booster.find_first_not_of(' '));
		m_booster = stod(booster);

	}

	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		
		out << "*";

	}

	double Racecar::topSpeed() const
	{
		return Car::topSpeed()+ Car::topSpeed()* m_booster;
	}

}