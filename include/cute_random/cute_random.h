#pragma once

#include <random>
#include <algorithm>
#include <chrono>

class CuteRandom {
public:
    explicit CuteRandom(const unsigned int seed = gen_seed()) : m_generator(seed) {}

    static inline unsigned int gen_seed() {
        return static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()) ^ static_cast<unsigned>(std::random_device()());
    }

    void seed(const unsigned int seed = gen_seed()) {
        m_generator.seed(seed);
    }

    inline int operator()() {
        return in_range(0, 100);
    }

    inline int operator()(const int max) {
        return in_range(0, max);
    }

    template<typename T = int>
    T in_range(const T min, const T max) {
        std::uniform_int_distribution<T> distribution(min, max);
        return distribution(m_generator);
    }

    template<typename T = double>
    T in_range_real(const T min, const T max) {
        std::uniform_real_distribution<T> distribution(min, max);
        return distribution(m_generator);

    }

    template<typename T = int>
    void random_fill(std::vector<T>& vec, const T min, const T max) {
        for (T& x : vec) {
            x = in_range<T>(min, max);
        }
    }

    template<typename T = double>
    void random_fill_real(std::vector<T>& vec, const T min, const T max) {
        for (T& x : vec) {
            x = in_range_real<T>(min, max);
        }
    }

    template<typename T = int>
    void random_fill(T* arr, size_t sz, const T min, const T max) {
        for (size_t i = 0; i < sz; ++i) {
            arr[i] = in_range<T>(min, max);
        }
    }

    template<typename T = double>
    void random_fill_real(T* arr, size_t sz, const T min, const T max) {
        for (size_t i = 0; i < sz; ++i) {
            arr[i] = in_range_real<T>(min, max);
        }
    }

    template <typename T>
    T random_element(const std::vector<T>& vec) {
        return vec[in_range<size_t>(0, vec.size() - 1)];
    }

    template <typename T>
    void shuffle(std::vector<T>& vec) {
        std::shuffle(vec.begin(), vec.end(), m_generator);
    }

    template <typename T, std::size_t N>
    void shuffle(T (&arr)[N]) {
        std::shuffle(std::begin(arr), std::end(arr), m_generator);
    }

    template <typename T>
    void shuffle(T* arr, const std::size_t sz) {
        std::shuffle(arr, arr + sz, m_generator);
    }

private:
    std::mt19937 m_generator;
};
