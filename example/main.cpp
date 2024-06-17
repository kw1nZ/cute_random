#include <iostream>
#include <vector>
#include "cute_random/cute_random.h"


int main() {
    CuteRandom cute_random;

    // Generate a random integer in the range [0, 100]
    int random_int = cute_random();
    std::cout << "Random integer: " << random_int << std::endl;

    // Generate a random integer in the range [0, max]
    int max_int = 50;
    int random_int_max = cute_random(max_int);
    std::cout << "Random integer up to " << max_int << ": " << random_int_max << std::endl;

    // Generate a random double in the range [0, 1]
    double random_double = cute_random.in_range_real(0.0, 1.0);
    std::cout << "Random double: " << random_double << std::endl;

    // Generate a vector of random integers
    std::vector<int> random_int_vec(5);
    cute_random.random_fill(random_int_vec, 0, 10);
    std::cout << "Random integer vector: ";
    for (int x : random_int_vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Generate a vector of random doubles
    std::vector<double> random_double_vec(3);
    cute_random.random_fill_real(random_double_vec, 0.0, 1.0);
    std::cout << "Random double vector: ";
    for (double x : random_double_vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Get a random element from a vector
    std::vector<std::string> str_vec = {"apple", "banana", "cherry", "durian", "elderberry"};
    std::string random_str = cute_random.random_element(str_vec);
    std::cout << "Random string: " << random_str << std::endl;

    // Shuffle a vector
    std::vector<int> shuffle_vec = {1, 2, 3, 4, 5};
    cute_random.shuffle(shuffle_vec);
    std::cout << "Shuffled vector: ";
    for (int x : shuffle_vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    constexpr int ARR_SZ = 5;
    // Shuffle a plain dynamic int array
    int* plain_int_arr = new int[ARR_SZ]{1, 2, 3, 4, 5};
    cute_random.shuffle(plain_int_arr, ARR_SZ);
    std::cout << "Shuffled plain dynamic int array: ";
    for (int i = 0; i < ARR_SZ; i++) std::cout << plain_int_arr[i] << " ";
    std::cout << std::endl;
    delete[] plain_int_arr;

    // Shuffle a plain dynamic std::string array
    auto* plain_str_arr = new std::string[ARR_SZ]{"apple", "banana", "cherry", "durian", "elderberry"};
    cute_random.shuffle(plain_str_arr, ARR_SZ);
    std::cout << "Shuffled plain dynamic string array: ";
    for (int i = 0; i < ARR_SZ; i++) std::cout << plain_str_arr[i] << " ";
    std::cout << std::endl;
    delete[] plain_str_arr;

    // Shuffle a plain str array
    std::string plain_str_arr_static[ARR_SZ] = {"apple", "banana", "cherry", "durian", "elderberry"};
    cute_random.shuffle(plain_str_arr_static);
    std::cout << "Shuffled plain static string array: ";
    for (auto& i : plain_str_arr_static) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
