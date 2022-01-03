#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <string>
#include <stdexcept>

template<typename T>
class Array {
public:
	Array() : m_size(0), m_array(NULL) {}
	Array(unsigned int n) : m_size(n), m_array(new T[n]) {}
	Array(const Array& copy) : m_size(0), m_array(NULL) { *this = copy; }
	~Array() {
		delete[] m_array;
	}

	Array& operator=(const Array& rhs) {
		if (m_array) { delete[] m_array; }

		m_size = rhs.m_size;
		m_array = NULL;

		if (m_size == 0) { return *this; }
		m_array = new T[m_size];
		for (unsigned int i = 0; i < m_size; i++) {
			m_array[i] = rhs.m_array[i];
		}
		return *this;
	}

	T& operator[](unsigned int idx) {
		if (idx < 0 || idx >= m_size) { throw std::out_of_range("out of range"); }
		return m_array[idx];
	}

	T& operator[](unsigned int idx) const {
		if (idx < 0 || idx >= m_size) { throw std::out_of_range("out of range"); }
		return m_array[idx];
	}

	unsigned int size(void) const {
		return m_size;
	}

private:
	unsigned int m_size;
	T* m_array;
};

#endif
