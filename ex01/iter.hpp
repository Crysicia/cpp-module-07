#ifndef ITER_HPP
# define ITER_HPP

template<typename A, typename L>
void iter(A* array, const L& length, void (*f)(A&)) {
	for (L i = 0; i < length; i++) {
		f(array[i]);
	}
}

#endif
