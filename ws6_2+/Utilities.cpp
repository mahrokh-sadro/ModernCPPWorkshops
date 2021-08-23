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
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"
using namespace std;
namespace sdds {

	

	Vehicle* createInstance(std::istream& in)
	{
		
		Vehicle* vehic{};
		string str;
		getline(in, str);
		 str.erase(0, str.find_first_not_of(' '));
		 std::stringstream ss(str);
		 if (str[0]) {
			 if (str[0] == 'c' || str[0] == 'C') {
				 vehic = new Car(ss);
			 }
			 else  if (str[0] == 'r' || str[0] == 'R') {
				 vehic = new Racecar(ss);
			 }
			 else {
				 string  ch = str.substr(0,1);
				 string err=  "Unrecognized record type: [" +ch +"]";
				throw err;
			 }
		 }

		return vehic;

	}

}
