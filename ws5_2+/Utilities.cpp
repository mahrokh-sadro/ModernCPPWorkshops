/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 30,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/



#include "Utilities.h"
namespace sdds {

	std::string  ltrim(const std::string& str)
	{
		std::string ret = str;
		return ret.erase(0, ret.find_first_not_of(' '));
	}

	std::string  rtrim(const std::string& str)
	{
		std::string ret = str;
		return ret.substr(0, ret.find_last_not_of(' ') + 1);
	}

	std::string  fullTrim(const std::string& str)
	{
		std::string ret = str;
		return ltrim(rtrim(ret));
	}
}