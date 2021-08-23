/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:July 10,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#include <string>
#include <iostream>
#include <iomanip>
#include "Car.h"

using namespace std;
namespace sdds {

	std::string Car::ltrim(const std::string& str)
	{
		std::string ret = str;
		return ret.erase(0, ret.find_first_not_of(' '));
	}

	std::string  Car::rtrim(const std::string& str)
	{
		std::string ret = str;
		return ret.substr(0, ret.find_last_not_of(' ') + 1);
	}

	std::string  Car::fullTrim(const std::string& str)
	{
		std::string ret = str;
		return ltrim(rtrim(ret));
	}
	
	Car::Car(std::istream& is)
	{


		string tag;
		string maker;
		string condition;
		string speed;

		getline(is, tag, ',');
		getline(is, maker, ',');
		getline(is, condition, ',');
		getline(is, speed,',');

		tag = fullTrim(tag);
		m_tag = tag[0];
	
		maker = fullTrim(maker);
		m_maker = maker;
		
		condition = fullTrim(condition);

		if (condition.size() == 0 || condition[0]==' ') m_condition = 'n';
		else if (condition[0] == 'n' || condition[0] == 'u' || condition[0] == 'b') m_condition = condition[0];
		else throw string("Invalid record!");
		
		speed = fullTrim(speed);
		try {
			m_topSpeed = stod(speed);
		}

		catch (const std::invalid_argument& ) {
			throw string("Invalid record!");
			
		}

	}

	std::string Car::condition() const
	{
		string ret;
		if (m_condition == 'n') ret = "new";
		else if (m_condition == 'u') ret = "used";
		else if (m_condition == 'b') ret = "broken";
		return ret;
	}

	double Car::topSpeed() const
	{
		return m_topSpeed;
	}
	
	void Car::display(std::ostream& out) const
	{
		
		out << "| " << setw(10) << right << m_maker
			<< " | " << setw(6) << left << condition()
			<< " | " << setw(6) << fixed << setprecision(2) << topSpeed()
			<< " |";
			
	}

}
