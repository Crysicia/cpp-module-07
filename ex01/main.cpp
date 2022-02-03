#include "iter.hpp"
#include <iostream>

#define LENGTH 10

void ft_putchar(char& c) {
	std::cout << c << std::endl;
}

void ft_putnbr(int& i) {
	std::cout << i << std::endl;
}

void ft_putnbr_const(const int& i) {
	std::cout << i << std::endl;
}

int main(void) {
	int int_array[LENGTH] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	const int int_array_const[LENGTH] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	char char_array[LENGTH] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

	std::cout << "---- Call iter on int array ----" << std::endl;
	iter(int_array, LENGTH, ft_putnbr);

	std::cout << "---- Call iter on const int array ----" << std::endl;
	iter(int_array_const, LENGTH, ft_putnbr_const);

	std::cout << "---- Call iter on const int array ----" << std::endl;
	iter(int_array, LENGTH, ft_putnbr_const);

	std::cout << std::endl << "---- Call iter on char array ----" << std::endl;
	iter(char_array, LENGTH, ft_putchar);

	return 0;
}
