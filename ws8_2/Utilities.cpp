/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:July 21,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/



// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* ptr = new Product(desc[i].desc, price[j].price);
					try {
						ptr->validate();
					}
					catch (const std::string& msg) {
						Product::Trace = false;
						delete ptr;
						Product::Trace = true;
						throw; 
					}
					priceList += ptr;
					delete ptr;
				}
			}

		}
		return priceList;

	}
	
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t n = 0; n < price.size(); n++) {
				if (desc[i].code == price[n].code) {
					std::unique_ptr<Product> ptr(new
						Product(desc[i].desc, price[n].price));
					ptr->validate();
					priceList += ptr;
				}
			}
		}
		return priceList;
	}
}