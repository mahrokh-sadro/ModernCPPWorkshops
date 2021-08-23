/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 30,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/



#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>

namespace sdds {
	template <typename T>
	class Collection {
		
		T* m_arrOfObj{};
		size_t m_sizeOfArr{};
		std::string m_nameOfCollection;
		void (*m_observer)(const Collection<T>&, const T&) {};
	public:
		T* arr() const {
			return m_arrOfObj
				;
		}
		Collection(const std::string& name) {
			m_nameOfCollection = name;
			m_arrOfObj = nullptr;
			m_sizeOfArr = 0;
			m_observer = nullptr;
		}

		~Collection() {
			delete[] m_arrOfObj;
		
		}

		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		Collection(Collection&& n) {
			*this = move(n);
		}
		Collection& operator=(Collection&& n) {
			m_sizeOfArr = n.m_sizeOfArr;
			n.m_sizeOfArr = 0u;
			m_nameOfCollection = n.m_nameOfCollection;
			n.m_nameOfCollection = "";
			m_observer = n.m_observer;
			n.m_observer = nullptr;
			m_arrOfObj = n.m_arrOfObj;
			n.m_arrOfObj = nullptr;
		}



		const std::string& name() const {
			return m_nameOfCollection;
		}

		size_t size() const {
			return m_sizeOfArr;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool exists = false;

			for (auto i = 0u; i < m_sizeOfArr; i++) {
				if (m_arrOfObj[i].title() == item.title()) {
					exists = true;
				}
			}
			if (!exists) {
			
				size_t i = 0u;
					T* temp = new T[m_sizeOfArr+1];
					for ( i = 0; i < m_sizeOfArr; ++i) {
						temp[i] = m_arrOfObj[i];
					}

					temp[i] = item;
					delete[] m_arrOfObj;
					m_sizeOfArr++;
					m_arrOfObj = temp;
					if (m_observer) {
						m_observer(*this, item);
					}
					
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= m_sizeOfArr || idx < 0) {
				std::string exception = { "Bad index [" + std::to_string(idx) + "]. " + "Collection has [" + std::to_string(m_sizeOfArr) + "] items." };
				throw 	std::out_of_range(exception);
			}
			else {
				return m_arrOfObj[idx];
			}
		}

		T* operator[](std::string title) const {
			T* ret{};
			for (auto i = 1u; i < size(); i++)
				if (m_arrOfObj[i].title() == title) ret = &m_arrOfObj[i];
			return ret;
		}

		/*friend 	std::ostream& operator<<(std::ostream& os, Collection& n) {
			for (auto i = 0u; i < n.size(); ++i) {
				os << n.m_arrOfObj[i];
			}
			return os;
		}*/
	};
	template <typename T>
	 	std::ostream& operator<<(std::ostream& os, Collection<T>& n) {
		for (auto i = 0u; i < n.size(); ++i) {
			os << n[i];
		}
		return os;
	}
}
#endif