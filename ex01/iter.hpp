#ifndef ITER_HPP
# define ITER_HPP

template<typename A, typename size_t>
void iter(A* array, const size_t& length, void (*f)(A&)) {
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

template<typename A, typename size_t>
void iter(A* array, const size_t& length, void (*f)(const A&)) {
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

#endif
