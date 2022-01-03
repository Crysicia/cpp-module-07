#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 10

void print_values(Array<std::string>& array) {
    std::cout << "[";
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i];
        if (i < array.size() - 1) { std::cout << ", "; }
    }
    std::cout << "]" << std::endl;
}

void print_values(Array<int>& array) {
    std::cout << "[";
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << array[i];
        if (i < array.size() - 1) { std::cout << ", "; }
    }
    std::cout << "]" << std::endl;
}

void print_values(int* array) {
    std::cout << "[";
    for (int i = 0; i < MAX_VAL; i++) {
        std::cout << array[i];
        if (i < MAX_VAL - 1) { std::cout << ", "; }
    }
    std::cout << "]" << std::endl;
}

int main(void)
{
    std::srand(std::time(NULL));

    std::cout << "---- Initialize Arrays and control array ----" << std::endl;

    Array<int>* empty = new Array<int>;
    Array<int> numbers(MAX_VAL);
    Array<std::string> strings(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    std::cout << "---- Fill Arrays and control array ----" << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = std::rand() % 25;
        numbers[i] = value;
        mirror[i] = value;
    }

    strings[0] = "Somebody";
    strings[1] = "once";
    strings[2] = "told";
    strings[3] = "me";
    strings[4] = "the";
    strings[5] = "world";
    strings[6] = "is";
    strings[7] = "gonna";
    strings[8] = "roll";
    strings[9] = "me.";

    std::cout << "---- Print values from strings ----" << std::endl;
    print_values(strings);

    std::cout << std::endl << "---- Print values from numbers ----" << std::endl;
    print_values(numbers);

    std::cout << std::endl << "---- Print values from mirror ----" << std::endl;
    print_values(mirror);
    
    std::cout << std::endl << "---- Print values from empty array ----" << std::endl;
    print_values(*empty);

    std::cout << std::endl << "---- Test copy constructor and assignation ----" << std::endl;
    {
        Array<int> tmp = numbers;
        print_values(tmp);

        Array<int> test(tmp);
        print_values(test);
    }

    std::cout << std::endl << "---- Check if the array was modified ----" << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout << std::endl << "---- Check invalid indexes ----" << std::endl;
    try { numbers[-2] = 0; }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

    try { numbers[MAX_VAL] = 0; }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    
    delete empty;
    delete[] mirror;
    return 0;
}
