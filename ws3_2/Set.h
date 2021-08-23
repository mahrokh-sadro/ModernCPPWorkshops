/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:June 13,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/



#ifndef SDDS_SET_H
#define SDDS_SET_H 


namespace sdds {

	template<unsigned N,typename T>
	class Set {
		T m_arr[N]{  };
		unsigned m_currentSize{};
		unsigned m_capacity{50};
		
	public:
	
		size_t size() const {
			return m_currentSize;
		}	
		const T& get(size_t idx) const {
			return m_arr[idx];
		}
	
		void operator+=(const T& item) {
			if (m_currentSize < N && N<m_capacity) {
				m_arr[m_currentSize++] = item;
			}
		}

	};

}
#endif

