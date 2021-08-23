// Workshop 9 - Multi-Threading
// SecureData.cpp

/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:July 30,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/


#include <memory>
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}
	
	void SecureData::code(char key)
	{
		
		vector<thread> threads;
		size_t numOfPortions{ 4 };
		size_t numOfBytes = nbytes / numOfPortions;
		for (size_t i = 0u; i < numOfPortions; i++)
			threads.push_back(thread(bind(   converter,  text+ i * numOfBytes, key, nbytes-i* numOfBytes, Cryptor()  )));
		for (auto& thread : threads) thread.join();


		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			ofstream fout(file, std::ios::out | std::ios::binary);
			fout.write(text, nbytes);
			fout.close();
		}
	}
	
	void SecureData::restore(const char* file, char key) {
		delete[] text;
		ifstream fin(file, std::ios::in | std::ios::binary);
			
	
		size_t numOfChars{};

		fin.seekg(0, std::ios::end);
		numOfChars = (size_t)fin.tellg() + 1;  

		text = new char[numOfChars];

		
		fin.clear();
		fin.seekg(0, std::ios::beg);
		while (fin) fin.read(text, numOfChars); 

		text[numOfChars - 1] = 0;

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}
	

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
